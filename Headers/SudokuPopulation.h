
#pragma once

#include <vector>
#include "../Interfaces/Population.h"
#include "Sudoku.h"

class SudokuPopulation : public Population {
public:
   SudokuPopulation(int maxPopulationSize, int inputSudoku[81]);
   void Cull();
   void NewGeneration();
   int BestFitness();
   Puzzle* BestIndividual();
   bool CompareSudokus(Sudoku left, Sudoku right);

private:
   int maxPopulationSize;
   std::vector<Sudoku> sudokuStorage;
   SudokuFactory factory;
};