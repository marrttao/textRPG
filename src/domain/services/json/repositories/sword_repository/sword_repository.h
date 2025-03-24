// File: example_repository.h
#ifndef SWORD_REPOSITORY_H
#define SWORD_REPOSITORY_H

#include <iostream>
#include <vector>
#include "../../models/items/swords.h"
#include "../../models/itemm/sword/sword.h"

using namespace std;

class SwordRepository {
public:
    static void print(const Swords& swords)
    {

        cout << "Items: " << '\n';
        for (const Sword& item : swords.items)
        {
    
			cout << "name: " << item.name << '\n';
			cout << "type: " << item.type << '\n';
			cout << "damage: " << item.damage << '\n';
			cout << "weight: " << item.weight << '\n';
			cout << '\n';
        }
    }
};

#endif // SWORD_REPOSITORY_H
