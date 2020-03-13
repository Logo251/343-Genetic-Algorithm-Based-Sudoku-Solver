
#include "../Headers/SudokuPopulation.h"

SudokuPopulation::SudokuPopulation(int maxPopulationSize, int inputSudoku[81]) {
   this->maxPopulationSize = maxPopulationSize; 

   //Generate fitness for this function (unsure if I can do this in the factory while following spec, so I do it here)
   Sudoku toBeAdded = dynamic_cast<Sudoku&>(factory.createPuzzle(inputSudoku));
   toBeAdded.fitness = fitness.howFit(toBeAdded);

   sudokuStorage.push(toBeAdded);
}

void SudokuPopulation::Cull() {
   //Local Variables
   std::vector<Sudoku> temporaryStorage; //Used to store the top 10% temporarily.

   //If generation is not full, we just initialized, do nothing.
   if(sudokuStorage.size() == 1) //One because that is how we initalized the item.
   return;

   //Empty the 90% of the graph.
   for (int i = 0; i < (maxPopulationSize * 0.1 + 0.5 - 1); i++) { //the -1 offsets the start at 0, use 0.5 to round for specific cases.
      temporaryStorage.push_back(sudokuStorage.top());
      sudokuStorage.pop();
   }

   //This resets sudokuStorage more efficiently than while looping an popping each element (~17ms vs ~550ms).
   sudokuStorage = std::priority_queue<Sudoku, std::vector<Sudoku>, CompareSudokus>();

   //Put the 10% back in.
   for (Sudoku i : temporaryStorage) {
      sudokuStorage.push(i);
   }
}

void SudokuPopulation::NewGeneration() {
   //Local Variables
   int progressThroughTopTenPercent = 0;
   std::vector<Sudoku> temporaryStorage; //Used to store the top 10% temporarily.
   Sudoku toBeAdded; //Used for giving fitness just before being added to the queue.

   //Initialization condition.
   if (sudokuStorage.size() == 1) {
      Sudoku starterSudoku = sudokuStorage.top(); //This is put here to save resource utilization, as it is only used here.
      for (int i = 0; i < maxPopulationSize - 1; i++) { //One is already in the table.
         toBeAdded = dynamic_cast<Sudoku&>(factory.createPuzzle(starterSudoku));
         toBeAdded.fitness = fitness.howFit(toBeAdded);
         sudokuStorage.push(toBeAdded);
      }
      return;
   }

   //Isolate the 10% so we can duplicate them.
   for (int i = 0; i < (maxPopulationSize * 0.1 + 0.5 - 1); i++) { //the -1 offsets the start at 0, use 0.5 to round for specific cases.
      temporaryStorage.push_back(sudokuStorage.top());
      sudokuStorage.pop();
   }
   for (Sudoku i : temporaryStorage) {
      sudokuStorage.push(i);
   }

   if (sudokuStorage.size() == (int)(maxPopulationSize * 0.1 + 0.5)) { //Use 0.5 to round for specific cases.
      for (int i = (maxPopulationSize * 0.1 + 0.5); i < maxPopulationSize; i++) { //Use 0.5 to round for specific cases.

         //Generate fitness for this function (unsure if I can do this in the factory while following spec, so I do it here)
         toBeAdded = dynamic_cast<Sudoku&>(factory.createPuzzle(temporaryStorage.at(progressThroughTopTenPercent)));
         toBeAdded.fitness = fitness.howFit(sudokuStorage.top());

         sudokuStorage.push(toBeAdded);

         if (progressThroughTopTenPercent < maxPopulationSize * 0.1 - 1 + 0.5) { //-1 for edge, starts at 0, 0.5 to round for specific cases.
            progressThroughTopTenPercent = 0;
         }
         else {
            progressThroughTopTenPercent++;
         }
      }
   }
}

int SudokuPopulation::BestFitness() {
   return sudokuStorage.top().fitness;
}

const Puzzle& SudokuPopulation::BestIndividual() const {
   return sudokuStorage.top();
}

bool SudokuPopulation::CompareSudokus::operator()(const Sudoku& left, const Sudoku& right) {
   return left.fitness < right.fitness;
}
