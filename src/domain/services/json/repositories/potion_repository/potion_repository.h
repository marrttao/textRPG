
#ifndef POTION_REPOSITORY_H
#define POTION_REPOSITORY_H

#include <iostream>
#include <vector>
#include "../../models/items/potions.h"
#include "../../models/itemm/potion/potion.h"

using namespace std;

class PotionRepository {
public:
	static void print(const Potions& potions)
	{

		cout << "Items: " << '\n';
		for (const Potion& item : potions.potions)
		{
			// all from potions
			cout << "name: " << item.name << '\n';
			cout << "type: " << item.type << '\n';
			cout << "heal: " << item.heal << '\n';
			cout << "strength: " << item.strength << '\n';
			cout << "armour: " << item.armour << '\n';
			cout << "rage: " << item.rage << '\n';
			cout << "duration: " << item.duration << '\n';
			cout << "weight: " << item.weight << '\n';
			cout << '\n';

		}
	}
};

#endif POTION_REPOSITORY_H
