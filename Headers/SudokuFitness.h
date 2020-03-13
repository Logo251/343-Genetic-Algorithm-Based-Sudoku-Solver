
#pragma once

#include <vector>
#include "../Interfaces/Fitness.h"
#include "../Headers/Sudoku.h"

class SudokuFitness : public Fitness {
public:
   int howFit(const Puzzle& inputPuzzle) const;
private:
  int evaluateRows(Sudoku sudoku) const;
  int evaluateColumns(Sudoku sudoku) const;
  int evaluateQuadrants(Sudoku sudoku) const;
};