
#pragma once

#include <sstream>
#include "../Interfaces/Puzzle.h"

class Sudoku : public Puzzle {
public:
   Sudoku();
   Sudoku(int inputSudoku[81]);
   Sudoku(const Sudoku& inputSudoku);
   Sudoku& operator=(const Sudoku& inputSudoku);
   friend std::istream& operator>>(std::istream& input, const Puzzle& puzzle);
   friend std::ostream& operator<<(std::ostream& out, const Puzzle& puzzle);
   std::string toString() const;
   std::istream& inputPuzzle(std::istream& input);

   short int sudoku[9][9] = { { 0 }, { 0 }}; //This object's puzzle.
   int fitness = 1874919423; //This object's fitness, defaults to what should be the max of int.
};
