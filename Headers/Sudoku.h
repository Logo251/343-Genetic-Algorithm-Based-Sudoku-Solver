
#pragma once

#include <sstream>
#include "../Interfaces/Puzzle.h"

class Sudoku : public Puzzle {
public:
   Sudoku(int inputSudoku[]);
   friend std::istream& operator>>(std::istream& input, const Puzzle& puzzle);
   friend std::ostream& operator<<(std::ostream& out, const Puzzle& puzzle);
   std::string toString() const;
   std::istream& inputPuzzle(std::istream& input);

   int sudoku[9][9] = { 0 }; //This object's puzzle.
};