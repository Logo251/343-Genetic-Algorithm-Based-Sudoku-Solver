
#pragma once

#include "Puzzle.h"

class Fitness {
public:
      virtual int howFit(Puzzle inputPuzzle) = 0;
};