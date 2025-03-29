#ifndef INVENTORY_REPOSITORY_H
#define INVENTORY_REPOSITORY_H
#include <string>
#include <fstream>

class InventoryRepository {
public:
	void addItem(const std::string& item);
	void removeItem(const std::string& item);
	void getAllItems();
};

#endif // !INVENTORY_REPOSITORY_H
