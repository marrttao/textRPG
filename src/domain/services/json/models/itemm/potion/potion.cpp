#include "potion.h"

std::vector<std::string> Potion::toJsonFields() {
	return { "id", "name", "type", "heal", "strength", "armour", "rage", "duration", "weight" };
}

void Potion::fromJson(std::map<std::string, std::string> jsonMap) {
	id = jsonMap["id"];
	name = jsonMap["name"];
	type = jsonMap["type"];
	if (jsonMap.find("heal") != jsonMap.end()) heal = std::stoi(jsonMap["heal"]);
	if (jsonMap.find("strength") != jsonMap.end()) strength = std::stoi(jsonMap["strength"]);
	if (jsonMap.find("armour") != jsonMap.end()) armour = std::stoi(jsonMap["armour"]);
	if (jsonMap.find("rage") != jsonMap.end()) rage = std::stoi(jsonMap["rage"]);
	if (jsonMap.find("duration") != jsonMap.end()) duration = std::stoi(jsonMap["duration"]);
	if (jsonMap.find("weight") != jsonMap.end()) weight = std::stof(jsonMap["weight"]);
}
