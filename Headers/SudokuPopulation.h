
#include "../Interfaces/Population.h"

class SudokuPopulation : Population {
public:
   SudokuPopulation(int maxPopulationSize, int inputSudoku[81]);
   void Cull();
   void NewGeneration();
   int BestFitness();
   Puzzle* BestIndividual();

private:
   int sudokuStorage[];
};