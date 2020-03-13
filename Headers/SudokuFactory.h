
#pragma once

#include <sstream>
#include "../Interfaces/PuzzleFactory.h"
#include "../Headers/SudokuOffspring.h"

class SudokuFactory : public PuzzleFactory {
public:
   Puzzle& createPuzzle(Puzzle& referencePuzzle);
   Puzzle& createPuzzle(int inputArray[81]);

   SudokuOffspring reproductionObject;
};
