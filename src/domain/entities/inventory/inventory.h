#ifndef INVENTORY_H
#define INVENTORY_H

#include "../../services/json/core/json_object.h"
#include <vector>
#include <string>
#include <map>
#include "../../repositories/inventory_repository/inventory_repository.h"
using namespace std;

class Inventory : public JsonObject, public InventoryRepository {
public:

    vector<string> items;
    vector<string> toJsonFields() override {
        return { "items" };
    }

    void fromJson(map<string, string> jsonMap) override {
        items.clear();
        for (int i = 0; ; ++i) {
            string key = "items[" + to_string(i) + "]";
            if (jsonMap.count(key)) {
                items.push_back(jsonMap[key]);
            }
            else {
                break;
            }
        }
    }

    std::string to_json() const {
        std::string json = "[";
        for (size_t i = 0; i < items.size(); ++i) {
            json += "\"" + items[i] + "\"";
            if (i < items.size() - 1) {
                json += ",";
            }
        }
        json += "]";
        return json;
    }
};

#endif // INVENTORY_H
