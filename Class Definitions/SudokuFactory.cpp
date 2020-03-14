
#include "../Headers/SudokuFactory.h"

Puzzle& SudokuFactory::createPuzzle(Puzzle& referencePuzzle) {
   return reproductionObject.makeOffspring(referencePuzzle);
}

Puzzle& SudokuFactory::createPuzzle(int inputArray[81]) {
   //Local Variables
   //This is done because newSudoku cannot be returned.
   Sudoku newSudoku(inputArray);
   initialSudoku = newSudoku;

   return createPuzzle(initialSudoku);
}
