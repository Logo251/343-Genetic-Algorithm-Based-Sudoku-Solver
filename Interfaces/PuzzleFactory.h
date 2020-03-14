/*
File Name:  PuzzleFactory.h
Author:     Logan Petersen
Date:       March 13, 2020
Purpose:    The purpose of this code is to be the abstract class that
            must be overriden by any classes claiming to be a PuzzleFactory.
            It provides the method that must be overridden to be so.
*/

#pragma once

#include "Puzzle.h"


class PuzzleFactory {
public:

   /*
   Purpose:          Create a Puzzle using a reference Puzzle.
   Parameters:       referencePuzzle, a Puzzle used for creating the new Puzzle.
   Preconditions:    A new Puzzle needs to be created by a class overriding this interface.
   Postconditions:   A new, mutated, Puzzle is created.
   Return value:     Puzzle, the new Puzzle.
   Functions Called: None.
   */
   virtual Puzzle& createPuzzle(Puzzle& referencePuzzle) = 0;
};