#include "..\Headers\SudokuPopulation.h"
#include "..\Headers\SudokuFitness.h"

SudokuPopulation::SudokuPopulation(int maxPopulationSize, int inputSudoku[81]) {
   this->maxPopulationSize = maxPopulationSize;
}

void SudokuPopulation::Cull() {
}

void SudokuPopulation::NewGeneration() {
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
         bestFitnessPuzzle = sudokuStorage[i];
      }
   }
   return bestFitnessPuzzle;
}
