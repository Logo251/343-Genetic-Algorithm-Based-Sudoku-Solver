/*
File Name:  Puzzle.h
Author:     Logan Petersen
Date:       March 13, 2020
Purpose:    The purpose of this code is to be the abstract class that
            must be overriden by any classes claiming to be Puzzle. It
            provides the methods that must be overridden to be so.
*/

#pragma once

#include <string> //used for string.
#include <iostream> //used for reading and printing.

class Puzzle {
public:

   /*
   Purpose:          Give a string to be printed by ostream.
   Parameters:       None.
   Preconditions:    This Puzzle object has been instantiated, operator<< is called, and the interface is implemented properly.
   Postconditions:   A string is displayed through operator<<.
   Return value:     string, used to give a string to be displayed.
   Functions Called: None.
   */
   virtual const std::string toString() const = 0;

   /*
   Purpose:          Be a helper function for inputting characters into Puzzle.
   Parameters:       input, the istream.
                     Used to input characters.
   Preconditions:    This Puzzle object has been instantiated, operator>> is called, and the interface is implemented properly.
   Postconditions:   This specific Puzzle object has inputPuzzle's given values.
   Return value:     None.
   Functions Called: None.
   */
   virtual const std::istream& inputPuzzle(std::istream& input) = 0;
};