#ifndef VILLAGE_H
#define VILLAGE_H

#include "npc/pickpocket.h"
#include "strange_shop/strange_shop.h"
#include "smithy/smithy.h"
#include <iostream>

class Village {
public:
    Pickpocket pickpocket;
    StrangeShop strangeShop;
    Smithy smithy;

    void enter(MainCharacter& character) {
        std::cout << "Welcome to the village!" << std::endl;
        std::cout << "1. Visit the Strange Shop" << std::endl;
        std::cout << "2. Visit the Smithy" << std::endl;
        std::cout << "3. Leave the village" << std::endl;

        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1:
            visitStrangeShop(character);
            break;
        case 2:
            visitSmithy(character);
            break;
        case 3:
            leave();
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            enter(character);
            break;
        }
    }

    void leave() {
        std::cout << "You have left the village." << std::endl;
    }

private:
    void visitStrangeShop(MainCharacter& character) {
        strangeShop.showProducts();
        std::cout << "Do you want to buy something? (yes/no)" << std::endl;
        std::string response;
        std::cin >> response;
        if (response == "yes") {
            strangeShop.buyProduct(character);
        }
    }

    void visitSmithy(MainCharacter& character) {
        std::cout << "1. Buy a sword" << std::endl;
        std::cout << "2. Repair your sword" << std::endl;
        int choice;
        std::cin >> choice;
        switch (choice) {
        case 1:
            smithy.BuySword(character);
            break;
        case 2:
            smithy.RepairSword(character);
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            visitSmithy(character);
            break;
        }
    }
};

#endif // VILLAGE_H
