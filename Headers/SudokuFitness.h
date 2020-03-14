
#pragma once

#include <vector>
#include "../Interfaces/Fitness.h"
#include "../Headers/Sudoku.h"

class SudokuFitness : public Fitness {
public:
   int howFit(const Puzzle& inputPuzzle) const;
private:
  int evaluateRows(const Sudoku& sudoku) const;
  int evaluateColumns(const Sudoku& sudoku) const;
  int evaluateQuadrants(const Sudoku& sudoku) const;
};