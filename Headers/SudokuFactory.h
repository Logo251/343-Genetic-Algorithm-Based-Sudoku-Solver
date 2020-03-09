
#include "../Interfaces/PuzzleFactory.h"
#include "Sudoku.h"

class SudokuFactory : public PuzzleFactory {
public:
   Puzzle& createPuzzle();
};
