#ifndef DEFAULT_EVENTS_H
#define DEFAULT_EVENTS_H

#include "../../../core/json_object.h"
#include "../../item/item.h"
#include <vector>

class DefaultEvent : public JsonObject, public Item {
public:
    int id;
    std::string name;
    std::string description;
    std::string type;
    std::string location;
    int health;
    int damage;
    int fear;

    // Реализация методов Item
    std::string getID() const override {
        return "default_event_" + std::to_string(id);
    }

    std::string getName() const override {
        return name;
    }

    // Методы JsonObject
    std::vector<std::string> toJsonFields() override {
        return { "id", "name", "description", "type", "location", "health", "damage", "fear" };
    }

    void fromJson(std::map<std::string, std::string> jsonMap) override {
        id = jsonMap.count("id") ? stoi(jsonMap["id"]) : 0;
        name = jsonMap.count("name") ? jsonMap["name"] : "";
        description = jsonMap.count("description") ? jsonMap["description"] : "";
        type = jsonMap.count("type") ? jsonMap["type"] : "";
        location = jsonMap.count("location") ? jsonMap["location"] : "";
		health = jsonMap.count("health") ? stoi(jsonMap["health"]) : 0;
        damage = jsonMap.count("damage") ? stoi(jsonMap["damage"]) : 0;
        fear = jsonMap.count("fear") ? stoi(jsonMap["fear"]) : 0;
    }
};

class DefaultEventCollection : public JsonObject {
public:
    std::vector<DefaultEvent> defaultEvents;

    std::vector<std::string> toJsonFields() override { return {}; }

    void fromJson(std::map<std::string, std::string> jsonMap) override {
        defaultEvents.clear();
        for (int i = 0; ; ++i) {
            std::string prefix = "[" + std::to_string(i) + "].";
            if (jsonMap.count(prefix + "id")) {
                DefaultEvent defaultEvent;
                std::map<std::string, std::string> defaultEventMap;

                for (const auto& field : defaultEvent.toJsonFields()) {
                    std::string fullKey = prefix + field;
                    if (jsonMap.count(fullKey)) {
                        defaultEventMap[field] = jsonMap[fullKey];
                    }
                }

                defaultEvent.fromJson(defaultEventMap);
                defaultEvents.push_back(defaultEvent);
            }
            else {
                break;
            }
        }
    }
};

#endif // DEFAULT_EVENTS_H
