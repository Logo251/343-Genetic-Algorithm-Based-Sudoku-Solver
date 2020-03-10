
#include "..\Headers\SudokuFactory.h"

Puzzle& SudokuFactory::createPuzzle(Puzzle& referencePuzzle) {
   return reproductionObject.makeOffspring(referencePuzzle);
}
