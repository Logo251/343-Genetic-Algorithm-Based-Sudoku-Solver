
#pragma once

#include "../Interfaces/Population.h"
#include "Sudoku.h"

class SudokuPopulation : public Population {
public:
   SudokuPopulation(int maxPopulationSize, int inputSudoku[81]);
   void Cull();
   void NewGeneration();
   int BestFitness();
   Puzzle* BestIndividual();

private:
   int maxPopulationSize;
   Sudoku sudokuStorage[];
};