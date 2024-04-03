#include "animal.h"

#include <iostream>

// The animals attack each other, setting _isAlive to false if either of them loses
void Animal::Attack(Animal *other)
{
    if (_attack.Resolve(other->_attack)) // This one wins
    {
        other->SetIsAlive(false);
    }
    else if (other->_attack.Resolve(_attack)) // This one loses
    {
        SetIsAlive(false);
    }
}

void Animal::_moveWithLoopingAround(int dX, int dY)
{
    int nextX = _x + dX,
        nextY = _y + dY;

    // Verifying the edges for both X and Y directions

    if (nextX >= _board.GetWidth())
        nextX -= _board.GetWidth();
    else if (nextX < 0)
        nextX += _board.GetWidth();

    if (nextY >= _board.GetHeight())
        nextY -= _board.GetHeight();
    else if (nextY < 0)
        nextY += _board.GetHeight();

    _x = nextX;
    _y = nextY;
}

void Animal::DebugPrint() const
{
    std::cout << GetEmoji() << "(" << GetX() << ", " << GetY() << ", " << (IsAlive() ? "Alive" : "Dead") << ")";
}

void Animal::Update()
{
    Move();
    SetAttack();
}