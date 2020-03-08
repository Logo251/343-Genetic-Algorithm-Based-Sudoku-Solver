
#pragma once

#include "Puzzle.h"

class Reproduction {
public:
   virtual Reproduction* makeOffspring(Puzzle input) = 0;
};