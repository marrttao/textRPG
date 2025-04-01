#ifndef PICKPOCKET_H
#define PICKPOCKET_H
#include "../../character/character.h"
class Pickpocket {
public:
	void stealGold(MainCharacter& character) {
		cout << "Pickpocket stole your gold!" << endl << "You lost" << character.gold/20 << "gold" << endl;
		character.gold -= character.gold / 20;
	}
};

#endif // !PICKPOCKET_H
