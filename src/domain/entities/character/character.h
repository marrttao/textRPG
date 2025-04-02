#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <iostream>
#include "../inventory/inventory.h"
#include <fstream>
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
	bool isInVillage = true;
	MainCharacter() {
		std::string _name;
		cout << "Enter your name: ";
		cin >> _name;
		name = _name;
		level = 1;
		health = 100;
		mana = 100;
		strength = 0;
		dexterity = 10;
		intelligence = 10;
		luck = 10;
		experience = 0;
		gold = 0;
		attack = 10;
		defense = 10;
		armor = "None";
		weapon = "Rapier of Shadows";
	}
	void showStats() {
		std::cout << "Name: " << name << std::endl;
		std::cout << "Level: " << level << std::endl;
		std::cout << "Health: " << health << std::endl;
		std::cout << "Mana: " << mana << std::endl;
		std::cout << "Strength: " << strength << std::endl;
		std::cout << "Dexterity: " << dexterity << std::endl;
		std::cout << "Intelligence: " << intelligence << std::endl;
		std::cout << "Luck: " << luck << std::endl;
		std::cout << "Experience: " << experience << std::endl;
		std::cout << "Gold: " << gold << std::endl;
		std::cout << "Attack: " << attack << std::endl;
		std::cout << "Defense: " << defense << std::endl;
		std::cout << "Armor: " << armor << std::endl;
		std::cout << "Weapon: " << weapon << std::endl;
	}
	void saveCharacter() {
		std::ofstream file;
		file.open("src/data/local/character/character.json");
		file << "{\n";
		file << "\"name\": \"" << name << "\",\n";
		file << "\"level\": " << level << ",\n";
		file << "\"health\": " << health << ",\n";
		file << "\"mana\": " << mana << ",\n";
		file << "\"strength\": " << strength << ",\n";
		file << "\"dexterity\": " << dexterity << ",\n";
		file << "\"intelligence\": " << intelligence << ",\n";
		file << "\"luck\": " << luck << ",\n";
		file << "\"experience\": " << experience << ",\n";
		file << "\"gold\": " << gold << ",\n";
		file << "\"attack\": " << attack << ",\n";
		file << "\"defense\": " << defense << ",\n";
		file << "\"armor\": \"" << armor << "\",\n";
		file << "\"weapon\": \"" << weapon << "\"\n";
		file << "}";
		file.close();
	}
	void loadCharacter() {

		// Load character from json
		std::ifstream file;
		file.open("src/data/local/character/character.json");
		if (!file.is_open()) {
			std::cerr << "Error: Could not open the file." << std::endl;
			return;
		}
		std::string line;
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
		std::string armor;
		std::string weapon;
		while (std::getline(file, line)) {
			if (line.find("name") != std::string::npos) {
				name = line.substr(line.find(":") + 3, line.size() - 3);
			}
			else if (line.find("level") != std::string::npos) {
				level = std::stoi(line.substr(line.find(":") + 2, line.size() - 2));
			}
			else if (line.find("health") != std::string::npos) {
				health = std::stoi(line.substr(line.find(":") + 2, line.size() - 2));
			}
			else if (line.find("mana") != std::string::npos) {
				mana = std::stoi(line.substr(line.find(":") + 2, line.size() - 2));
			}
			else if (line.find("strength") != std::string::npos) {
				strength = std::stoi(line.substr(line.find(":") + 2, line.size() - 2));
			}
			else if (line.find("dexterity") != std::string::npos) {
				dexterity = std::stoi(line.substr(line.find(":") + 2, line.size() - 2));
			}
			else if (line.find("intelligence") != std::string::npos) {
				intelligence = std::stoi(line.substr(line.find(":") + 2, line.size() - 2));
			}
			else if (line.find("luck") != std::string::npos) {
				luck = std::stoi(line.substr(line.find(":") + 2, line.size() - 2));
			}
			else if (line.find("experience") != std::string::npos) {
				experience = std::stoi(line.substr(line.find(":") + 2, line.size() - 2));
			}
			else if (line.find("gold") != std::string::npos) {
				gold = std::stoi(line.substr(line.find(":") + 2, line.size() - 2));
			}
			else if (line.find("attack") != std::string::npos) {
				attack = std::stoi(line.substr(line.find(":") + 2, line.size() - 2));
			}
			else if (line.find("defense") != std::string::npos) {
				defense = std::stoi(line.substr(line.find(":") + 2, line.size() - 2));
			}
			else if (line.find("armor") != std::string::npos) {
				armor = line.substr(line.find(":") + 3, line.size() - 3);
			}
			else if (line.find("weapon") != std::string::npos) {
				weapon = line.substr(line.find(":") + 3, line.size() - 3);
			}
		}
		file.close();
		name = name.substr(0, name.size() - 2);
		armor = armor.substr(0, armor.size() - 2);
		weapon = weapon.substr(0, weapon.size() - 2);
		MainCharacter character;
		character.name = name;
		character.level = level;
		character.health = health;
		character.mana = mana;
		character.strength = strength;
		character.dexterity = dexterity;
		character.intelligence = intelligence;
		character.luck = luck;
		character.experience = experience;
		character.gold = gold;
		character.attack = attack;
		character.defense = defense;
		character.armor = armor;
		character.weapon = weapon;
	}
	void updateStats() {
		// using experience += o some stat
		// choose stat to upgrade
		std::cout << "Choose stat to upgrade: " << std::endl;
		std::cout << "1. Mana" << std::endl;
		std::cout << "2. Strength" << std::endl;
		std::cout << "3. Dexterity" << std::endl;
		std::cout << "4. Intelligence" << std::endl;
		std::cout << "5. Luck" << std::endl;
		int choice;

		std::cin >> choice;
		switch (choice) {
		case 1:
			mana += 10;
			break;
		case 2:
			strength += 10;
			health = 100 + strength * 2.5;
			break;
		case 3:
			dexterity += 10;
			break;
		case 4:
			intelligence += 10;
			break;
		case 5:
			luck += 10;
			break;
		default:
			std::cout << "Invalid choice. Please try again." << std::endl;
			updateStats();
			break;
		}



	}

};

#endif // !CHARACTER_H
