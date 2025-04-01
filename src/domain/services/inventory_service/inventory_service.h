#ifndef INVENTORY_SERVICE_H
#define INVENTORY_SERVICE_H

#include "IInventory_service.h"
#include <fstream>
#include "../json/core/json_parser.h"
#include "../../entities/inventory/inventory.h"
#include <iostream>

class InventoryService : public IInventoryService {
public:
    void LoadInventory() {
        // Load inventory from txt file
        std::ifstream file("src/data/local/inventory/inventory.txt");
        if (!file.is_open()) {
            std::cerr << "Error: Could not open the file." << std::endl;
            return;
        }

        Inventory inventory;
        std::string line;
        while (std::getline(file, line)) {
            inventory.addItem(line);
        }

        file.close();
    }

    void SaveInventory(const Inventory& inventory) {
        // Save inventory to txt file
        std::ofstream file("src/data/local/inventory/inventory.txt");
        if (!file.is_open()) {
            std::cerr << "Error: Could not open the file." << std::endl;
            return;
        }

        // Save all items in inventory to txt
        for (const auto& item : inventory.getAllItems()) {
            file << item.first << ":" << item.second << std::endl;
        }

        file.close();
    }
};

#endif // INVENTORY_SERVICE_H
