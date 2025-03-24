#ifndef ITEM_REPOSITORY_H
#define ITEM_REPOSITORY_H

#include "../../services/json/models/item/item.h"
#include <map>

class ItemRepository {
public:
    static std::map<std::string, Item> load(const std::string& filename);
};

#endif // ITEM_REPOSITORY_H