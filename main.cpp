#include <iostream>

#include <time.h>
#include <stdlib.h>

#include "board.h"

int main()
{
  srand(time(NULL));

  Board board;

  char c;
  int i = 0;

  do
  {
    i++;

    std::cout << "Round #" << i << std::endl;
    board.Update();
    board.Draw(); // Before Battle
    board.Battle();
    board.Draw(); // After battle

    std::cout << "Should continue (y/N)? ";
    std::cin >> c;

    std::cout << std::endl; // Newline

  } while (c == 'y');
}