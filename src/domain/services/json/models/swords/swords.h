#ifndef SWORDS_H
#define SWORDS_H

#include "../../core/json_object.h"
#include "../item/item.h"  // Правильное подключение заголовка
#include <vector>

class Sword : public JsonObject, public Item {
public:
    std::string name;
    int damage;
    int durability;
    std::string type;
    std::vector<std::string> attributes;

    // Реализация методов Item
    std::string getID() const override {
        return "sword_" + name; // Пример генерации ID
    }

    std::string getName() const override {
        return name;
    }

    // Методы JsonObject
    std::vector<std::string> toJsonFields() override {
        return { "name", "damage", "durability", "type", "attributes" };
    }

    void fromJson(std::map<std::string, std::string> jsonMap) override {
        name = jsonMap.count("name") ? jsonMap["name"] : "";
        damage = jsonMap.count("damage") ? stoi(jsonMap["damage"]) : 0;
        durability = jsonMap.count("durability") ? stoi(jsonMap["durability"]) : 100;
        type = jsonMap.count("type") ? jsonMap["type"] : "standard";

        attributes.clear();
        for (int i = 0; ; ++i) {
            std::string key = "attributes[" + std::to_string(i) + "]";
            if (jsonMap.count(key)) {
                attributes.push_back(jsonMap[key]);
            }
            else {
                break;
            }
        }
    }
};

class SwordCollection : public JsonObject {
public:
    std::vector<Sword> swords;

    std::vector<std::string> toJsonFields() override { return {}; }

    void fromJson(std::map<std::string, std::string> jsonMap) override {
        swords.clear();
        for (int i = 0; ; ++i) {
            std::string prefix = "[" + std::to_string(i) + "].";
            if (jsonMap.count(prefix + "name")) {
                Sword sword;
                std::map<std::string, std::string> swordMap;

                for (const auto& field : sword.toJsonFields()) {
                    std::string fullKey = prefix + field;
                    if (jsonMap.count(fullKey)) {
                        swordMap[field] = jsonMap[fullKey];
                    }
                }

                sword.fromJson(swordMap);
                swords.push_back(sword);
            }
            else {
                break;
            }
        }
    }
};
#endif // SWORDS_H