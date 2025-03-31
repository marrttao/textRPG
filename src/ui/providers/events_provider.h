#ifndef EVENTS_PROVIDER_H
#define EVENTS_PROVIDER_H
#include "../../domain/events/events_system/events_system.h"
#include <iostream>
#include <random>
#include <thread>
#include <chrono>
#include <ctime>
class EventsProvider : public EventsSystem {
public:
    EventsProvider(CombatSystem& combatSystem, MainCharacter& character)
        : EventsSystem(combatSystem, character) {}

    void Event() {
        std::cout << "Event method started" << std::endl;
        while (IsInForest) {
            std::random_device rd;
            std::mt19937 gen(rd());
            int min = 10;
            int max = 30;
            if (min > max) {
                std::cerr << "Invalid min and max values for uniform_int_distribution" << std::endl;
                return;
            }
            std::uniform_int_distribution<> dis(min, max);
            int time = dis(gen) * 1000; // Convert to milliseconds
            std::cout << "Wait for " << time << " milliseconds" << std::endl;
            // sleep
			
            randomEvent();
            std::cout << "Wanna back to village? 1 - yes 0 - no" << std::endl;
            int choice;
            std::cin >> choice;
            if (choice == 1) {
                toVillage();
            }
            else {
                system("cls");
            }
        }
        std::cout << "Event method ended" << std::endl;
    }

};

#endif // !EVENTS_PROVIDER_H
