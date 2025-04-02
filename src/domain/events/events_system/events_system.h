#ifndef EVENTS_SYSTEM_H
#define EVENTS_SYSTEM_H

#include <random>
#include <thread>
#include <chrono>
#include <iostream>
#include "../../services/json/core/json_parser.h"
#include "../../services/json/models/events/boss_events/boss_events.h"
#include "../../services/json/models/events/default_events/default_events.h"
#include "../../services/json/repositories/boss_event_repository.h"
#include "../../services/json/repositories/default_event_repository.h"
#include "../../combat_system/combat_system.h"
#include "../../entities/character/character.h"
#include "../../entities/village/village.h"

class EventsSystem {

public:
    EventsSystem(CombatSystem& combatSystem, MainCharacter& character)
        : combatSystem(combatSystem), character(character) {}

    bool IsInForest = false;

    static int IsBossEvent() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 3);
        int event = dis(gen);
        if (event <= 2) {
            return 0;
        }
        else {
            return 1;
        }
    }

    void randomEvent() {
        std::random_device rd;
        std::mt19937 gen(rd());

        if (IsBossEvent()) {
            BossEventCollection bossEvents;
            JsonParser parser;
            parser.parse(bossEvents, "src/domain/events/boss_events.json", ParsingPath::FILE_FORMAT);
            if (bossEvents.bossEvents.empty()) {
                std::cerr << "No boss events available." << std::endl;
                return;
            }
            std::uniform_int_distribution<> dis(0, static_cast<int>(bossEvents.bossEvents.size()) - 1);
            int eventIndex = dis(gen);
            // Handle boss event using eventIndex
            combatSystem.EnemyHealth = bossEvents.bossEvents[eventIndex].health;
            combatSystem.EnemyDamage = bossEvents.bossEvents[eventIndex].damage;
            combatSystem.Fear = bossEvents.bossEvents[eventIndex].fear;
            combatSystem.gold = bossEvents.bossEvents[eventIndex].gold;
            combatSystem.experience = bossEvents.bossEvents[eventIndex].experience;

            // repository print
            BossEventRepository::print(bossEvents.bossEvents[eventIndex]);

            combatSystem.Combat(character); // Pass the character to the Combat function
        }
        else {
            DefaultEventCollection defaultEvents;
            JsonParser parser;
            parser.parse(defaultEvents, "src/domain/events/default_events.json", ParsingPath::FILE_FORMAT);
            if (defaultEvents.defaultEvents.empty()) {
                std::cerr << "No default events available." << std::endl;
                return;
            }
            std::uniform_int_distribution<> dis(0, static_cast<int>(defaultEvents.defaultEvents.size()) - 1);
            int eventIndex = dis(gen);
            // Set combat system attributes based on the selected event
            combatSystem.EnemyHealth = defaultEvents.defaultEvents[eventIndex].health;
            combatSystem.EnemyDamage = defaultEvents.defaultEvents[eventIndex].damage;
            combatSystem.Fear = defaultEvents.defaultEvents[eventIndex].fear;
            combatSystem.gold = defaultEvents.defaultEvents[eventIndex].gold;
            combatSystem.experience = defaultEvents.defaultEvents[eventIndex].experience;

            // repository print
            DefaultEventRepository::print(defaultEvents.defaultEvents[eventIndex]);
            combatSystem.Combat(character); // Pass the character to the Combat function
        }
    }

    void toForest() {
        IsInForest = true;
        std::cout << "You have entered the forest." << std::endl;
        randomEvent();
    }

    void toVillage() {
        IsInForest = false;
        std::cout << "You have entered the village." << std::endl;
        Village village;
        village.enter(character);
    }

private:
    MainCharacter& character;
    CombatSystem& combatSystem;
};

#endif // !EVENTS_SYSTEM_H
