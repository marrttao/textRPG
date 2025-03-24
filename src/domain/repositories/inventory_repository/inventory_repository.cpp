#include "inventory_repository.h"
#include <vector>
#include <fstream>
#include "../../services/json/core/json_parser.h"
#include "../../services/json/core/json_object.h"
#define FILE_PATH "src/domain/services/json/assets/json/inventory.json"

void InventoryRepository::addItem(JsonObject item) {
	// add item to inventory.json
	std::vector<JsonObject> items;
	std::ifstream file(FILE_PATH);
	if (file.is_open()) {
		JsonParser parser;
		items = parser.parse(file);
		file.close();
	}

	items.push_back(item);

	std::ofstream outFile(FILE_PATH);
	if (outFile.is_open()) {
		JsonParser parser;
		parser.serialize(outFile, items);
		outFile.close();
	}
}

void InventoryRepository::removeItem(JsonObject item) {
	// remove item from inventory.json
	std::vector<JsonObject> items;
	std::ifstream file(FILE_PATH);
	if (file.is_open()) {
		JsonParser parser;
		items = parser.parse(file);
		file.close();
	}

	items.erase(std::remove_if(items.begin(), items.end(), [&](JsonObject const& i) {
		return i == item; // Assuming JsonObject has an overloaded operator==
		}), items.end());

	std::ofstream outFile(FILE_PATH);
	if (outFile.is_open()) {
		JsonParser parser;
		parser.serialize(outFile, items);
		outFile.close();
	}
}

std::vector<JsonObject> InventoryRepository::getAllItems() {
	// get all items from inventory.json
	std::vector<JsonObject> items;
	std::ifstream file(FILE_PATH);
	if (file.is_open()) {
		JsonParser parser;
		items = parser.parse(file);
		file.close();
	}
	return items;
}
