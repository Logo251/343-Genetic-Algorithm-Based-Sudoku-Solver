
#pragma once

#include "Sudoku.h"
#include "../Interfaces/Fitness.h"

class SudokuFitness : Fitness {
public:
   static int howFit(Puzzle inputPuzzle);
private:
  static int evaluateRows(Sudoku sudoku);
  static int evaluateColumns(Sudoku sudoku);
  static int evaluateQuadrants(Sudoku sudoku);
};