// item.h
#ifndef ITEM_H
#define ITEM_H

#include "../../../core/json_object.h"
#include <string>

class Sword : public JsonObject {
public:
    std::string id;
    std::string name;
    std::string type;
    int damage = 0;
    float weight = 0.0f;

    std::vector<std::string> toJsonFields() override;
    void fromJson(std::map<std::string, std::string> jsonMap) override;
};

#endif // ITEM_H

