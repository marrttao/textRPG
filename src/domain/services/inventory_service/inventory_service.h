#ifndef INVENTORY_SERVICE_H
#define INVENTORY_SERVICE_H
#include "IInventory_service.h"
#include <fstream>
#include "../json/core/json_parser.h"
#include "../../entities/inventory/inventory.h"
#include <iostream>
class InventoryService : public IInventoryService {

public:
	void LoadInventory()  {


	}
	void SaveInventory(Inventory inventory) {
		// save inventory to txt file
		std::ofstream file;
		file.open("src/data/local/inventory/inventory.txt");
		if (!file.is_open()) {
			std::cerr << "Error: Could not open the file." << std::endl;
			return;
		}
		// all items in inventory to txt

		for (int i = 0; i < inventory.items.size(); i++) {
			file << inventory.items[i] << std::endl;
		}

		file.close();
	}

};


#endif // !INVENTORY_SERVICE_H
