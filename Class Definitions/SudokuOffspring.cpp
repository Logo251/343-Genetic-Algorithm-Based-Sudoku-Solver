
#include "../Headers/SudokuOffspring.h"

Reproduction& SudokuOffspring::makeOffspring(Puzzle& input) {
   //Create random
   srand(time(NULL));

   for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
         if (input.sudoku[i][j]) >= 0) {
         if (rand() % 100 + 1 <= PERCENTAGE_CHANCE_OF_MUTATION) { //Rolls a number between 1 and 100.
            input.sudoku[i][j] = rand() % 9 + 1; //This generates a number between 1 and 9.
         }
            }
      }
   }
   return newObject;
}
