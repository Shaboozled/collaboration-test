#ifndef CHARACTERCREATOR_H
#define CHARACTERCREATOR_H

#include <string>

struct Character {
    std::string name;
    int strength;
    int agility;
    int intelligence;
};

// Function declaration
Character createCharacter(const std::string& name);

#endif
