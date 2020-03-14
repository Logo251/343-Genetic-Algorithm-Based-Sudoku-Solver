/*
File Name:  SudokuOffspring.h
Author:     Logan Petersen
Date:       March 13, 2020
Purpose:    This is the header file for the SudokuOffspring class containing
            SudokuOffspring's interface. The purpose of this code is to provide
            the function prototypes for SudokuOffspring and connect it to its
            Interface.
*/

#pragma once

#include <ctime> //Used for the random to attempt to be random.
#include "../Interfaces/Reproduction.h"
#include "../Headers/Sudoku.h"

class SudokuOffspring : public Reproduction {
public:

   /*
   Purpose:          Construct SudokuOffspring when SudokuOffspring is created without arguments.
   Parameters:       None.
   Preconditions:    This specific SudokuOffspring object has not been instantiated.
   Postconditions:   SudokuOffspring object has been instantiated with rand seeded.
   Return value:     None.
   Functions Called: None.
   */
   SudokuOffspring();

   /*
   Purpose:          Create a mutated clone of a given Sudoku.
   Parameters:       input, the Sudoku that is cloned and mutated.
   Preconditions:    This specific SudokuOffspring object has not been instantiated.
   Postconditions:   A mutated clone of input is given back.
   Return value:     Puzzle, a Sudoku that is a mutated clone of the given one.
   Functions Called: None.
   */
   Puzzle& makeOffspring(Puzzle& input) const;
};