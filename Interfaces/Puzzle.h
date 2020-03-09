
#pragma once

#include <iostream>

class Puzzle {
public:
   virtual friend std::istream& operator>>(std::istream& input, const Puzzle& puzzle) = 0;
   virtual friend std::ostream& operator<<(std::ostream& out, const Puzzle& puzzle) = 0;
   virtual std::string printPuzzle() const = 0;
   virtual std::istream& inputPuzzle(std::istream& input) = 0;
};