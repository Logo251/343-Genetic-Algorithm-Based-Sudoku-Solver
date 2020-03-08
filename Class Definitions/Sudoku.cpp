#include "../Headers/Sudoku.h"

std::ostream& operator<<(std::ostream& out, const Puzzle& inputPuzzle) {
   //Local Variables
   int progressThroughX = 0; //Progress through the x axis of the sudoku puzzle being printed.
   int progressThroughY = 0; //Progress through the y axis of the sudoku puzzle being printed.

   for (int i = 0; i < 16; i++) {
      for (int j = 0; j < 12; j++) {
         //Handles the '+' and '-'.
         if (i == 0 || i == 4 || i == 8 || i == 12) {
            if (j == 0 || j == 8 || j == 16) {
               out << '+';
            }
            else {
               out << '-';
            }
         }

         //Handles the spaces.
         else if (j % 2 == 0) {
            out << ' ';
         }

         //Handles the actual numbers.
         else {
            out << inputPuzzle.sudoku[progressThroughX][progressThroughY];
            if (progressThroughX == 9) {
               progressThroughX = 0;
               progressThroughY++;
            }
            else {
               progressThroughX++;
            }
         }
         
      }
   }

   return out;
}

std::istream& operator>>(std::istream& input, const Puzzle& inputPuzzle) {
   int progressThroughX = 0; //Progress through the x axis of the sudoku puzzle.
   int progressThroughY = 0; //Progress through the y axis of the sudoku puzzle.
   char inputChar;
   
   while (input.get(inputChar)) {
      inputPuzzle.sudoku[progressThroughX][progressThroughY] = (int)inputChar - 48; //48 converts ascii numbers to integer.
      if (progressThroughX == 9) {
         progressThroughX = 0;
         progressThroughY++;
      }
      else {
         progressThroughX++;
      }
   }

   return input;
}
