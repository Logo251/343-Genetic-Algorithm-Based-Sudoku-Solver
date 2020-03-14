
#include <list>
#include "../Headers/SudokuPopulation.h"

SudokuPopulation::SudokuPopulation(int maxPopulationSize, int inputSudoku[81]) {
   this->maxPopulationSize = maxPopulationSize;
   tenPercentOfPop = maxPopulationSize * 0.1 + 0.5; //use 0.5 to round for specific cases.

   //Generate fitness for this function (unsure if I can do this in the factory while following spec, so I do it here)
   Sudoku toBeAdded = dynamic_cast<Sudoku&>(factory.createPuzzle(inputSudoku));
   toBeAdded.fitness = fitness.howFit(toBeAdded);

   sudokuStorage.push(toBeAdded);
}

void SudokuPopulation::Cull() {
   //Clear the old top 10% of sudokus.
   topTenPercentOfSudokus.clear();

   //If generation is not full, we just initialized, do nothing.
   if (sudokuStorage.size() == 1) { //One because that is how we initalized the item.
      return;
   }

   //Empty the 90% of the graph.
   for (int i = 0; i < (tenPercentOfPop); i++) { //the -1 offsets the start at 0
      topTenPercentOfSudokus.push_back(sudokuStorage.top());
      sudokuStorage.pop();
   }

   for (int i = 0; i < 100; i++) {
      std::cout << sudokuStorage.top().sudoku[0][0] << sudokuStorage.top().sudoku[1][0] << sudokuStorage.top().sudoku[2][0] << '\t'; //TODO: delete
      sudokuStorage.pop();
   }


   //This resets sudokuStorage more efficiently than while looping an popping each element (~17ms vs ~550ms).
   sudokuStorage = std::priority_queue<Sudoku, std::vector<Sudoku>, SudokuPopulation::CompareSudokus>();

   for (Sudoku i : topTenPercentOfSudokus) {
      sudokuStorage.push(i);
   }
}

void SudokuPopulation::NewGeneration() {
   //Local Variables
   int progressThroughTopTenPercent = 0;
   Sudoku toBeAdded; //Used for giving fitness just before being added to the queue.

   //Initialization condition.
   if (sudokuStorage.size() == 1) {
      Sudoku starterSudoku = sudokuStorage.top(); //This is put here to save resources, as it is only used here.
      for (int i = 0; i < maxPopulationSize - 1; i++) { //One is already in the table.
         toBeAdded = dynamic_cast<Sudoku&>(factory.createPuzzle(starterSudoku));
         if (toBeAdded.sudoku[0][0] == 4 && toBeAdded.sudoku[1][0] == 3 && toBeAdded.sudoku[2][0] == 5) {
            int test = 0; //TODO:delete
         }
         toBeAdded.fitness = fitness.howFit(toBeAdded);
         sudokuStorage.push(toBeAdded);
      }
      return;
   }

   if (sudokuStorage.size() == tenPercentOfPop) {
      for (int i = tenPercentOfPop; i < maxPopulationSize; i++) { //Use 0.5 to round for specific cases.

         //TODO: use while for each item repeat maxpopsize - 10%.
         //Generate fitness for this function (unsure if I can do this in the factory while following spec, so I do it here)
         toBeAdded = dynamic_cast<Sudoku&>(factory.createPuzzle(topTenPercentOfSudokus.at(progressThroughTopTenPercent)));
         if (toBeAdded.sudoku[0][0] == 4 && toBeAdded.sudoku[1][0] == 3 && toBeAdded.sudoku[2][0] == 5) {
            int test = 0; //TODO:delete
         }
         toBeAdded.fitness = fitness.howFit(sudokuStorage.top());

         sudokuStorage.push(toBeAdded);

         if (progressThroughTopTenPercent == topTenPercentOfSudokus.size() - 1) {
            progressThroughTopTenPercent = 0;
         }
         else {
            progressThroughTopTenPercent++;
         }
      }
   }
   else {
      std::cout << "exploded" << sudokuStorage.size(); //TODO: remove
   }
}

int SudokuPopulation::BestFitness() {
   return sudokuStorage.top().fitness;
}

const Puzzle& SudokuPopulation::BestIndividual() const {
   return sudokuStorage.top();
}

bool SudokuPopulation::CompareSudokus::operator()(const Sudoku& left, const Sudoku& right) {
   return left.fitness > right.fitness;
}
