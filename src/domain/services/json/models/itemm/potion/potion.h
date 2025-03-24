#ifndef POTION_H
#define POTION_H
#include "../../../core/json_object.h"
#include <string>

class Potion : public JsonObject {
public:
	std::string id;
	std::string name;
	std::string type;
	int heal = 0;
	int strength = 0;
	int armour = 0;
	int rage = 0;
	int duration = 0;
	float weight = 0.0f;

	std::vector<std::string> toJsonFields() override;
	void fromJson(std::map<std::string, std::string> jsonMap) override;
};

#endif // !POTION_H
