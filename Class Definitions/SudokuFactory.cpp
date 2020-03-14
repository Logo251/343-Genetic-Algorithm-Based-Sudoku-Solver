/*
File Name:  SudokuFactory.cpp
Author:     Logan Petersen
Date:       March 13, 2020
Purpose:    The purpose of this code is to be the function definitions for
            the function prototypes defined in SudokuFactory.h. The code allows creation
            of SudokuFactory and its use.
*/


#include "../Headers/SudokuFactory.h"

/*
Purpose:          Create a Sudoku using a reference Sudoku.
Parameters:       referencePuzzle, a Puzzle object used for creating the new Sudoku.
Preconditions:    A new Sudoku needs to be created.
Postconditions:   A new, mutated, Sudoku is created.
Return value:     Puzzle, the new Sudoku.
Functions Called: reproductionObject's createOffspring, used for creating and mutating a new Sudoku.
*/
Puzzle& SudokuFactory::createPuzzle(Puzzle& referencePuzzle) {
   return reproductionObject.makeOffspring(referencePuzzle);
}

/*
Purpose:          Create a Sudoku using a raw sudoku.
Parameters:       inputArray, an int array used for creating the new Sudoku.
Preconditions:    A new Sudoku needs to be created.
Postconditions:   A new, mutated, Sudoku is created.
Return value:     Puzzle, the new Sudoku.
Functions Called: reproductionObject's createOffspring, used for creating and mutating a new Sudoku.
*/
Puzzle& SudokuFactory::createPuzzle(int inputArray[81]) {
   //Local Variables
   //This is done because newSudoku cannot be returned.
   Sudoku newSudoku(inputArray);
   initialSudoku = newSudoku;

   return createPuzzle(initialSudoku);
}
