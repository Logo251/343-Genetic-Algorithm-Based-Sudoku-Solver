
#include "../Headers/SudokuOffspring.h"
#include "../Headers/Sudoku.h"
#include <ctime>

Puzzle& SudokuOffspring::makeOffspring(Puzzle& input) {
   //Local Variables
   int PERCENTAGE_CHANCE_OF_MUTATION = 2; //This is used to easily adjust the percentage chance of mutation.

   //input is a Sudoku, set it so.
   Sudoku input2 = dynamic_cast<Sudoku&>(input);
   
   //Create random
   srand(time(NULL));

   //Create copy of input Sudoku
   Sudoku newSudoku;
   
   for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
         newSudoku.sudoku[i][j] = input2.sudoku[i][j];
      }
   }

   for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
         if (newSudoku.sudoku[i][j] >= 0) {
            if (rand() % 100 + 1 <= PERCENTAGE_CHANCE_OF_MUTATION) { //Rolls a number between 1 and 100.
               newSudoku.sudoku[i][j] = rand() % 9 + 1; //This generates a number between 1 and 9.
            }
         }
      }
   }
   return newSudoku;
}
