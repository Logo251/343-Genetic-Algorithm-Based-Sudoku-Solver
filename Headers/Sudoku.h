
#pragma once

#include "../Interfaces/Puzzle.h"
#include <iostream> //Used for the in/out operators.

class Sudoku : public Puzzle {
public:
   friend std::istream& operator>>(std::istream& input, const Puzzle& puzzle);
   friend std::ostream& operator<<(std::ostream& out, const Puzzle& puzzle);
   std::string printPuzzle() const;
   std::istream& inputPuzzle(std::istream& input);

   int sudoku[9][9]; //This object's puzzle.
};