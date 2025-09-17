#include "CharacterCreator.h"
#include <iostream>
#include <limits> // for std::numeric_limits

// Helper function to safely read a stat with max remaining
int readStat(const std::string& statName, int maxRemaining) {
    int value;
    while (true) {
        std::cout << "Enter " << statName << " (1-20, remaining points: " << maxRemaining << "): ";
        if (std::cin >> value) {
            if (value >= 1 && value <= 20) {
                if (value > maxRemaining) {
                    value = maxRemaining;
                    std::cout << statName << " capped to " << value << " to respect max total.\n";
                }
                return value;
            }
        }
        // Invalid input handling
        std::cout << "Invalid input! Please enter a number between 1 and 20.\n";
        std::cin.clear(); // clear fail state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
    }
}

// Main character creation function
Character createCharacter(const std::string& name) {
    Character player;
    player.name = name;
    player.strength = 0;
    player.agility = 0;
    player.intelligence = 0;

    const int MAX_TOTAL = 20;
    int totalSpent = 0;

    std::cout << "\n--- Character Creation ---\n";
    std::cout << "You can spend up to " << MAX_TOTAL << " points across Strength, Agility, and Intelligence.\n";

    // Strength
    player.strength = readStat("Strength", MAX_TOTAL);
    totalSpent += player.strength;

    // Agility
    if (totalSpent < MAX_TOTAL) {
        player.agility = readStat("Agility", MAX_TOTAL - totalSpent);
        totalSpent += player.agility;
    }

    // Intelligence
    if (totalSpent < MAX_TOTAL) {
        player.intelligence = readStat("Intelligence", MAX_TOTAL - totalSpent);
        totalSpent += player.intelligence;
    }

    // Summary
    std::cout << "\nCharacter successfully created!\n";
    std::cout << "Name: " << player.name << "\n";
    std::cout << "Strength: " << player.strength << "\n";
    std::cout << "Agility: " << player.agility << "\n";
    std::cout << "Intelligence: " << player.intelligence << "\n";

    return player;
}
