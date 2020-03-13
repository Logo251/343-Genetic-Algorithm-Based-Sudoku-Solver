
#include "../Headers/Sudoku.h"

std::istream& operator>>(std::istream& input, Puzzle& puzzle) {
   puzzle.inputPuzzle(input);
   return input;
}

std::ostream& operator<<(std::ostream& out, const Puzzle& puzzle) {
   out << puzzle.toString();
   return out;
}

Sudoku::Sudoku(int inputSudoku[81]) {
   std::string inputInString;

   //Convert inputArray to string
   for (int i = 0; i < 81; i++) {
      inputInString += std::to_string(inputSudoku[i]);
   }
   std::istringstream stringStream(inputInString);

   this->inputPuzzle(stringStream);
}

std::string Sudoku::toString() const {
   //Local Variables
   int progressThroughX = 0; //Progress through the x axis of the sudoku puzzle being printed.
   int progressThroughY = 0; //Progress through the y axis of the sudoku puzzle being printed.
   std::string out;

   for (int i = 0; i < 13; i++) {
      for (int j = 0; j < 19; j++) {
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

std::istream& Sudoku::inputPuzzle(std::istream& input) {
   //Local Variables
   int progressThroughX = 0; //Progress through the x axis of the sudoku puzzle.
   int progressThroughY = 0; //Progress through the y axis of the sudoku puzzle.
   char inputChar;
   int addToSudoku; //Used to add to Sudoku.

   while (input.get(inputChar)) {
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
