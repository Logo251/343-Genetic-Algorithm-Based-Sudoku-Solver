
#pragma once

#include "../Interfaces/Puzzle.h"
#include <iostream> //Used for the in/out operators.

class Sudoku : Puzzle {
public:
   friend std::istream& operator>>(std::istream& input, const Puzzle& inputPuzzle);
   friend std::ostream& operator<<(std::ostream& out, const Puzzle& inputPuzzle);

   int sudoku[9][9]; //This object's puzzle.
};