#include "domain/services/json/core/json_parser.h"
#include "domain/services/json/repositories/sword_repository.h"
#include "domain/services/json/repositories/potion_repository.h"
#include "domain/repositories/inventory_repository/inventory_repository.h"
#include "domain/services/inventory_service/inventory_service.h"
#include "ui/providers/events_provider.h"
#include "domain/combat_system/combat_system.h"
#include "ui/providers/MainCharacter_Provider.h"
#define FILE_PATH "src/domain/services/json/assets/json/swords.json"
#define FILE_PATHH "src/domain/services/json/assets/json/potions.json"

int main() {
    // combat system
    CombatSystem combatSystem(100, 10, 0);
    MainCharacter mainCharacter; // Create MainCharacter instance
    MainCharacterProvider mainCharacterProvider(mainCharacter); // Pass by reference
    EventsProvider eventsProvider(combatSystem, mainCharacterProvider.character);

    // to forest
    eventsProvider.IsInForest = true; // Set IsInForest to true

    std::cout << "Program started" << std::endl;
    std::cout << "Calling Event method" << std::endl;
    eventsProvider.Event(); // Corrected method call
    std::cout << "Program ended" << std::endl;
    return 0;
}

