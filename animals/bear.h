#pragma once

#include "../animal.h"

class Bear : public Animal
{
public:
    Bear(const Board &board, int x, int y);

    void SetAttack();
    void Move();
};