
#include "../Headers/SudokuOffspring.h"

SudokuOffspring::SudokuOffspring() {
   //Create random
   std::srand(time(NULL));
}

Puzzle& SudokuOffspring::makeOffspring(Puzzle& input) const {
   //Local Variables
   int PERCENTAGE_CHANCE_OF_MUTATION = 4; //This is used to easily adjust the percentage chance of mutation.

   //input is a Sudoku, set it so.
   Sudoku input2 = dynamic_cast<Sudoku&>(input);

   //Create copy of input Sudoku
   Sudoku newSudoku = input2;

   for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
         if (newSudoku.sudoku[j][i] >= 0) {
            if (rand() % 100 + 1 <= PERCENTAGE_CHANCE_OF_MUTATION) { //Rolls a number between 1 and 100.
               newSudoku.sudoku[j][i] = rand() % 9 + 1; //This generates a number between 1 and 9.
            }
         }
      }
   }
   return newSudoku;
}
