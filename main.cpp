#include <iostream>
#include <string>
#include "CharacterCreator.h"

int main() {
    std::string playerName;

    std::cout << "Welcome to the adventure of a lifetime, stranger!\n";
    std::cout << "Before we begin, who are you and what is your name?\n";

    std::getline(std::cin, playerName); // safer than cin >>

    std::cout << "Nice to meet you, " << playerName << "!\n";

    // Create character
    Character hero = createCharacter(playerName);

    return 0;
}
