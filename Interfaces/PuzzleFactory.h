
#pragma once

#include "Puzzle.h"
#include "Reproduction.h"

class PuzzleFactory {
public:
   virtual Puzzle& createPuzzle(Puzzle& referencePuzzle) = 0;
   virtual Puzzle& createPuzzle(int inputArray[81]) = 0;
};