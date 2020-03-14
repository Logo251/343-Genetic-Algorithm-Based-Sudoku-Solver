/*
File Name:  Population.h
Author:     Logan Petersen
Date:       March 13, 2020
Purpose:    The purpose of this code is to be the abstract class that
            must be overriden by any classes claiming to be a Population
            class. It provides the method that must be overriden to be so.
*/

#pragma once

#include "Puzzle.h"

class Population {
public:

   /*
   Purpose:          Deletes the worst 90% of the entire generation.
   Parameters:       None.
   Preconditions:    This object overriding this interface has been instantiated.
   Postconditions:   The population is only 10% of its previous size.
   Return value:     None.
   Functions Called: None.
   */
   virtual void Cull() = 0;

      /*
   Purpose:          Regenerates the missing population.
   Parameters:       None.
   Preconditions:    This specific object overriding this class has been instantiated.
   Postconditions:   The population is at 100% of its size.
   Return value:     None.
   Functions Called: None.
   */
   virtual void NewGeneration() = 0;

   /*
   Purpose:          Gives the most fit function's fitness.
   Parameters:       None.
   Preconditions:    This specific object overriding this class has been instantiated and contains a Puzzle.
   Postconditions:   Nothing has been changed.
   Return value:     int, used to give the most fit object's fitness.
   Functions Called: None.
   */
   virtual const int BestFitness() const = 0;

   /*
   Purpose:          Gives the most fit function.
   Parameters:       None.
   Preconditions:    This specific object overriding this class has been instantiated and contains a Puzzle.
   Postconditions:   Nothing has been changed.
   Return value:     Puzzle, used to give a const reference to the Puzzle.
   Functions Called: None.
   */
   virtual const Puzzle& BestIndividual() const = 0;
};