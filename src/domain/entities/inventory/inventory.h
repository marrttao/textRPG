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

    vector < pair<string, string>> items;
    vector<string> toJsonFields() override {
        return { "items" };
    }

    void fromJson(map<string, string> jsonMap) override {
        items.clear();
        for (int i = 0; ; ++i) {
            string key = "items[" + to_string(i) + "]";
            if (jsonMap.count(key)) {
                // Assuming the value in jsonMap is a string in the format "key:value"
                size_t delimiterPos = jsonMap[key].find(':');
                if (delimiterPos != string::npos) {
                    string first = jsonMap[key].substr(0, delimiterPos);
                    string second = jsonMap[key].substr(delimiterPos + 1);
                    items.push_back(make_pair(first, second));
                }
            }
            else {
                break;
            }
        }
    }

    std::string to_json() const {
        std::string json = "[";
        for (size_t i = 0; i < items.size(); ++i) {
            json += "{\"" + items[i].first + "\":\"" + items[i].second + "\"}";
            if (i < items.size() - 1) {
                json += ",";
            }
        }
        json += "]";
        return json;
    }

};

#endif // INVENTORY_H
