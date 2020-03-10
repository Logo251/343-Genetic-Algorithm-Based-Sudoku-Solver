
#include "../Interfaces/PuzzleFactory.h"
#include "SudokuOffspring.h"
#include "Sudoku.h"

class SudokuFactory : public PuzzleFactory {
public:
   Puzzle& createPuzzle(Puzzle& referencePuzzle);
   Puzzle& createPuzzle(int inputArray[81]);

   SudokuOffspring reproductionObject;
};
