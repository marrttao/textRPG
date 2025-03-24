#include "item_repository.h"
#include "../../services/json/services/json_reader/json_reader.h"
#include "../../services/json/services/json_mapper/json_mapper.h"

std::map<std::string, Item> ItemRepository::load(const std::string& filename) {
    std::map<std::string, Item> items;
    std::string* json = JsonReader::read(filename);
    if (!json) return items;

    JsonMapper mapper;
    std::map<std::string, std::string> jsonMap;
    mapper.parseJson(*json, jsonMap);

    for (int i = 0; ; ++i) {
        std::string baseKey = "items[" + std::to_string(i) + "].";
        if (!jsonMap.count(baseKey + "id")) break;

        Item item;
        item.fromJson({
            {"id", jsonMap[baseKey + "id"]},
            {"name", jsonMap[baseKey + "name"]},
            {"type", jsonMap[baseKey + "type"]},
            {"damage", jsonMap[baseKey + "damage"]},
            {"heal", jsonMap[baseKey + "heal"]},
            {"weight", jsonMap[baseKey + "weight"]}
            });

        items[item.id] = item;
    }

    delete json;
    return items;
}