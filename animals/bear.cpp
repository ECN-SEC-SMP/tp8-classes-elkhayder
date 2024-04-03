#include "bear.h"

Bear::Bear(const Board &board, int x, int y) : Animal(board, x, y)
{
    _emoji = "🐻";                           //'B';
    _attack.SetType(Attack::Type::Scissors); // Always play scissors
}

void Bear::SetAttack()
{
    // No need to update the type, he only plays scissors
}

void Bear::Move()
{
    int xDirection = (rand() % 2 == 0) ? 1 : -1,
        yDirection = (rand() % 2 == 0) ? 1 : -1;

    int dX = (rand() % 2) + 1; // Either 1 or 2
    int dY = dX == 1 ? 2 : 1;  // The oppotite of X (Either 2 or 1)

    // Multipy directions
    dX *= xDirection;
    dY *= yDirection;

    _moveWithLoopingAround(dX, dY);
}