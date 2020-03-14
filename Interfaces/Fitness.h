/*
File Name:  Fitness.h
Author:     Logan Petersen
Date:       March 13, 2020
Purpose:    The purpose of this code is to be the abstract class that
            must be overriden by any classes claiming to be Fitness. It
            provides the method that must be overridden to be so.
*/

#pragma once

#include "Puzzle.h"

class Fitness {
public:

   /*
   Purpose:          Return the fitness of a Puzzle.
   Parameters:       inputPuzzle, the Puzzle that is evaluated.
   Preconditions:    The class overriding this method has been instantiated.
   Postconditions:   The fitness of the Puzzle is returned with nothing changed.
   Return value:     integer, the fitness of the Sudoku.
   Functions Called: None.
   */
   virtual const int howFit(const Puzzle& inputPuzzle) const = 0;
};