
#pragma once

#include <vector>
#include "../Interfaces/Fitness.h"
#include "../Headers/Sudoku.h"

class SudokuFitness : public Fitness {
public:
   static int howFit(const Puzzle& inputPuzzle);
private:
  static int evaluateRows(Sudoku sudoku);
  static int evaluateColumns(Sudoku sudoku);
  static int evaluateQuadrants(Sudoku sudoku);
};