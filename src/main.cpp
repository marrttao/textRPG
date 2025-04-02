#include "domain/entities/village/village.h"
#include "domain/combat_system/combat_system.h"
#include "domain/events/events_system/events_system.h"
#include "domain/entities/character/character.h"
#include "ui/providers/MainCharacter_Provider.h"
#include <iostream>

int main() {
    // Initialize main character
    MainCharacter character;
    MainCharacterProvider characterProvider(character);

    // Initialize combat system
    CombatSystem combatSystem(100, 10, 30); // Example values for enemy health, damage, and fear

    // Initialize events system
    EventsSystem eventsSystem(combatSystem, character);

    // Main game loop
    while (true) {
        std::cout << "1. Go to Village" << std::endl;
        std::cout << "2. Go to Forest" << std::endl;
        std::cout << "3. Exit Game" << std::endl;

        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1:
            eventsSystem.toVillage();
            break;
        case 2:
            eventsSystem.toForest();
            break;
        case 3:
            std::cout << "Exiting game..." << std::endl;
            return 0;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
    }

    return 0;
}
