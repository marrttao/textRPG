#ifndef INVENTORY_REPOSITORY_H
#define INVENTORY_REPOSITORY_H

#include <string>
#include <vector>
#include <utility> // for std::pair

class InventoryRepository {
public:
    void addItem(const std::string& item);
    void removeItem(const std::string& item);
    std::vector<std::pair<std::string, std::string>> getAllItems() const;

private:
    std::vector<std::pair<std::string, std::string>> items;
};

#endif // INVENTORY_REPOSITORY_H
