#ifndef BOSS_EVENTS_H
#define BOSS_EVENTS_H

#include "../../../core/json_object.h"
#include "../../item/item.h"
#include <vector>

class BossEvent : public JsonObject, public Item {
public:
    std::string name;
    std::string description;
    std::string type;
    std::string location;
    int health;
    int damage;
    int fear;

    // Реализация методов Item
    std::string getID() const override {
        return "boss_event_" + name;
    }

    std::string getName() const override {
        return name;
    }

    // Методы JsonObject
    std::vector<std::string> toJsonFields() override {
        return { "name", "description", "type", "location", "health", "damage", "fear" };
    }

    void fromJson(std::map<std::string, std::string> jsonMap) override {
        name = jsonMap.count("name") ? jsonMap["name"] : "";
        description = jsonMap.count("description") ? jsonMap["description"] : "";
        type = jsonMap.count("type") ? jsonMap["type"] : "";
        location = jsonMap.count("location") ? jsonMap["location"] : "";
		health = jsonMap.count("health") ? stoi(jsonMap["health"]) : 0;
        damage = jsonMap.count("damage") ? stoi(jsonMap["damage"]) : 0;
        fear = jsonMap.count("fear") ? stoi(jsonMap["fear"]) : 0;
    }
};

class BossEventCollection : public JsonObject {
public:
    std::vector<BossEvent> bossEvents;

    std::vector<std::string> toJsonFields() override { return {}; }

    void fromJson(std::map<std::string, std::string> jsonMap) override {
        bossEvents.clear();
        for (int i = 0; ; ++i) {
            std::string prefix = "[" + std::to_string(i) + "].";
            if (jsonMap.count(prefix + "name")) {
                BossEvent bossEvent;
                std::map<std::string, std::string> bossEventMap;

                for (const auto& field : bossEvent.toJsonFields()) {
                    std::string fullKey = prefix + field;
                    if (jsonMap.count(fullKey)) {
                        bossEventMap[field] = jsonMap[fullKey];
                    }
                }

                bossEvent.fromJson(bossEventMap);
                bossEvents.push_back(bossEvent);
            }
            else {
                break;
            }
        }
    }
};

#endif // BOSS_EVENTS_H
