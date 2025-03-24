#ifndef INVENTORY_REPO_H
#define INVENTORY_REPO_H
#include "../../entities/inventory/inventory.h"
#include "../../services/json/core/json_object.h"
#include <vector>

class InventoryRepository {
public:
	void addItem(JsonObject item);
	void removeItem(JsonObject item);
	std::vector<JsonObject> getAllItems();
};

#endif // !INVENTORY_REPO_H
