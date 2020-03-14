/*
File Name:  SudokuFitness.cpp
Author:     Logan Petersen
Date:       March 13, 2020
Purpose:    The purpose of this code is to be the function definitions for
            the function prototypes defined in SudokuFitness.h. The code
            allows creation of SudokuFitness and its use.
*/

#include "../Headers/SudokuFitness.h"

/*
Purpose:          Return the fitness of a Sudoku.
Parameters:       inputPuzzle, the sudoku that is evaluated.
Preconditions:    This specific SudokuFitness object has not been instantiated.
Postconditions:   The fitness of the Sudoku is returned with nothing changed.
Return value:     integer, the fitness of the Sudoku.
Functions Called: evaluateRows, evaluateColumns, evaluateQuadrants, used to better
                  evaluate seperate parts of the Sudoku.
*/
const int SudokuFitness::howFit(const Puzzle& inputPuzzle) const {
   //Local Variables
   Sudoku newSudoku = dynamic_cast<const Sudoku&>(inputPuzzle);

   return (evaluateRows(newSudoku) + evaluateColumns(newSudoku) + evaluateQuadrants(newSudoku));
}

/*
Purpose:          Return the number of issues in the rows of the sudoku.
Parameters:       sudoku, the sudoku that is evaluated.
Preconditions:    This specific SudokuFitness object has not been instantiated.
Postconditions:   The fitness of the Sudoku's rows is returned with nothing changed.
Return value:     integer, the fitness of the Sudoku's rows.
Functions Called: None.
*/
const int SudokuFitness::evaluateRows(const Sudoku& sudoku) const {
   //Local Variables
   //OVERALL: shorts are used because its faster and the size is not needed.
   short int errorCount = 0; //Number of errors found relating to the rows. Can be any non-negative number.
   short int ComparisonNumber; //Used to ensure we compare the actual values of each number, not the negative parts.

   for (short int i = 0; i < 9; i++) {
      //It has not passed the end of the one of Sudoku's dimensions.
      //Should be better than a for loop to reset every row.
      bool foundNumbers[9] = { false };

      for (short int j = 0; j < 9; j++) {
         //It has not passed the end of the one of Sudoku's dimensions.
         ComparisonNumber = abs(sudoku.sudoku[j][i]);

         //If the spot is blank, it IS wrong.
         if (ComparisonNumber == 0) {
            errorCount++;
         }
         else {
            if(foundNumbers[ComparisonNumber - 1] == true) {
               errorCount++;
            }
            else {
               foundNumbers[ComparisonNumber - 1] = true;
            }
         }
      }
   }

   return errorCount;
}

/*
Purpose:          Return the number of issues in the columns of the sudoku.
Parameters:       sudoku, the sudoku that is evaluated.
Preconditions:    This specific SudokuFitness object has not been instantiated.
Postconditions:   The fitness of the Sudoku's columns is returned with nothing changed.
Return value:     integer, the fitness of the Sudoku's columns..
Functions Called: None.
*/
const int SudokuFitness::evaluateColumns(const Sudoku& sudoku) const {
   //Local Variables
   short int errorCount = 0; //Number of errors found relating to the column. Can be any non-negative number.
   short int ComparisonNumber; //Used to ensure we compare the actual values of each number, not the negative parts.

   for (short int i = 0; i < 9; i++) {
      //It has not passed the end of the one of Sudoku's dimensions.
      //Should be better than a for loop to reset every row.
      bool foundNumbers[9] = { false };

      for (short int j = 0; j < 9; j++) {
         //It has not passed the end of the one of Sudoku's dimensions.

         ComparisonNumber = abs(sudoku.sudoku[i][j]);

         //If the spot is blank, it IS wrong.
         if (ComparisonNumber == 0) {
            errorCount++;
         }
         else {
            if (foundNumbers[ComparisonNumber - 1] == true) {
               errorCount++;
            }
            else {
               foundNumbers[ComparisonNumber - 1] = true;
            }
         }
      }
   }

   return errorCount;
}

/*
Purpose:          Return the number of issues in the quadrants of the sudoku.
Parameters:       sudoku, the sudoku that is evaluated.
Preconditions:    This specific SudokuFitness object has not been instantiated.
Postconditions:   The fitness of the Sudoku's quadrants is returned with nothing changed.
Return value:     integer, the fitness of the Sudoku's quadrants.
Functions Called: None.
*/
const int SudokuFitness::evaluateQuadrants(const Sudoku& sudoku) const {
   short int errorCount = 0; //Number of errors found relating to the block. Can be any non-negative number.
   short int ComparisonNumber; //Used to ensure we compare the actual values of each number, not the negative parts.

   //The if nightmare, but reads each quadrant.
   for (short int i = 0; i < 9; i += 3) {
      //We have not left Sudoku in terms of quadrants top-left value.
      for (short int j = 0; j < 9; j += 3) {
         //We have not left Sudoku in terms of quadrants top - left value.
         //Should be better than a for loop to reset every row.
         bool foundNumbers[9] = { false };

         for (short int k = 0; k < 3; k++) {
            //We are inside the bounds of this quadrant.
            for (short int l = 0; l < 3; l++) {
               //We are inside the bounds of this quadrant.
               ComparisonNumber = abs(sudoku.sudoku[k + i][j + l]);

               //If the spot is blank, it IS wrong.
               if (ComparisonNumber == 0) {
                  errorCount++;
               }
               else {
                  if (foundNumbers[ComparisonNumber - 1] == true) {
                     errorCount++;
                  }
                  else {
                     foundNumbers[ComparisonNumber - 1] = true;
                  }
               }
            }
         }
      }
   }

   return errorCount;
}
