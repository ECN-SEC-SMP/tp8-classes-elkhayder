#pragma once

#include <string>
#include "attack.h"
#include "board.h"

class Board;

class Animal
{
public:
    Animal(const Board &board, int x, int y) : _x(x), _y(y), _board(board) {}

    void Attack(Animal *other);

    virtual void SetAttack() = 0;
    virtual void Move() = 0;

    void Update();

    void DebugPrint() const;

    // Getters
    int GetX() const { return _x; }
    int GetY() const { return _y; }
    int IsAlive() const { return _isAlive; }
    const std::string &GetEmoji() const { return _emoji; }
    const ::Attack &GetAttack() const { return _attack; }

    // Setters
    void SetIsAlive(bool value) { _isAlive = value; }

protected:
    void _moveWithLoopingAround(int dX, int dY);

protected:
    std::string _emoji;
    int _x, _y;
    bool _isAlive = true;
    ::Attack _attack;
    const Board &_board;
};