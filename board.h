#pragma once

#include <vector>

class Animal;

class Board
{
public:
    Board() : Board(10, 10) {}
    Board(int width, int height);

    void Draw() const;
    void Update();
    void Battle();

    void DebugPrint() const;

    int GetWidth() const { return _width; }
    int GetHeight() const { return _height; }

private:
    int _printAnimalsInCase(int x, int y) const;

private:
    int _width = 10, _height = 10;

    std::vector<Animal *> _buffer;
};