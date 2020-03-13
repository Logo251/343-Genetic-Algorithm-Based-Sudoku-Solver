
#include "..\Headers\SudokuFitness.h"

int SudokuFitness::howFit(const Puzzle& inputPuzzle) {
   //Local Variables
   Sudoku newSudoku = dynamic_cast<const Sudoku&>(inputPuzzle);

   return evaluateRows(newSudoku) + evaluateQuadrants(newSudoku); //evaluateColumns(newSudoku)
}

int SudokuFitness::evaluateRows(Sudoku sudoku) {
   //Local Variables
   int errorCount = 0; //Number of errors found relating to the rows. Can be any non-negative number.
   //std::vector<int> seenNumbers; //Used to make sure we do not have duplicates in each row.
   int ComparisonNumber; //Used to ensure we compare the actual values of each number, not the negative parts.

   for (int i = 0; i < 9; i++) {
      //Should be better than a for loop to reset every row.
      bool foundNumbers[9] = { false };

      for (int j = 0; j < 9; j++) {
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

int SudokuFitness::evaluateColumns(Sudoku sudoku) {
   //Local Variables
   int errorCount = 0; //Number of errors found relating to the rows. Can be any non-negative number.
   std::vector<int> seenNumbers; //Used to make sure we do not have duplicates in each row.
   int ComparisonNumber; //Used to ensure we compare the actual values of each number, not the negative parts.

   for (int i = 0; i < 9; i++) {
      //Should be better than a for loop to reset every row.
      bool foundNumbers[9] = { false };

      for (int j = 0; j < 9; j++) {
         ComparisonNumber = abs(sudoku.sudoku[j][i]);

         //If the spot is blank, it IS wrong.
         if (ComparisonNumber == 0) {
            errorCount++;
         }
         else {
            if (foundNumbers[ComparisonNumber - 1] == true) {
               errorCount++;
            }
            else {
               foundNumbers[ComparisonNumber - 1] = false;
            }
         }
      }
   }

   return errorCount;
}

int SudokuFitness::evaluateQuadrants(Sudoku sudoku) {
   int errorCount = 0; //Number of errors found relating to the rows. Can be any non-negative number.
   std::vector<int> seenNumbers; //Used to make sure we do not have duplicates in each row.
   int ComparisonNumber; //Used to ensure we compare the actual values of each number, not the negative parts.

   //The if nightmare, but reads each quadrant.
   for (int i = 0; i < 9; i += 3) {
      for (int j = 0; j < 9; j += 3) {
         //Should be better than a for loop to reset every row.
         bool foundNumbers[9] = { false };

         for (int k = 0; k < 3; k++) {
            for (int l = 0; l < 3; l++) {
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
