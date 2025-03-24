// item.cpp
#include "sword.h"

std::vector<std::string> Sword::toJsonFields() {
    return { "id", "name", "type", "damage", "weight" };
    
}

void Sword::fromJson(std::map<std::string, std::string> jsonMap) {
    
	id = jsonMap["id"];
	name = jsonMap["name"];
	type = jsonMap["type"];
	damage = std::stoi(jsonMap["damage"]);
	weight = std::stof(jsonMap["weight"]);


}