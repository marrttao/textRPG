#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include "../../services/json/models/item/item.h"
class MainCharacter {
public:
	std::string name;
	short level;
	short health;
	short mana;
	short strength;
	short dexterity;
	short intelligence;
	short luck;
	short experience;
	short gold;
	short attack;
	short defense;
	Item armor;
	Item weapon;

};

#endif // !CHARACTER_H
