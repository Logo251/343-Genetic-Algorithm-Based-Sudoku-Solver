
#include "../Interfaces/Fitness.cpp"

class SudokuFitness : Fitness {
public:

private:
  int evaluateRows(Sudoku sudoku);
  int evaluateColumns(Sudoku sudoku);
  int evaluateQuadrants(Sudoku sudoku);
};