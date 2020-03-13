
#pragma once

#include <queue> //Used for the priority queue
#include <algorithm> //Used for sort.
#include "../Interfaces/Population.h"
#include "../Headers/SudokuFitness.h"
#include "../Headers/SudokuFactory.h"


class SudokuPopulation : public Population {
public:
   SudokuPopulation(int maxPopulationSize, int inputSudoku[81]);
   void Cull();
   void NewGeneration();
   int BestFitness();
   const Puzzle& BestIndividual() const;
   

private:
   struct CompareSudokus {
      bool operator()(const Sudoku& left, const Sudoku& right);
   };

   int maxPopulationSize;
   //std::vector<Sudoku> sudokuStorage;
   std::priority_queue<Sudoku, std::vector<Sudoku>, SudokuPopulation::CompareSudokus> sudokuStorage;
   SudokuFactory factory;
   SudokuFitness fitness;
};