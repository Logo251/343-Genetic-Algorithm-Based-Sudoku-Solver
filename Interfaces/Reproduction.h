
#pragma once

#include "Puzzle.h"

class Reproduction {
public:
   virtual Puzzle& makeOffspring(Puzzle& input) const = 0;
   //TODO: add copy constructor for puzzle
};