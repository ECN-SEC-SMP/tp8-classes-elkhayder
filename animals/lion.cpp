#include "lion.h"

Lion::Lion(const Board &board, int x, int y) : Animal(board, x, y)
{
    _emoji = "🦁"; //'L';
}

void Lion::SetAttack()
{
    // Lion only attacks with Paper or Scissors (no hands to hold a rock apparently!)
    _attack.SetType((rand() % 2) == 0 ? ::Attack::Type::Paper : ::Attack::Type::Scissors);
}

void Lion::Move()
{
    int dX = (rand() % 2 == 0) ? 1 : -1,
        dY = (rand() % 2 == 0) ? 1 : -1;

    _moveWithLoopingAround(dX, dY);
}
