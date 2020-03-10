
#include "../Interfaces/Reproduction.h"
#include <random>
#include <ctime>

class SudokuOffspring : public Reproduction {
public:
   Puzzle& makeOffspring(Puzzle& input);
};