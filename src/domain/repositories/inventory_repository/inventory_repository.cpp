#include "inventory_repository.h"
#include <iostream>
void InventoryRepository::addItem(const std::string& item) {
	// add item in txt file
	std::ofstream file;
	file.open("src/data/local/inventory/inventory.txt", std::ios::app);
	if (!file.is_open()) {
		std::cerr << "Error: Could not open the file." << std::endl;
		return;
	}
	file << item << std::endl;
	file.close();


}

