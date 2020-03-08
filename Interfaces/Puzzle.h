
#pragma once

#include <iostream>

class Puzzle {
public:
   virtual friend std::istream operator>>(std::istream input, const Puzzle& inputPuzzle) = 0;
   virtual friend std::ostream operator<<(std::ostream out, const Puzzle& inputPuzzle) = 0;
};