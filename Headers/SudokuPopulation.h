
#pragma once

#include <algorithm> //Used for sort.
#include "../Interfaces/Population.h"
#include "../Headers/SudokuFitness.h"
#include "../Headers/SudokuFactory.h"


class SudokuPopulation : public Population {
public:
   SudokuPopulation(int maxPopulationSize, int inputSudoku[]);
   void Cull();
   void NewGeneration();
   int BestFitness();
   const Puzzle* BestIndividual() const;
   

private:
   static bool CompareSudokus(const Sudoku& left, const Sudoku& right); // Needs to be static for the function to function.

   int maxPopulationSize;
   std::vector<Sudoku> sudokuStorage;
   SudokuFactory factory;
};