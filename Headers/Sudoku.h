
#pragma once

#include <sstream>
#include "../Interfaces/Puzzle.h"

class Sudoku : public Puzzle {
public:
   Sudoku() {}
   Sudoku(int inputSudoku[81]);
   friend std::istream& operator>>(std::istream& input, const Puzzle& puzzle);
   friend std::ostream& operator<<(std::ostream& out, const Puzzle& puzzle);
   std::string toString() const;
   std::istream& inputPuzzle(std::istream& input);

   int sudoku[9][9]; //This object's puzzle.
   int fitness; //This object's fitness.
};