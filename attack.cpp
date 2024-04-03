#include "attack.h"

Attack::Attack()
{
    // Generate a random integer between 0 and 2, and cast it to type
    _type = static_cast<Type>(rand() % 3);
}

const std::string Attack::GetName() const
{

    switch (_type)
    {
    case Type::Paper:
        return "Paper";
    case Type::Rock:
        return "Rock";
    case Type::Scissors:
        return "Scissors";
    }
}

// Resolve attack.
// Returns true if this attack is more powerful than the other
bool Attack::Resolve(const Attack &other) const
{
    switch (_type)
    {
    case Type::Rock:
        return other._type == Type::Scissors; // Rock wins against Scissors
    case Type::Paper:
        return other._type == Type::Rock; // Scissors wins against Rock
    case Type::Scissors:
        return other._type == Type::Paper; // Scissors wins against paper
    }
}
