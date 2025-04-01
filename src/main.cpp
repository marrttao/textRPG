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

    // inventory test
	Inventory inventory;
	inventory.addItem("key1:value1");
	inventory.addItem("key2:value2");
	inventory.addItem("key3:value3");
	inventory.addItem("key4:value4");
	inventory.addItem("key5:value5");
	// Save inventory
	InventoryService inventoryService;
	inventoryService.SaveInventory(inventory);
	// Load inventory
	inventoryService.LoadInventory();
	// Get all items
	std::vector<std::pair<std::string, std::string>> items = inventory.getAllItems();
	for (const auto& item : items) {
		std::cout << item.first << " " << item.second << std::endl;
	}


    SwordCollection swords;
    JsonParser parser;
    parser.parse(swords, PATH_SWORDS, ParsingPath::FILE_FORMAT);
    // cout all swords
	for (auto sword : swords.swords) {
		std::cout << sword.name << " " << sword.damage << std::endl;
	}


	

    // to forest
    eventsProvider.IsInForest = true; // Set IsInForest to true

    std::cout << "Program started" << std::endl;
    std::cout << "Calling Event method" << std::endl;
    eventsProvider.Event(); // Corrected method call
    std::cout << "Program ended" << std::endl;
    return 0;
}

