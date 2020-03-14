/*
File Name:  Sudoku.h
Author:     Logan Petersen
Date:       March 13, 2020
Purpose:    This is the header file for the Sudoku class containing Sudoku's interface.
            The purpose of this code is to provide the function prototypes for Sudoku,
            define some defaults for variables, and declare the relationship to Puzzle.
*/

#pragma once

#include <sstream> //Used for string stream.
#include "../Interfaces/Puzzle.h"

class Sudoku : public Puzzle {
public:
   /*
   Purpose:          Construct Sudoku when Sudoku is created without arguments.
   Parameters:       None.
   Preconditions:    This specific Sudoku object has not been instantiated.
   Postconditions:   Sudoku object is instantiated with default values in its variables.
   Return value:     None.
   Functions Called: None.
   */
   Sudoku();

   /*
   Purpose:          Construct Sudoku when Sudoku is created with an argument.
   Parameters:       inputSudoku, an array of integers that represesents a raw sudoku.
                     Used for creating a Sudoku with these values for its sudoku.
   Preconditions:    This specific Sudoku object has not been instantiated.
   Postconditions:   Sudoku object is instantiated with the given argument and default values otherwise.
   Return value:     None.
   Functions Called: inputPuzzle, used to input the sudoku puzzle into Sudoku correctly.
   */
   Sudoku(int inputSudoku[81]);

   /*
   Purpose:          Be the copy constructor for Sudoku.
   Parameters:       inputSudoku, another Sudoku object.
                     Used in the copy constructor to copy.
   Preconditions:    This specific Sudoku object does not have inputSudoku's values.
   Postconditions:   This specific Sudoku object has inputSudoku's values.
   Return value:     None.
   Functions Called: Technically operator=, used to assign.
   */
   Sudoku(const Sudoku& inputSudoku);

   /*
   Purpose:          Be the assignment operator for Sudoku.
   Parameters:       inputSudoku, another Sudoku object.
                     Used as the reference that assigns this object.
   Preconditions:    This specific Sudoku object does not have inputSudoku's values.
   Postconditions:   This specific Sudoku object has inputSudoku's values.
   Return value:     None.
   Functions Called: None.
   */
   Sudoku& operator=(const Sudoku& inputSudoku);

   /*
   Purpose:          Input into Sudoku according to specifications.
   Parameters:       input, the istream that is the stream of integer characters being sent to the terminal.
                     puzzle, the puzzle that is going to be inputted into according to specifications.
   Preconditions:    Sudoku has been instantiated.
   Postconditions:   Sudoku now has a puzzle based on the input according to specifications.
   Return value:     istream, an istream to allow statements to be chained according to operator>>'s specification.
   Functions Called: inputPuzzle, a helper function due to having an interface.
   */
   friend std::istream& operator>>(std::istream& input, const Puzzle& puzzle);

   /*
   Purpose:          Output the Sudoku according to specifications.
   Parameters:       out, the ostream that is the stream of characters being sent to the terminal.
                     puzzle, the Puzzle that is going to be printed according to specifications.
   Preconditions:    Sudoku has been instantiated.
   Postconditions:   Output the sudoku inside according to specifications, mainly in human-readable format.
   Return value:     out, an ostream to allow statements to be chained according to operator<<'s specification.
   Functions Called: toString, a helper function due to having an interface.
   */
   friend std::ostream& operator<<(std::ostream& out, const Puzzle& puzzle);

   /*
   Purpose:          Give a string to be printed by ostream.
   Parameters:       None.
   Preconditions:    This Sudoku object has been instantiated and operator<< is called.
   Postconditions:   A string is displayed through operator<<.
   Return value:     string, used to give a string to be displayed.
   Functions Called: None.
   */
   const std::string toString() const;

   /*
   Purpose:          Be a helper function for inputting characters into Sudoku's sudoku.
   Parameters:       input, the istream.
                     Used to input characters.
   Preconditions:    This Sudoku object has been instantiated and operator>> is called.
   Postconditions:   This specific Sudoku object has input's given values.
   Return value:     None.
   Functions Called: None.
   */
   const std::istream& inputPuzzle(std::istream& input);

   short int sudoku[9][9] = { { 0 }, { 0 }}; //This object's puzzle.
   int fitness = 1874919423; //This object's fitness, defaults to what should be the max of int.
};
