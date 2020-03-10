#include <algorithm> //Used for sort.
#include "..\Headers\SudokuPopulation.h"
#include "..\Headers\SudokuFitness.h"
#include "..\Headers\SudokuFactory.h"

SudokuPopulation::SudokuPopulation(int maxPopulationSize, int inputSudoku[81]) {
   this->maxPopulationSize = maxPopulationSize;
   sudokuStorage.resize(maxPopulationSize);
   sudokuStorage.push_back(dynamic_cast<Sudoku&>(factory.createPuzzle())
}

void SudokuPopulation::Cull() {

   //Sort in order of fitness.
   std::sort(sudokuStorage.begin(), sudokuStorage.end(), CompareSudokus);

   //Empty the 90% of the graph.
   for (int i = (maxPopulationSize * 0.1); i < maxPopulationSize; i++) {
      sudokuStorage.erase(sudokuStorage.begin() + i - 1); //the -1 offsets the +1 given by the iterator.
   }
}

void SudokuPopulation::NewGeneration() {
   //Local Variables
   int progressThroughTopTenPercent = 0;

   //Initialization condition.
   if (sudokuStorage.size() == 1) {
      for (int i = 0; i < maxPopulationSize; i++) {
         sudokuStorage.at(i) = dynamic_cast<Sudoku&>(factory.createPuzzle())
      }
   }

   if (sudokuStorage.size() == (maxPopulationSize * 0.1)) {
      for (int i = (maxPopulationSize * 0.1); i < maxPopulationSize; i++) {
         sudokuStorage.at()
      }
   }
}

int SudokuPopulation::BestFitness() {
   //Local Variables
   int bestFitnessRating = 99999; //99999 is more than every possible error in Sudoku.
   int currentFitness; //Rating of the current Sudoku in question.

   for (int i = 0; i < maxPopulationSize; i++) {
      currentFitness = SudokuFitness::howFit(sudokuStorage[i]);
         if (currentFitness < bestFitnessRating) {
            bestFitnessRating = currentFitness;
      }
   }
   return bestFitnessRating;
}

Puzzle* SudokuPopulation::BestIndividual() {
   //Local Variables
   int bestFitnessRating = 99999; //99999 is more than every possible error in Sudoku.
   int currentFitness; //Rating of the current Sudoku in question.
   Puzzle* bestFitnessPuzzle;

   for (int i = 0; i < maxPopulationSize; i++) {
      currentFitness = SudokuFitness::howFit(sudokuStorage[i]);
      if (currentFitness < bestFitnessRating) {
         bestFitnessRating = currentFitness;
         bestFitnessPuzzle = &sudokuStorage[i];
      }
   }
   return bestFitnessPuzzle;
}

bool SudokuPopulation::CompareSudokus(Sudoku left, Sudoku right) {
   if (SudokuFitness::howFit(left) < SudokuFitness::howFit(right) {
      return true;
   }
   return false;
}
