
#include "../Headers/SudokuFactory.h"

Puzzle& SudokuFactory::createPuzzle(Puzzle& referencePuzzle) {
   return reproductionObject.makeOffspring(referencePuzzle);
}

Puzzle& SudokuFactory::createPuzzle(int inputArray[]) {
   //Local Variables
   Sudoku newSudoku(inputArray);

   return createPuzzle(newSudoku);
}
