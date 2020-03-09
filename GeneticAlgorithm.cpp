
#include <iostream>
#include "Headers/SudokuPopulation.h"

int PERCENTAGE_CHANCE_OF_MUTATION = 2; //This is used to easily adjust the percentage chance of mutation.

void main(int argc, char** argv) {

   //Local Variables
   char inputChar; //used for processing cin.
   int inputSudoku[81] = { 0 }; //Used for creating the Sudoku that needs to be solved.
   int progressThroughInputSudoku = 0; //Used for inputting itno inputSudoku.

   //If no argument was given.
   if (argv[1] == nullptr) {
      std::cout << "No arguments.\n";
      return;
   }

   //In case the input is invalid by being negative.
   for (int i = 0; i < 2; i++) {
      if (argv[i] < 0) {
         return;
      }
   }

   //Read in the numbers for the first puzzle.
   //It has been stated that it can hang if it does not recieve 81 integers.
   while (std::cin.get(inputChar)) {
      if (isdigit(inputChar)) {
         inputSudoku[progressThroughInputSudoku] = (int)inputChar - 48; //The 48 converts the ascii number to an integer.
      }
   }

   //Now create population.
   SudokuPopulation sudokuPopulation((int)argv[1] - 48, inputSudoku); //The 48 converts the ascii number to an integer.

   for (int i = 0; i < (int)argv[1] - 48; i++) { //The 48 converts the ascii number to an integer.
      if (sudokuPopulation.BestFitness == 0) {
         break;
      }
      sudokuPopulation.Cull();
      sudokuPopulation.NewGeneration();
   }

   Puzzle* bestPuzzle = sudokuPopulation.BestIndividual();
   std::cout << bestPuzzle;
   return;
}