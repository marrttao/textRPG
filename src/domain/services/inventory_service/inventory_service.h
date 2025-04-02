#ifndef INVENTORY_SERVICE_H
#define INVENTORY_SERVICE_H

#include "IInventory_service.h"
#include <fstream>
#include "../json/core/json_parser.h"
#include "../../entities/inventory/inventory.h"
#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
#include "../json/models/potions/potions.h"
#include "../../entities/character/character.h"

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

    void useItem(const std::string& item, Inventory& inventory, MainCharacter& character) {
        // find item in inventory
        std::vector<std::pair<std::string, std::string>> items = inventory.getAllItems();
        for (const auto& i : items) {
            if (i.first == item) {
                // use item
                std::cout << "Item used: " << i.first << std::endl;
                // if item not potion cout error
                if (i.second != "potion") {
                    std::cout << "Error: Item is not a potion." << std::endl;
                }
                else {
                    std::cout << "Item used: " << i.first << std::endl;

                    // parse potions collection
                    PotionCollection potions;
                    JsonParser parser;
                    parser.parse(potions, "src/domain/services/json/assets/json/potions.json", ParsingPath::FILE_FORMAT);
                    inventory.removeItem(i.first);
					SaveInventory(inventory);
                    // find potion in collection
                    for (auto& potion : potions.potions) {
                        if (potion.name == i.first) {
                            // character health damage strength + potion effect
                            std::cout << "Potion used: " << potion.name << std::endl;

                            // Apply potion effects
                            character.health += potion.effect.at("health");
							if (character.health > 100 + character.strength * 2.5) {
								character.health = 100 + character.strength * 2.5;
							}
                            character.attack += potion.effect.at("damage");
                            character.strength += potion.effect.at("strength");

                            // Start a thread to remove the effects after the duration
                            std::thread([&, potion]() {
                                std::this_thread::sleep_for(std::chrono::seconds(potion.duration));
                                std::lock_guard<std::mutex> lock(mutex_);
                                character.health -= potion.effect.at("health");
                                character.attack -= potion.effect.at("damage");
                                character.strength -= potion.effect.at("strength");
                                std::cout << "Potion effects worn off: " << potion.name << std::endl;
                                }).detach();
                        }
                    }

                    // remove item from inventory
                    inventory.removeItem(i.first);
                }
            }
        }
    }
    void printInventory(Inventory& inventory) {

		// Get all items
		std::vector<std::pair<std::string, std::string>> items = inventory.getAllItems();
        for (const auto& item : items) {
            std::cout << item.first << " " << item.second << std::endl;
        }

    }

private:
    std::mutex mutex_;
};

#endif // INVENTORY_SERVICE_H
