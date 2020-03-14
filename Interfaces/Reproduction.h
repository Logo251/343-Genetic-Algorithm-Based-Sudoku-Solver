/*
File Name:  Reproduction.h
Author:     Logan Petersen
Date:       March 13, 2020
Purpose:    The purpose of this code is to be the abstract class that
            must be overriden by any classes claiming to a Reproduction class.
            It provides the method that must be overridden to be so.
*/

#pragma once

#include "Puzzle.h"

class Reproduction {
public:

   /*
   Purpose:          Create a mutated clone of a given Puzzle.
   Parameters:       input, the Puzzle that is cloned and mutated.
   Preconditions:    This specific SudokuOffspring object implementing this interface has not been instantiated.
   Postconditions:   A mutated clone of input is given back.
   Return value:     Puzzle, a Puzzle that is a mutated clone of the given one.
   Functions Called: None.
   */
   virtual Puzzle& makeOffspring(Puzzle& input) const = 0;
};