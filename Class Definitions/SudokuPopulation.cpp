
#include "../Headers/SudokuPopulation.h"

SudokuPopulation::SudokuPopulation(int maxPopulationSize, int inputSudoku[]) {
   this->maxPopulationSize = maxPopulationSize;
   sudokuStorage.resize(maxPopulationSize);
   //sudokuStorage.push_back(dynamic_cast<Sudoku&>(factory.createPuzzle(inputSudoku)));
}

void SudokuPopulation::Cull() {

   //If generation is not full, we just initialized, do nothing.
   if(sudokuStorage.size() == 1) //One because that is how we initalized the item.
   return;

   //Sort in order of fitness.
   std::sort(sudokuStorage.begin(), sudokuStorage.end(), SudokuPopulation::CompareSudokus);

   //Empty the 90% of the graph.
   //TODO: CHeck this
   for (int i = (maxPopulationSize * 0.1 + 0.5); i < maxPopulationSize; i++) { //Use 0.5 to round for specific cases.
      sudokuStorage.erase(sudokuStorage.begin() + i - 1, sudokuStorage.end()); //the -1 offsets the +1 given by the iterator.
   }
}

void SudokuPopulation::NewGeneration() {
   //Local Variables
   int progressThroughTopTenPercent = 0;

   //Initialization condition.
   if (sudokuStorage.size() == 1) {
      for (int i = 0; i < maxPopulationSize; i++) {
         //sudokuStorage.at(i) = dynamic_cast<Sudoku&>(factory.createPuzzle(sudokuStorage.at(0)));
      }
      return;
   }

   if (sudokuStorage.size() == (maxPopulationSize * 0.1 + 0.5)) { //Use 0.5 to round for specific cases.
      for (int i = (maxPopulationSize * 0.1 + 0.5); i < maxPopulationSize; i++) { //Use 0.5 to round for specific cases.
         //sudokuStorage.at(i) = dynamic_cast<Sudoku&>(factory.createPuzzle(sudokuStorage.at(progressThroughTopTenPercent)));
         if (progressThroughTopTenPercent < maxPopulationSize * 0.1 - 1 + 0.5) { //-1 for edge case, 0.5 to round for specific cases.
            progressThroughTopTenPercent = 0;
         }
         else {
            progressThroughTopTenPercent++;
         }
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

const Puzzle* SudokuPopulation::BestIndividual() const {
   //Local Variables
   int bestFitnessRating = 99999; //99999 is more than every possible error in Sudoku.
   int currentFitness; //Rating of the current Sudoku in question.
   const Sudoku* bestFitnessPuzzle = nullptr;

   for (int i = 0; i < maxPopulationSize; i++) {
      currentFitness = SudokuFitness::howFit(sudokuStorage[i]);
      if (currentFitness < bestFitnessRating) {
         bestFitnessRating = currentFitness;
         bestFitnessPuzzle = &sudokuStorage[i];
      }
   }
   return bestFitnessPuzzle;
}


bool SudokuPopulation::CompareSudokus(const Sudoku &left, const Sudoku &right) {
   if (SudokuFitness::howFit(left) < SudokuFitness::howFit(right)) {
      return true;
   }
   return false;
}