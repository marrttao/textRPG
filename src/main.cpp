#include "domain/services/json/core/json_parser.h"
#include "domain/services/json/repositories/sword_repository.h" // Подключите репозиторий мечей
#include "domain/services/json/repositories/potion_repository.h"
#include "domain/repositories/inventory_repository/inventory_repository.h"
#include "domain/services/inventory_service/inventory_service.h"
#define FILE_PATH "src/domain/services/json/assets/json/swords.json"
#define FILE_PATHH "src/domain/services/json/assets/json/potions.json"
int main() {
    SwordCollection collection;
    JsonParser parser;
    parser.parse(collection, FILE_PATH, FILE_FORMAT);

    // Проверка наличия хотя бы 3 мечей
    if(collection.swords.size() >= 3) {
        // Получаем третий меч (индексация с 0)
        const Sword& thirdSword = collection.swords[2];
        
        // Выводим только третий меч через репозиторий
        SwordRepository::print(thirdSword);
    } else {
        std::cerr << "Error: Collection contains only " 
                  << collection.swords.size() 
                  << " swords\n";
    }

	PotionCollection collection1;
	JsonParser parser1;
	parser1.parse(collection1, FILE_PATHH, FILE_FORMAT);

	if (collection1.potions.size() >= 2) {
		const Potion& thirdPotion = collection1.potions[1];
		PotionRepository::print(thirdPotion);
	}
	else {
		std::cerr << "Error: Collection contains only "
			<< collection1.potions.size()
			<< " potions\n";
	}

    cout << endl << endl;

    InventoryService inventoryService;
    InventoryRepository inventoryRepository; // Use the concrete repository
    Inventory inventory;
    // Load the inventory
    inventoryService.LoadInventory();

    // Add an item to the inventory
    std::string newItem = "New Item";
    inventoryRepository.addItem(newItem);
    inventoryService.LoadInventory();

    // Save the updated inventory
    inventoryService.SaveInventory(inventory);

    std::cout << "Inventory updated successfully." << std::endl;



    return 0;
}