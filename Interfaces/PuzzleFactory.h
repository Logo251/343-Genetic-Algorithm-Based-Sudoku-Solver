
#pragma once

#include "Puzzle.h"
#include "Reproduction.h"

class PuzzleFactory {
public:
   virtual Puzzle createPuzzle(Reproduction referencePuzzle) = 0;
};