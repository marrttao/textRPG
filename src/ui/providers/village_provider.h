#ifndef VILLAGE_PROVIDER_H
#define VILLAGE_PROVIDER_H

#include "../../domain/entities/character/character.h"
#include "../../domain/entities/village/village.h"
#include "../../domain/entities/village/npc/pickpocket.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <random>
#include <mutex>

class VillageProvider {
private:
    int sellerMood = 50; // Настроение продавца (от 0 до 100)
    std::mutex moodMutex;
    bool playerInForest = true;

public:
    void simulateVillage() {
        std::cout << "Simulating village activities..." << std::endl;

        std::thread shopThread(&VillageProvider::simulateShop, this);
        std::thread pickpocketThread(&VillageProvider::pickpocketChance, this);
        std::thread smithyThread(&VillageProvider::smithyActivity, this);
        std::thread strangeShopThread(&VillageProvider::strangeShopActivity, this);

        shopThread.detach();
        pickpocketThread.detach();
        smithyThread.detach();
        strangeShopThread.detach();
    }

    void simulateShop() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> timeDist(1, 5);
        std::uniform_int_distribution<int> purchaseDist(1, 10);

        while (playerInForest) {
            std::this_thread::sleep_for(std::chrono::seconds(timeDist(gen)));
            int purchases = purchaseDist(gen);

            std::lock_guard<std::mutex> lock(moodMutex);
            sellerMood += purchases * 2;
            if (sellerMood > 100) sellerMood = 100;

           
        }
    }

    void pickpocketChance() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 10);

        while (playerInForest) {
            std::this_thread::sleep_for(std::chrono::seconds(10));
            int chance = dis(gen);

            if (chance <= 3) {
                std::lock_guard<std::mutex> lock(moodMutex);
                sellerMood -= 10;
                if (sellerMood < 0) sellerMood = 0;
               
            }
        }
    }

    void smithyActivity() {
        while (playerInForest) {
            std::this_thread::sleep_for(std::chrono::seconds(7));
           
        }
    }

    void strangeShopActivity() {
        while (playerInForest) {
            std::this_thread::sleep_for(std::chrono::seconds(8));
           
        }
    }

    void setPlayerInForest(bool status) {
        playerInForest = status;
    }
};

#endif // VILLAGE_PROVIDER_H
