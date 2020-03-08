
#pragma once

#include "Puzzle.h"

class Population {
public:
   virtual void Cull() = 0;
   virtual void NewGeneration() = 0;
   virtual int BestFitness() = 0;
   virtual Puzzle* BestIndividual() = 0;
};