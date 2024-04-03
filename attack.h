#pragma once

#include <string>

class Attack
{
public:
    enum class Type
    {
        Rock,
        Paper,
        Scissors
    };

    Attack();                          // Set random attack
    Attack(Type type) : _type(type) {} // Set specific attack

    bool Resolve(const Attack &other) const; // Resolve attack

    // Getters
    Type GetType() const { return _type; }
    const std::string GetName() const;

    // Setters
    void SetType(Type value) { _type = value; }

private:
    Type _type;
};