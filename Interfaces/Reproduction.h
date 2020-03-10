
#pragma once

#include "Puzzle.h"

class Reproduction {
public:
   virtual Puzzle& makeOffspring(Puzzle& input) = 0;
};