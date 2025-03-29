#ifndef POTION_REPOSITORY_H
#define POTION_REPOSITORY_H

#include <iostream>
#include "../models/potions/potions.h"

class PotionRepository {
public:
		static void print(const Potion& potion) {
		std::cout << "=== Potion Details ===\n";
		std::cout << "Name: " << potion.name << '\n';
		std::cout << "Effect: " << potion.effect << '\n';
		std::cout << "Potency: " << potion.potency << '\n';
		std::cout << "Duration: " << potion.duration << '\n';
		std::cout << "Ingredients: ";
		for (const auto& ingredient : potion.ingredients) {
			std::cout << ingredient << " ";
		}
        std::cout << "\n=====================\n";
    }
};

#endif // !POTION_REPOSITORY_H
