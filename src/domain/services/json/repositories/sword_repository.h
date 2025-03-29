// sword_repository.h
#ifndef SWORD_REPOSITORY_H
#define SWORD_REPOSITORY_H

#include <iostream>
#include "../models/swords/Swords.h"

class SwordRepository {
public:
    static void print(const Sword& sword) {
        std::cout << "=== Sword Details ===\n";
        std::cout << "Name: " << sword.name << '\n';
        std::cout << "Damage: " << sword.damage << '\n';
        std::cout << "Durability: " << sword.durability << "/100\n";
        std::cout << "Type: " << sword.type << '\n';

        std::cout << "Attributes: ";
        for (const auto& attr : sword.attributes) {
            std::cout << attr << " ";
        }
        std::cout << "\n=====================\n";
    }
};

#endif // SWORD_REPOSITORY_H