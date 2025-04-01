#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <iostream>
#include "../inventory/inventory.h"
class MainCharacter {
public:
	std::string name;
	Inventory inventory;
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
	std::string armor;
	std::string weapon;
	bool isDead = false;

	MainCharacter() {
		std::string _name;
		cout << "Enter your name: ";
		cin >> _name;
		name = _name;
		level = 1;
		health = 100;
		mana = 100;
		strength = 10;
		dexterity = 10;
		intelligence = 10;
		luck = 10;
		experience = 0;
		gold = 0;
		gold = 0;
		attack = 10;
		defense = 10;
		armor = "None";
		weapon = "Rapier of Shadows";
	}

};

#endif // !CHARACTER_H
