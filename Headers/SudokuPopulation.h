
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
   int tenPercentOfPop;
   //std::vector<Sudoku> sudokuStorage;
   std::priority_queue<Sudoku, std::vector<Sudoku>, SudokuPopulation::CompareSudokus> sudokuStorage;
   std::vector<Sudoku> topTenPercentOfSudokus; //Used to store the top 10% temporarily.
   SudokuFactory factory;
   SudokuFitness fitness;
};