#pragma once

#include "../animal.h"

class Wolf : public Animal
{
public:
    Wolf(const Board &board, int x, int y);

    void SetAttack();
    void Move();
};