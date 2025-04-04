// potion.h
#ifndef POTION_H
#define POTION_H

#include "../../core/json_object.h"
#include "../item/item.h"
#include <vector>

class Potion : public JsonObject, public Item {
public:
    std::string name;
    std::string effect;
    int potency;
    int duration;
    std::vector<std::string> ingredients;

    // ���������� ������� Item
    std::string getID() const override {
        return "potion_" + name;
    }

    std::string getName() const override {
        return name;
    }

    // ������ JsonObject
    std::vector<std::string> toJsonFields() override {
        return { "name", "effect", "potency", "duration", "ingredients" };
    }

    void fromJson(std::map<std::string, std::string> jsonMap) override {
        name = jsonMap.count("name") ? jsonMap["name"] : "";
        effect = jsonMap.count("effect") ? jsonMap["effect"] : "";
        potency = jsonMap.count("potency") ? stoi(jsonMap["potency"]) : 0;
        duration = jsonMap.count("duration") ? stoi(jsonMap["duration"]) : 60;

        ingredients.clear();
        for (int i = 0; ; ++i) {
            std::string key = "ingredients[" + std::to_string(i) + "]";
            if (jsonMap.count(key)) {
                ingredients.push_back(jsonMap[key]);
            }
            else {
                break;
            }
        }
    }
};

class PotionCollection : public JsonObject {
public:
    std::vector<Potion> potions;

    std::vector<std::string> toJsonFields() override { return {}; }

    void fromJson(std::map<std::string, std::string> jsonMap) override {
        potions.clear();
        for (int i = 0; ; ++i) {
            std::string prefix = "[" + std::to_string(i) + "].";
            if (jsonMap.count(prefix + "name")) {
                Potion potion;
                std::map<std::string, std::string> potionMap;

                for (const auto& field : potion.toJsonFields()) {
                    std::string fullKey = prefix + field;
                    if (jsonMap.count(fullKey)) {
                        potionMap[field] = jsonMap[fullKey];
                    }
                }

                potion.fromJson(potionMap);
                potions.push_back(potion);
            }
            else {
                break;
            }
        }
    }
};

#endif // POTION_H