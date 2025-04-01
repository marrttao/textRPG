#include "inventory_repository.h"

void InventoryRepository::addItem(const std::string& item) {
    // Assuming the item is a string in the format "key:value"
    size_t delimiterPos = item.find(':');
    if (delimiterPos != std::string::npos) {
        std::string first = item.substr(0, delimiterPos);
        std::string second = item.substr(delimiterPos + 1);
        items.push_back(std::make_pair(first, second));
    }
}

void InventoryRepository::removeItem(const std::string& item) {
    // Implementation for removing an item
}

std::vector<std::pair<std::string, std::string>> InventoryRepository::getAllItems() const {
    return items;
}
