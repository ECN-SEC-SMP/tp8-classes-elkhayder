#include "wolf.h"

Wolf::Wolf(const Board &board, int x, int y) : Animal(board, x, y)
{
    _emoji = "🐺"; //'W';
}

void Wolf::SetAttack()
{
    // Wolves are sneaky! they play all hands (pun intended)
    _attack.SetType(static_cast<::Attack::Type>(rand() % 3));
}

void Wolf::Move()
{
    // The wolf can move to wherever he pleases
    _x = rand() % _board.GetWidth();
    _y = rand() % _board.GetHeight();
}