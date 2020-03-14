/*
File Name:  SudokuPopulation.cpp
Author:     Logan Petersen
Date:       March 13, 2020
Purpose:    The purpose of this code is to be the function definitions for
            the function prototypes defined in SudokuPopulation.h. The code
            allows creation of SudokuPopulation and its use.
*/

#include "../Headers/SudokuPopulation.h"

/*
Purpose:          Construct Sudoku when Sudoku is created with arguments.
Parameters:       maxPopulationSize, the max size of the population.
                  inputSudoku, an array of integers that represesents a raw sudoku.
                  Used later for creating a Sudoku with these values for its sudoku.
Preconditions:    This specific SudokuPopulation object has not been instantiated.
Postconditions:   Sudoku object is instantiated with the given arguments.
Return value:     None.
Functions Called: createPuzzle, used to create a Sudoku puzzle for the population.
                  howFit, used to evaluate the Sudoku puzzle.
*/
SudokuPopulation::SudokuPopulation(int maxPopulationSize, int inputSudoku[81]) {
   this->maxPopulationSize = maxPopulationSize;
   tenPercentOfPop = maxPopulationSize * 0.1 + 0.5; //use 0.5 to round for specific cases.

   //Generate fitness for this function (unsure if I can do this in the factory while following spec, so I do it here)
   Sudoku toBeAdded = dynamic_cast<Sudoku&>(factory.createPuzzle(inputSudoku));
   toBeAdded.fitness = fitness.howFit(toBeAdded);

   sudokuStorage.push(toBeAdded);
}

/*
Purpose:          Deletes the worst 90% of the entire generation.
Parameters:       None.
Preconditions:    This specific SudokuPopluation object has been instantiated.
Postconditions:   The population is only 10% of its previous size.
Return value:     None.
Functions Called: None.
*/
void SudokuPopulation::Cull() {
   //Clear the old top 10% of sudokus.
   topTenPercentOfSudokus.clear();

   //If generation is not full, we just initialized, do nothing.
   if (sudokuStorage.size() == 1) { //One because that is how we initalized the item.
      return;
   }

   //Empty the 90% of the graph.
   for (int i = 0; i < (tenPercentOfPop); i++) { //the -1 offsets the start at 0
      //The top ten percent is not full yet.

      topTenPercentOfSudokus.push_back(sudokuStorage.top());
      sudokuStorage.pop();
   }

   //This resets sudokuStorage more efficiently than while looping an popping each element (~17ms vs ~550ms).
   sudokuStorage = std::priority_queue<Sudoku, std::vector<Sudoku>, SudokuPopulation::CompareSudokus>();

   for (Sudoku i : topTenPercentOfSudokus) {
      //We have not iterated through every Sudoku in the top ten percent.

      sudokuStorage.push(i);
   }
}

/*
Purpose:          Regenerates the missing population.
Parameters:       None.
Preconditions:    This specific SudokuPopluation object has been instantiated.
Postconditions:   The population is at 100% of its size.
Return value:     None.
Functions Called: createPuzzle, used to create a Sudoku puzzle for the population.
                  howFit, used to evaluate the Sudoku puzzle.
*/
void SudokuPopulation::NewGeneration() {
   //Local Variables
   int progressThroughTopTenPercent = 0;
   Sudoku toBeAdded; //Used for giving fitness just before being added to the queue.

   //Initialization condition.
   if (sudokuStorage.size() == 1) {
      Sudoku starterSudoku = sudokuStorage.top(); //This is put here to save resources, as it is only used here.
      for (int i = 0; i < maxPopulationSize - 1; i++) { //One is already in the table.
         toBeAdded = dynamic_cast<Sudoku&>(factory.createPuzzle(starterSudoku));

         toBeAdded.fitness = fitness.howFit(toBeAdded);
         sudokuStorage.push(toBeAdded);
      }
      return;
   }

   if (sudokuStorage.size() == tenPercentOfPop) {
      for (int i = tenPercentOfPop; i < maxPopulationSize; i++) {
         //We have not iterated through every open space in the population.

         //Generate fitness for this function (unsure if I can do this in the factory while following spec, so I do it here)
         toBeAdded = dynamic_cast<Sudoku&>(factory.createPuzzle(topTenPercentOfSudokus.at(progressThroughTopTenPercent)));
         toBeAdded.fitness = fitness.howFit(toBeAdded);
         sudokuStorage.push(toBeAdded);

         if (progressThroughTopTenPercent == topTenPercentOfSudokus.size() - 1) {
            progressThroughTopTenPercent = 0;
         }
         else {
            progressThroughTopTenPercent++;
         }
      }
   }
}

/*
Purpose:          Gives the most fit function's fitness.
Parameters:       None.
Preconditions:    This specific SudokuPopluation object has been instantiated and has a Sudoku inside it.
Postconditions:   Nothing has been changed.
Return value:     int, used to give the most fit object's fitness.
Functions Called: None.
*/
const int SudokuPopulation::BestFitness() const {
   return sudokuStorage.top().fitness;
}

/*
Purpose:          Gives the most fit function.
Parameters:       None.
Preconditions:    This specific SudokuPopluation object has been instantiated and has a Sudoku inside it.
Postconditions:   Nothing has been changed.
Return value:     Puzzle, used to give a const reference to the Sudoku.
Functions Called: None.
*/
const Puzzle& SudokuPopulation::BestIndividual() const {
   return sudokuStorage.top();
}

/*
Purpose:          Used to allow the priority queue to sort Sudokus.
Parameters:       left, the left Sudoku, and right, the right Sudoku being compared.
Preconditions:    This specific SudokuPopluation object and an item is being added to SudokuPopulation.
Postconditions:   An item is added at the proper place in Sudoku
Return value:     bool, to indicate if a Sudoku should go before or after another.
Functions Called: None.
*/
bool SudokuPopulation::CompareSudokus::operator()(const Sudoku& left, const Sudoku& right) {
   return left.fitness > right.fitness;
}
