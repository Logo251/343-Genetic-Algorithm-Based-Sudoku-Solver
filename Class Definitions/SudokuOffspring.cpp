/*
File Name:  SudokuOffspring.cpp
Author:     Logan Petersen
Date:       March 13, 2020
Purpose:    The purpose of this code is to be the function definitions for
            the function prototypes defined in SudokuOffspring.h. The code
            allows creation of SudokuOffspring and its use.
*/

#include "../Headers/SudokuOffspring.h"

/*
Purpose:          Construct SudokuOffspring when SudokuOffspring is created without arguments.
Parameters:       None.
Preconditions:    This specific SudokuOffspring object has not been instantiated.
Postconditions:   SudokuOffspring object has been instantiated with rand seeded.
Return value:     None.
Functions Called: None.
*/
SudokuOffspring::SudokuOffspring() {
   //Create random
   std::srand(std::time(0));
}

/*
Purpose:          Create a mutated clone of a given Sudoku.
Parameters:       input, the Sudoku that is cloned and mutated.
Preconditions:    This specific SudokuOffspring object has not been instantiated.
Postconditions:   A mutated clone of input is given back.
Return value:     Puzzle, a Sudoku that is a mutated clone of the given one.
Functions Called: None.
*/
Puzzle& SudokuOffspring::makeOffspring(Puzzle& input) const {
   //Local Variables
   int PERCENTAGE_CHANCE_OF_MUTATION = 5; //This is used to easily adjust the percentage chance of mutation.

   //input is a Sudoku, set it so.
   Sudoku input2 = dynamic_cast<Sudoku&>(input);

   //Create copy of input Sudoku
  static Sudoku newSudoku = input2; //This is done this way because I need to return a non-local variable and my program is not designed to use pointers, therefore leaving this option.

   for (int i = 0; i < 9; i++) {
      //It has not passed the end of the one of Sudoku's dimensions.

      for (int j = 0; j < 9; j++) {
         //It has not passed the end of the one of Sudoku's dimensions.
         //If it is 0, we can just choose a random number for it, since we know that 0 is always wrong.
         if (newSudoku.sudoku[j][i] == 0) {
            newSudoku.sudoku[j][i] = rand() % 9 + 1;
         }
         else if (newSudoku.sudoku[j][i] >= 0) {
            if (rand() % 100 + 1 <= PERCENTAGE_CHANCE_OF_MUTATION) { //Rolls a number between 1 and 100.
               newSudoku.sudoku[j][i] = rand() % 9 + 1; //This generates a number between 1 and 9.
            }
         }
      }
   }
   return newSudoku;
}
