
#pragma once

#include "Puzzle.h"

class Population {
public:
   virtual void Cull() = 0;
   virtual void NewGeneration() = 0;
   virtual int BestFitness() = 0;
   virtual const Puzzle* BestIndividual() const = 0;  //TODO: Ensure that returns of the actual item prevents modification / const for methods that aren't changing anything.
};