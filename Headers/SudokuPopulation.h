/*
File Name:  SudokuPopulation.h
Author:     Logan Petersen
Date:       March 13, 2020
Purpose:    This is the header file for the SudokuPopulation class containing
            SudokuPopulation's interface. The purpose of this code is to provide
            the function prototypes for SudokuPopulation and its structure CompareSudokus,
            define defaults for some, variables, and connect to its interface.
*/

#pragma once

#include <queue> //Used for the priority queue
#include <algorithm> //Used for sort.
#include "../Interfaces/Population.h"
#include "../Headers/SudokuFitness.h"
#include "../Headers/SudokuFactory.h"


class SudokuPopulation : public Population {
public:

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
   SudokuPopulation(int maxPopulationSize, int inputSudoku[81]);

   /*
   Purpose:          Deletes the worst 90% of the entire generation.
   Parameters:       None.
   Preconditions:    This specific SudokuPopluation object has been instantiated.
   Postconditions:   The population is only 10% of its previous size.
   Return value:     None.
   Functions Called: None.
   */
   void Cull();

   /*
   Purpose:          Regenerates the missing population.
   Parameters:       None.
   Preconditions:    This specific SudokuPopluation object has been instantiated.
   Postconditions:   The population is at 100% of its size.
   Return value:     None.
   Functions Called: createPuzzle, used to create a Sudoku puzzle for the population.
                     howFit, used to evaluate the Sudoku puzzle.
   */
   void NewGeneration();

   /*
   Purpose:          Gives the most fit function's fitness.
   Parameters:       None.
   Preconditions:    This specific SudokuPopluation object has been instantiated and has a Sudoku inside it.
   Postconditions:   Nothing has been changed.
   Return value:     int, used to give the most fit object's fitness.
   Functions Called: None.
   */
   const int BestFitness() const;

   /*
   Purpose:          Gives the most fit function.
   Parameters:       None.
   Preconditions:    This specific SudokuPopluation object has been instantiated and has a Sudoku inside it.
   Postconditions:   Nothing has been changed.
   Return value:     Puzzle, used to give a const reference to the Sudoku.
   Functions Called: None.
   */
   const Puzzle& BestIndividual() const;
   

private:
   struct CompareSudokus {
      /*
      Purpose:          Used to allow the priority queue to sort Sudokus.
      Parameters:       left, the left Sudoku, and right, the right Sudoku being compared.
      Preconditions:    This specific SudokuPopluation object and an item is being added to SudokuPopulation.
      Postconditions:   An item is added at the proper place in Sudoku
      Return value:     bool, to indicate if a Sudoku should go before or after another.
      Functions Called: None.
      */
      bool operator()(const Sudoku& left, const Sudoku& right);
   };

   int maxPopulationSize;  //Used to store the maximum population size allowed.
   int tenPercentOfPop;    //Used to store the number that is the top ten percent of population break-off point. Used to save resources and increase speed.
   std::priority_queue<Sudoku, std::vector<Sudoku>, SudokuPopulation::CompareSudokus> sudokuStorage; //Used to store Sudokus in an ordered format.
   std::vector<Sudoku> topTenPercentOfSudokus; //Used to store the top 10% temporarily.
   SudokuFactory factory; //Used to generate Sudokus.
   SudokuFitness fitness; //Used to evalute Sudokus.
};