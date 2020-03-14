/*
   File Name:  GeneticAlgorithm.cpp
   Author:     Logan Petersen
   Date:       March 13, 2020
   Purpose:    The purpose of this program is to solve Sudoku puzzles using a genetic algorithm. However, while solving
   this problem we must also demonstrate an understanding of OOP principles. Therefore, the problem’s solution must be
   broken into many parts, with interfaces for each part. The program itself only needs to solve Sudoku, but the program
   must be designed that the puzzle and related components can be swapped out for another puzzle and the program will solve
   it with minimal refactoring.

   The problem states there are three inputs in two different manners. Two inputs are given as arguments to the program, and
   they are the max number of generations and max number of generations allowed. The other is the Sudoku puzzle through cin
   in the form of a stream of numbers, white space, and potentially other characters. The numbers are used to build the Sudoku
   puzzle to be solved.

   Output for this problem is a human-friendly depiction of the best Sudoku puzzle solution found.
   To adequately demonstrate an understanding of OOP principles, the program must implement at least four interfaces and six
   classes, each with a specific purpose. The interfaces are PuzzleFactory, Puzzle, Population, Reproduction, and Fitness.
   PuzzleFactory classes, in this case SudokuFactory, generates Puzzle objects, so we can have many different puzzles for use in
   the genetic algorithm later, in this case Sudokus. Puzzle classes are the overarching puzzle type that is stored in the population
   classes, in this program SudokuPopulation, which in turn is influenced by GeneticAlgorithm, the driver code. Reproduction classes
   handle the SudokuOffspring, which will use PuzzleFactory classes to generate them. Finally, Fitness classes evaluate a puzzles fitness,
   or how well each puzzle is solved, in this program the class used I SudokuFitness. This is used to rate each Puzzle for how well
   it solves the problem. This is all controlled by GeneticAlgorithm.

   Input arguments for this program are the size of population and maximum number of generations. Formatting and order is not mentioned,
   so it is assumed that it will be input in the order above in integers, as a float for the number of generations does not appear valid.
   An example of this input is below.

   ./PuzzleSolver 1000 200000

   This runs the program with a max population size of 1000 and a number of generations allowed of 200,000.

   Input data after program startup is a string of 81 ASCII text numbers read through cin. These numbers correspond to the Sudoku puzzle
   numbers in the order of left to right, top to bottom. This means the first digit goes in the top left of the Sudoku puzzle, and last
   digit goes on the bottom right. A “0” is a empty position, any other number is part of the Sudoku puzzle and cannot be changed to solve
   the problem. The ASCII numbers may be split by white space or any non-integer character. These must be ignored. An example is below.

   000100010020304050000003040301000060040201009000030000600001000070000030001001000
   (Note that this is not a valid puzzle, merely an example of input.)

   This input would create this puzzle, stored internally, with 0 representing a blank spot:
   +-------+-------+-------+
   | 0 0 0 | 1 0 0 | 0 1 0 |
   | 2 0 3 | 0 4 0 | 5 0 0 |
   | 0 0 0 | 0 3 0 | 4 0 3 |
   +-------+-------+-------+
   | 0 1 0 | 0 0 0 | 6 0 0 |
   | 4 0 2 | 0 1 0 | 0 9 0 |
   | 0 0 0 | 3 0 0 | 0 0 6 |
   +-------+-------+-------+
   | 0 0 0 | 0 1 0 | 0 0 0 |
   | 7 0 0 | 0 0 0 | 3 0 0 |
   | 0 1 0 | 0 1 0 | 0 0 0 |
   +-------+-------+-------+
The output will be a sudoku puzzle with all the numbers filled in with number 1-9 if the puzzle is solved The format will be the same as the
diagram above. If the puzzle is not solved, it will output the best solution found before being told to terminate.
*/

#include <iostream>
#include "Headers/SudokuPopulation.h"

int main(int argc, char** argv) {

   //Local Variables
   char inputChar; //used for processing cin.
   int inputSudoku[81] = { 0 };        //Used for creating the Sudoku that needs to be solved.
   int progressThroughInputSudoku = 0; //Used for inputting itno inputSudoku.
   int maximumPopulationSize = 0;      //Used for storing the maximum population size in a easy-to-access location.
   int maximumGenerationCount = 0;     //Used for storing the maximum generation number in a easy-to-access location.

   //If no argument was given.
   if (argv[1] == nullptr || argv[2] == nullptr) {
      std::cout << "No or insufficient arguments.\n";
      return 0;
   }

   //In case the input is invalid by being negative or zero.
   for (int i = 1; i < 3; i++) {
      //We have not iterated twice completely yet.
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
      //cin.get has another character that has not been parsed yet.

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

   //Note that this program uses a "0" generation. This is used because a generation is, as it appears in specifications, one
   //full population. Therefore, a 0 population is used to initalize the population and can technically solve problems in 0
   //generations, if the first generation was the answer.. This can be fixed by inputting generation minus one or changing <=
   //to <. Technically this is one more generation than specified, but I believe this is more to what the requirements request.
   for (int i = 0; i <= maximumGenerationCount; i++) {
      //We have not reached the maximum number of generations.

      if (sudokuPopulation.BestFitness() == 0) {
         break;
      }
      sudokuPopulation.Cull();
      sudokuPopulation.NewGeneration();
   }

   std::cout << dynamic_cast<const Sudoku&>(sudokuPopulation.BestIndividual());
   return 0;
}
