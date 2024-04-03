#pragma once

#include "../animal.h"

class Rock : public Animal
{
public:
    Rock(const Board &board, int x, int y);

    void SetAttack();
    void Move();
};