
#pragma once

#include <string>
#include <iostream>

class Puzzle {
public:
   virtual std::string toString() const = 0;
   virtual std::istream& inputPuzzle(std::istream& input) = 0;
};