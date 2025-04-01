#ifndef STRANGE_SHOP_H
#define STRANGE_SHOP_H
#include "../npc/dealer.h"
#include "../../character/character.h"
#include "../../../services/json/models/potions/potions.h"
#include "../../../services/json/core/json_parser.h"
#include <iostream>

class StrangeShop {
public:
	Dealer dealer;
	vector <pair<string, string>> products = { {"Health Potion", "potion"}, {"Rage Potion", "potion"} };
	void showProducts() {
		if (dealer.isOnPlace) {
			cout << "Welcome to the Strange Shop!" << endl;
			cout << "Here are the products we have: " << endl;
			for (int i = 0; i < products.size(); i++) {
				cout << i + 1 << ". " << products[i].first << endl;
				if (products[i].second == "potion")
				{
					PotionCollection potions;
					JsonParser parser;
					parser.parse(potions, "src/domain/services/json/assets/json/potions.json", ParsingPath::FILE_FORMAT);
					// find potion with name
					for (auto potion : potions.potions) {
						if (potion.name == products[i].first) {
							cout << "Price: " << potion.rarity * 3 - dealer.mood << endl;
							cout << endl;
						}
					}
				}
			}
		}
		else {
			cout << "Dealer is not on place." << endl;
		}
	}
};

#endif // !STRANGE_SHOP_H
