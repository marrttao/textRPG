#ifndef INVENTORY_SERVICE_H
#define INVENTORY_SERVICE_H
#include "IInventory_service.h"
#include "../../repositories/item_repository/item_repository.h"
#include "../../entities/inventory/inventory.h"
#include <fstream>
class InventoryService:IInventoryService {
public:

	void useItem(Item item) override {}
	Item getItemInfo(Item item) override {
		// all info about item (damage name and other) from json
		return ExampleRepository::load(FILE_PATH)[item.id];


	}

	
	std::vector<Item> LoadInventory() {
		// Загрузка предметов
		items = ExampleRepository::load(FILE_PATH);

		if (items.empty()) {
			std::cerr << "Error: No items loaded!" << std::endl;
		}
		return items;
	}

	bool SaveInventory() {
		std::vector<std::map<std::string, std::string>> jsonItems;
		for (auto& item : items) {
			jsonItems.push_back(item.toJsonFields());
		}
		std::string jsonString = JsonParser::serialize(jsonItems);
		std::ofstream outFile(FILE_PATH);
		if (!outFile) {
			std::cerr << "Error: Could not open file for writing!" << std::endl;
			return false;
		}
		outFile << jsonString;
		outFile.close();
		return true;
	}
};

#endif // !INVENTORY_SERVICE_H
