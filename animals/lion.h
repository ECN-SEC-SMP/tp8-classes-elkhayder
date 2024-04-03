#pragma once

#include "../animal.h"

class Lion : public Animal
{
public:
    Lion(const Board &board, int x, int y);

    void SetAttack();
    void Move();
};