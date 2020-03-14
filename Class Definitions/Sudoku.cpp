/*
File Name:  Sudoku.cpp
Author:     Logan Petersen
Date:       March 13, 2020
Purpose:    The purpose of this code is to be the function definitions for
            the function prototypes defined in Sudoku.h. The code allows creation
            of Sudoku and its use.
*/

#include "../Headers/Sudoku.h"

/*
Purpose:          Construct Sudoku when Sudoku is created without arguments.
Parameters:       None.
Preconditions:    This specific Sudoku object has not been instantiated.
Postconditions:   Sudoku object is instantiated with default values in its variables.
Return value:     None.
Functions Called: None.
*/
Sudoku::Sudoku() {
   fitness = 0;
}

/*
Purpose:          Construct Sudoku when Sudoku is created with an argument.
Parameters:       inputSudoku, an array of integers that represesents a raw sudoku.
                  Used for creating a Sudoku with these values for its sudoku.
Preconditions:    This specific Sudoku object has not been instantiated.
Postconditions:   Sudoku object is instantiated with the given argument and default values otherwise.
Return value:     None.
Functions Called: inputPuzzle, used to input the sudoku puzzle into Sudoku correctly.
*/
Sudoku::Sudoku(int inputSudoku[81]) {
   //Local Variables
   std::string inputInString;

   fitness = 0;

   //Convert inputArray to string.
   for (int i = 0; i < 81; i++) {
      //More characters exist that belong in Sudoku eventually.
      inputInString += std::to_string(inputSudoku[i]);
   }
   std::istringstream stringStream(inputInString);

   this->inputPuzzle(stringStream);
}

/*
Purpose:          Be the copy constructor for Sudoku.
Parameters:       inputSudoku, another Sudoku object.
                  Used in the copy constructor to copy.
Preconditions:    This specific Sudoku object does not have inputSudoku's values.
Postconditions:   This specific Sudoku object has inputSudoku's values.
Return value:     None.
Functions Called: Technically operator=, used to assign.
*/
Sudoku::Sudoku(const Sudoku& inputSudoku) {
   *this = inputSudoku;
}

/*
Purpose:          Be the assignment operator for Sudoku.
Parameters:       inputSudoku, another Sudoku object.
                  Used as the reference that assigns this object.
Preconditions:    This specific Sudoku object does not have inputSudoku's values.
Postconditions:   This specific Sudoku object has inputSudoku's values.
Return value:     None.
Functions Called: None.
*/
Sudoku& Sudoku::operator=(const Sudoku& inputSudoku) {

   if (this == &inputSudoku) {
      return *this;
   }
   this->fitness = inputSudoku.fitness;

   //Copy array.
   for(int i = 0; i < 9; i++) {
      //We have not left the bounds of one of sudoku's dimensions.
      for(int j = 0; j < 9; j++) {
         //We have not left the bounds of one of sudoku's dimensions.
         this->sudoku[j][i] = inputSudoku.sudoku[j][i];
      }
   }
   return *this;
}

/*
Purpose:          Input into Sudoku according to specifications.
Parameters:       input, the istream that is the stream of integer characters being sent to the terminal.
                  puzzle, the puzzle that is going to be inputted into according to specifications.
Preconditions:    Sudoku has been instantiated.
Postconditions:   Sudoku now has a puzzle based on the input according to specifications.
Return value:     istream, an istream to allow statements to be chained according to operator>>'s specification.
Functions Called: inputPuzzle, a helper function due to having an interface.
*/
std::istream& operator>>(std::istream& input, Puzzle& puzzle) {
   puzzle.inputPuzzle(input);
   return input;
}

/*
Purpose:          Output the Sudoku according to specifications.
Parameters:       out, the ostream that is the stream of characters being sent to the terminal.
                  puzzle, the Puzzle that is going to be printed according to specifications.
Preconditions:    Sudoku has been instantiated.
Postconditions:   Output the sudoku inside according to specifications, mainly in human-readable format.
Return value:     out, an ostream to allow statements to be chained according to operator<<'s specification.
Functions Called: toString, a helper function due to having an interface.
*/
std::ostream& operator<<(std::ostream& out, const Puzzle& puzzle) {
   out << puzzle.toString();
   return out;
}

/*
Purpose:          Give a string to be printed by ostream.
Parameters:       None.
Preconditions:    This Sudoku object has been instantiated and operator<< is called.
Postconditions:   A string is displayed through operator<<.
Return value:     string, used to give a string to be displayed.
Functions Called: None.
*/
const std::string Sudoku::toString() const {
   //Local Variables
   int progressThroughX = 0; //Progress through the x axis of the sudoku puzzle being printed.
   int progressThroughY = 0; //Progress through the y axis of the sudoku puzzle being printed.
   std::string out;

   for (int i = 0; i < 13; i++) {
      //We have not left the bounds of the sudoku's fancy output Y dimension.
      for (int j = 0; j < 19; j++) {
         // We have not left the bounds of the sudoku's fancy output X dimension.
         //Handles the '+' and '-'.
         if (i == 0 || i == 4 || i == 8 || i == 12) {
            if (j == 0 || j == 6 || j == 12 || j == 18) {
               out += '+';
            }
            else {
               out += '-';
            }
         }

         //Handles the | down the table.
         else if (i != 0 && j == 0 || i != 19 && j == 18 || j == 6 || j == 12) {
            out += '|';
         }


         //Handles the spaces.
         else if (j % 2 == 0) {
            out += ' ';
         }

         //Handles the actual numbers.
         else {

            //This converts the negatives used to determine number that cannot be changed to normal for the human reading it.
            if (sudoku[progressThroughX][progressThroughY] < 0) {
               out += std::to_string(sudoku[progressThroughX][progressThroughY] * -1);
            }
            else {
               out += std::to_string(sudoku[progressThroughX][progressThroughY]);
            }

            //Increment counters.
            if (progressThroughX == 8) {
               progressThroughX = 0;
               progressThroughY++;
            }
            else {
               progressThroughX++;
            }
         }
      }
      out += '\n';
   }

   return out;
}

/*
Purpose:          Be a helper function for inputting characters into Sudoku's sudoku.
Parameters:       input, the istream.
                  Used to input characters.
Preconditions:    This Sudoku object has been instantiated and operator>> is called.
Postconditions:   This specific Sudoku object has input's given values.
Return value:     None.
Functions Called: None.
*/
const std::istream& Sudoku::inputPuzzle(std::istream& input) {
   //Local Variables
   int progressThroughX = 0; //Progress through the x axis of the sudoku puzzle.
   int progressThroughY = 0; //Progress through the y axis of the sudoku puzzle.
   char inputChar;
   int addToSudoku; //Used to add to Sudoku.

   while (input.get(inputChar)) {
      //More characters exist in the input.

      if (isdigit(inputChar)) {
         addToSudoku = (int)inputChar - 48;
         if (addToSudoku > 0) {
            addToSudoku *= -1; //A negative number indicates it cannot be changed.
         }
         sudoku[progressThroughX][progressThroughY] = addToSudoku; //48 converts ascii numbers to integer.
            if (progressThroughX == 8) {
               progressThroughX = 0;
               progressThroughY++;
            }
            else {
               progressThroughX++;
            }
      }
   }

   return input;
}
