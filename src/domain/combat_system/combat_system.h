// combat_system.h
#ifndef COMBAT_SYSTEM_H
#define COMBAT_SYSTEM_H

#include "../events/events_system/events_system.h"
#include "../entities/character/character.h"
#include "../services/json/models/swords/swords.h"
#include <algorithm>
#include <iostream>
#include <thread>
#include <chrono>
#include <random>
#define PATH_SWORDS "src/domain/services/json/assets/json/swords.json"
class CombatSystem {
public:
    int EnemyHealth;
    int EnemyDamage;
    int Fear;
	int gold;
	int experience;

    // Constructor
    CombatSystem(int enemyHealth, int enemyDamage, int fear)
        : EnemyHealth(enemyHealth), EnemyDamage(enemyDamage), Fear(fear) {}

    void Attack(MainCharacter& character) {
        SwordCollection swords;
        JsonParser parser;
        parser.parse(swords, PATH_SWORDS, ParsingPath::FILE_FORMAT);

        if (Fear <= 50) {
            // random
            auto it = std::find_if(swords.swords.begin(), swords.swords.end(), [&character](Sword& sword) {
                return sword.name == character.weapon;
                });

            if (it != swords.swords.end()) {
                EnemyHealth -= it->damage;
            }
        }
        else if (Fear > 50) {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dis(1, 2);
            if (dis(gen) == 2) {
                std::cout << "You missed!" << std::endl;
            }
            else {
                auto it = std::find_if(swords.swords.begin(), swords.swords.end(), [&character](Sword& sword) {
                    return sword.name == character.weapon;
                    });

                if (it != swords.swords.end()) {
                    EnemyHealth -= it->damage;
                }
            }
        }
    }



    void Combat(MainCharacter& character) {
        while (EnemyHealth > 0 && character.health > 0) {
            std::cout << "\nPress 1 to Attack! You have 3 seconds or you will be hit!" << std::endl;

            auto start = std::chrono::steady_clock::now();
            bool attacked = false;

            while (std::chrono::steady_clock::now() - start < std::chrono::seconds(3)) {
                if (std::cin.peek() != EOF) {
                    int input;
                    std::cin >> input;
                    if (input == 1) {
                        Attack(character);
						std::cout << "You attacked! Enemy health is now: " << EnemyHealth << std::endl;
                        attacked = true;
                        break;
                    }
                }
            }

            if (!attacked) {
                character.health -= EnemyDamage;
                std::cout << "You were hit! Your health is now: " << character.health << std::endl;
            }

            if (EnemyHealth <= 0) {
                std::cout << "You defeated the enemy!" << std::endl;
				character.gold += gold;
				character.experience += experience;
				character.saveCharacter();
                break;
            }

            if (character.health <= 0) {
                std::cout << "You were defeated!" << std::endl;
				character.gold = 0;
				character.health = 100+character.strength*2.5;
				character.isDead = true;
                break;
            }
        }
    }
};

// fabric
class CombatSystemFabric {
public:
    static CombatSystem createCombatSystem(int enemyHealth, int enemyDamage, int fear) {
        return CombatSystem(enemyHealth, enemyDamage, fear);
    }
};

#endif // !COMBAT_SYSTEM_H
