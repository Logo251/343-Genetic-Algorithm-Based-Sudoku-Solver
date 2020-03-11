
#pragma once

#include <ctime>
#include "../Interfaces/Reproduction.h"
#include "../Headers/Sudoku.h"

class SudokuOffspring : public Reproduction {
public:
   Puzzle& makeOffspring(Puzzle& input) const;
};