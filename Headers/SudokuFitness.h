/*
File Name:  SudokuFitness.h
Author:     Logan Petersen
Date:       March 13, 2020
Purpose:    This is the header file for the SudokuFitness class containing SudokuFitness's interface.
            The purpose of this code is to provide the function prototypes for
            SudokuFitness as well as demonstrate its interface relationship.
*/

#pragma once

#include "../Interfaces/Fitness.h"
#include "../Headers/Sudoku.h"

class SudokuFitness : public Fitness {
public:

    /*
    Purpose:          Return the fitness of a Sudoku.
    Parameters:       inputPuzzle, the sudoku that is evaluated.
    Preconditions:    This specific SudokuFitness object has not been instantiated.
    Postconditions:   The fitness of the Sudoku is returned with nothing changed.
    Return value:     integer, the fitness of the Sudoku.
    Functions Called: evaluateRows, evaluateColumns, evaluateQuadrants, used to better
                      evaluate seperate parts of the Sudoku.
    */
   const int howFit(const Puzzle& inputPuzzle) const;
private:

   /*
   Purpose:          Return the number of issues in the rows of the sudoku.
   Parameters:       sudoku, the sudoku that is evaluated.
   Preconditions:    This specific SudokuFitness object has not been instantiated.
   Postconditions:   The fitness of the Sudoku's rows is returned with nothing changed.
   Return value:     integer, the fitness of the Sudoku's rows.
   Functions Called: None.
   */
  const int evaluateRows(const Sudoku& sudoku) const;

   /*
   Purpose:          Return the number of issues in the columns of the sudoku.
   Parameters:       sudoku, the sudoku that is evaluated.
   Preconditions:    This specific SudokuFitness object has not been instantiated.
   Postconditions:   The fitness of the Sudoku's columns is returned with nothing changed.
   Return value:     integer, the fitness of the Sudoku's columns..
   Functions Called: None.
   */
  const int evaluateColumns(const Sudoku& sudoku) const;

  /*
   Purpose:          Return the number of issues in the quadrants of the sudoku.
   Parameters:       sudoku, the sudoku that is evaluated.
   Preconditions:    This specific SudokuFitness object has not been instantiated.
   Postconditions:   The fitness of the Sudoku's quadrants is returned with nothing changed.
   Return value:     integer, the fitness of the Sudoku's quadrants.
   Functions Called: None.
   */
  const int evaluateQuadrants(const Sudoku& sudoku) const;
};