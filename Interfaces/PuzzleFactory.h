
#pragma once

#include "Puzzle.h"

class PuzzleFactory {
public:
   virtual Puzzle& createPuzzle(Puzzle& referencePuzzle) = 0;
};