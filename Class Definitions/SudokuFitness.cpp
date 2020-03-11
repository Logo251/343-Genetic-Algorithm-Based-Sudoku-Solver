
#include "..\Headers\SudokuFitness.h"

int SudokuFitness::howFit(const Puzzle& inputPuzzle) {
   //Local Variables
   Sudoku newSudoku = dynamic_cast<const Sudoku&>(inputPuzzle);

   return evaluateRows(newSudoku) + evaluateColumns(newSudoku) + evaluateQuadrants(newSudoku);
}

int SudokuFitness::evaluateRows(Sudoku sudoku) {
   //Local Variables
   int errorCount = 0; //Number of errors found relating to the rows. Can be any non-negative number.
   std::vector<int> seenNumbers; //Used to make sure we do not have duplicates in each row.

   for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
         if (std::find(seenNumbers.begin(), seenNumbers.end(), sudoku.sudoku[i][j]) != seenNumbers.end()) {
            errorCount++;
         }
         else {
            seenNumbers.push_back(sudoku.sudoku[i][j]);
         }
      }
      seenNumbers.clear();
   }

   return errorCount;
}

int SudokuFitness::evaluateColumns(Sudoku sudoku) {
   //Local Variables
   int errorCount = 0; //Number of errors found relating to the rows. Can be any non-negative number.
   std::vector<int> seenNumbers; //Used to make sure we do not have duplicates in each row.

   for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
         if (std::find(seenNumbers.begin(), seenNumbers.end(), sudoku.sudoku[j][i]) != seenNumbers.end()) {
            errorCount++;
         }
         else {
            seenNumbers.push_back(sudoku.sudoku[j][i]);
         }
      }
      seenNumbers.clear();
   }

   return errorCount;
}

int SudokuFitness::evaluateQuadrants(Sudoku sudoku) {
   int errorCount = 0; //Number of errors found relating to the rows. Can be any non-negative number.
   std::vector<int> seenNumbers; //Used to make sure we do not have duplicates in each row.

   //The if nightmare, but reads each quadrant.
   for (int i = 0; i < 9; i+=3) {
      for (int j = 0; j < 9; j+=3) {
         seenNumbers.clear();
         for (int k = 0; k < 9; i++) {
            for (int l = 0; l < 3; l++) {
               if (std::find(seenNumbers.begin(), seenNumbers.end(), sudoku.sudoku[j][i]) != seenNumbers.end()) {
                  errorCount++;
               }
               else {
                  seenNumbers.push_back(sudoku.sudoku[j][i]);
               }
            }
         }
      }
   }

   return errorCount;
}
