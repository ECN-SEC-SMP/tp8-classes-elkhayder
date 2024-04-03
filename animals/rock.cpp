#include "rock.h"

Rock::Rock(const Board &board, int x, int y) : Animal(board, x, y)
{
    _emoji = "🪨";                       //'R';
    _attack.SetType(Attack::Type::Rock); // Rocks only play rocks, Duuuh!
}

void Rock::SetAttack()
{
    // No need to update the type, he only plays rocks
}

void Rock::Move()
{
    // Rocks do not move, duuuh!
}