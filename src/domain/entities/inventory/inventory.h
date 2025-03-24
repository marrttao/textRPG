#ifndef INVENTORY_H
#define INVENTORY_H
#include <vector>
#include <fstream>

#include "../../services/json/core/json_parser.h"
#include "../../services/json/core/json_object.h"
#include "../../services/json/models/items/potions.h"
#include "../../services/json/models/items/swords.h"
#include "../../repositories/item_repository/item_repository.h"
#define FILE_PATH "src/domain/services/json/assets/json/example.json"

class Inventory {
protected:
    // load inventory from json
    std::vector<JsonObject> items;
public:
    
};

#endif // INVENTORY_H
