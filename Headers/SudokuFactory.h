/*
File Name:  SudokuFactory.h
Author:     Logan Petersen
Date:       March 13, 2020
Purpose:    This is the header file for the SudokuFactory class containing SudokuFactory's
            interface. The purpose of this code is to provide the function prototypes for both
            SudokuFactory, define its variables needed, and demonstrate its interface utilization.
*/
#pragma once

#include <sstream> //Used for string stream.
#include "../Interfaces/PuzzleFactory.h"
#include "../Headers/SudokuOffspring.h"

class SudokuFactory : public PuzzleFactory {
public:

   /*
   Purpose:          Create a Sudoku using a reference Sudoku.
   Parameters:       referencePuzzle, a Puzzle object used for creating the new Sudoku.
   Preconditions:    A new Sudoku needs to be created.
   Postconditions:   A new, mutated, Sudoku is created.
   Return value:     Puzzle, the new Sudoku.
   Functions Called: reproductionObject's createOffspring, used for creating and mutating a new Sudoku.
   */
   Puzzle& createPuzzle(Puzzle& referencePuzzle);

   /*
   Purpose:          Create a Sudoku using a raw sudoku.
   Parameters:       inputArray, an int array used for creating the new Sudoku.
   Preconditions:    A new Sudoku needs to be created.
   Postconditions:   A new, mutated, Sudoku is created.
   Return value:     Puzzle, the new Sudoku.
   Functions Called: reproductionObject's createOffspring, used for creating and mutating a new Sudoku.
   */
   Puzzle& createPuzzle(int inputArray[81]);

   SudokuOffspring reproductionObject; //Used for mutating puzzles.
   Sudoku initialSudoku; //The inital sudoku this program uses, needed because cannot return local variables.
};
