
#pragma once

#include "Puzzle.h"
#include "Reproduction.h"

class PuzzleFactory {
public:
   virtual Puzzle& createPuzzle() = 0;
};