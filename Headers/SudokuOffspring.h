
#include "../Interfaces/Reproduction.h"
#include <random>
#include <ctime>

class SudokuOffspring : Reproduction {
   Reproduction& makeOffspring(Puzzle& input);
   }
};