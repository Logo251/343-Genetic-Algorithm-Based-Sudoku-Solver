
#include <iostream>
#include "Headers/SudokuPopulation.h"

int main(int argc, char** argv) {

   //Local Variables
   char inputChar; //used for processing cin.
   int inputSudoku[81] = { 0 }; //Used for creating the Sudoku that needs to be solved.
   int progressThroughInputSudoku = 0; //Used for inputting itno inputSudoku.
   int maximumPopulationSize = 0;
   int maximumGenerationCount = 0;

   //If no argument was given.
   if (argv[1] == nullptr || argv[2] == nullptr) {
      std::cout << "No or insufficient arguments.\n";
      return 0;
   }

   //In case the input is invalid by being negative or zero.
   for (int i = 1; i < 3; i++) {
      if (argv[i] <= 0) {
         return 0;
      }
   }

   //Convert arguments to ints.
   maximumPopulationSize = std::stoi(argv[1]);
   maximumGenerationCount = std::stoi(argv[2]);

   if (maximumPopulationSize < 10) {
      std::cout << "Insufficient population size for proper operation.";
      return 0;
   }

   //Read in the numbers for the first puzzle.
   //It has been stated that it can hang if it does not recieve 81 integers.
   while (std::cin.get(inputChar)) {
      if (isdigit(inputChar)) {
         inputSudoku[progressThroughInputSudoku] = (int)inputChar - 48; //The 48 converts the ascii number to an integer.
         progressThroughInputSudoku++;
         if (progressThroughInputSudoku == 81) {
            break;
         }
      }
   }

   //Now create population.
   SudokuPopulation sudokuPopulation(maximumPopulationSize, inputSudoku);

   for (int i = 0; i <= maximumGenerationCount; i++) {
      if (sudokuPopulation.BestFitness() == 0) {
         break;
      }
      sudokuPopulation.Cull();
      sudokuPopulation.NewGeneration();
      if (i % 15 == 0) {
         std::cout << '\r' << i << ' ' << sudokuPopulation.BestFitness() << '\n' << dynamic_cast<const Sudoku&>(sudokuPopulation.BestIndividual());
      }
   }

   std::cout << dynamic_cast<const Sudoku&>(sudokuPopulation.BestIndividual());
   return 0;
}
