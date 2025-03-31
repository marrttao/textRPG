#include "smithy.h"

void Smithy::BuySword(MainCharacter& character) {
    int price;
    cout << "Swords available for purchase: " << endl;
    SwordCollection swords;
    JsonParser parser;
    parser.parse(swords, "src/domain/services/json/assets/json/swords.json", ParsingPath::FILE_FORMAT);
    for (int i = 0; i < swords.swords.size(); i++) {
        cout << "Sword " << i + 1 << ": " << swords.swords[i].name << endl;
        cout << "Damage: " << swords.swords[i].damage << endl;
        cout << "Durability: " << swords.swords[i].durability << endl;
        cout << "Type: " << swords.swords[i].type << endl;
        cout << "Price: " << 2 * swords.swords[i].rarity << endl;
        price = 2 * swords.swords[i].rarity;
        cout << "Attributes: ";
        for (int j = 0; j < swords.swords[i].attributes.size(); j++) {
            cout << swords.swords[i].attributes[j] << " ";
        }
        cout << endl;
    }
    cout << "Enter the name of the sword you want to buy: ";

    string swordName;
    cin >> swordName;
    for (int i = 0; i < swords.swords.size(); i++) {
        if (swords.swords[i].name == swordName) {
            price = 2 * swords.swords[i].rarity;
            if (character.gold >= price) {
                character.gold -= price;
                character.weapon = swordName;
                cout << "You have successfully bought the sword!" << endl;
                character.inventory.addItem(swordName);
            }
            else {
                cout << "You don't have enough gold to buy this sword!" << endl;
            }
            break;
        }
    }
}

void Smithy::RepairSword(MainCharacter& character) {
    SwordCollection swords;
    JsonParser parser;
    parser.parse(swords, "src/domain/services/json/swords.json", ParsingPath::FILE_FORMAT);
    for (int i = 0; i < swords.swords.size(); i++) {
        if (swords.swords[i].name == character.weapon) {
            if (swords.swords[i].durability == 100) {
                cout << "Your sword is already at full durability!" << endl;
                return;
            }
            int price = 2 * (100 - swords.swords[i].durability);
            if (character.gold >= price) {
                character.gold -= price;
                swords.swords[i].durability = 100;
                cout << "You have successfully repaired your sword!" << endl;
            }
            else {
                cout << "You don't have enough gold to repair your sword!" << endl;
            }
            break;
        }
    }
}
