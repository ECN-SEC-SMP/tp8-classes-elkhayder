#include "board.h"

#include <iostream>
#include <algorithm>

#include "animals/bear.h"
#include "animals/lion.h"
#include "animals/rock.h"
#include "animals/wolf.h"

Board::Board(int width, int height) : _width(width), _height(height)
{
    const int AnimalGroupsCount = 4;

    const int size = _width * _height;
    const int totalAnimalsCount = size / 4; // 25%
    const int animalPerType = totalAnimalsCount / AnimalGroupsCount;

    // Initiate buffer
    for (int group = 0; group < AnimalGroupsCount; group++)
        for (int j = 0; j < animalPerType; j++)
        {
            Animal *animal;
            int x = rand() % _width, y = rand() & _height;

            // Init animal
            switch (group)
            {
            case 0:
                animal = new Bear(*this, x, y);
                break;

            case 1:
                animal = new Lion(*this, x, y);
                break;

            case 2:
                animal = new Rock(*this, x, y);
                break;

            case 3:
                animal = new Wolf(*this, x, y);
                break;
            }

            // Push to buffer
            _buffer.push_back(animal);
        }
}

void Board::Update()
{
    // Update all animals
    for (auto animal : _buffer)
        animal->Update();
}

void Board::Battle()
{
    for (int i = 0; i < _buffer.size() - 1; i++)
    {
        auto animal = _buffer[i];

        for (int j = i + 1; j < _buffer.size(); j++)
        {
            auto opponent = _buffer[j];

            if (
                animal->IsAlive() && opponent->IsAlive() && // THEY ARE ALIVE, THEIR BATTLE WILL BE LEGENDARY (Kung-fu panda ref)

                opponent->GetX() == animal->GetX() && opponent->GetY() == animal->GetY() // They are in the same case
            )
                animal->Attack(opponent);
        }
    }
}

void Board::Draw() const
{
    const int CharactersPerBlock = 8;

    // NOT TODAY
    const std::string LineDevider(_width * (CharactersPerBlock + 1) + 1, '-');

    for (int y = 0; y < _height; y++)
    {
        std::cout << LineDevider << std::endl; // Line devider
        for (int x = 0; x < _width; x++)
        {
            std::cout << '|';
            int printed = _printAnimalsInCase(x, y);
            std::cout << std::string(CharactersPerBlock - printed * 2, ' '); // Padding
        }
        std::cout << '|' << std::endl; // End character
    }
    std::cout << LineDevider << std::endl; // End line devider
}

// Returns the number of printed characters
int Board::_printAnimalsInCase(int x, int y) const
{
    int printed = 0;

    for (auto animal : _buffer)
    {
        if (animal->GetX() != x || animal->GetY() != y || // Not in case
            !animal->IsAlive()                            // HE's DEAD
        )
            continue;

        std::cout << animal->GetEmoji();
        printed++;
    }

    return printed;
}

void Board::DebugPrint() const
{
    for (auto animal : _buffer)
    {
        animal->DebugPrint();
        std::cout << "; ";
    }
    std::cout << std::endl;
}
