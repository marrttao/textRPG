#ifndef EVENTS_SYSTEM_H
#define EVENTS_SYSTEM_H
#include <random>
#include <thread>
#include <chrono>
#include "../../services/json/core/json_parser.h"
#include "../../services/json/models/events/boss_events/boss_events.h"
#include "../../services/json/models/events/default_events/default_events.h"
#include "../../services/json/repositories/boss_event_repository.h"
#include "../../services/json/repositories/default_event_repository.h"
#include "../../combat_system/combat_system.h"

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
            std::uniform_int_distribution<> dis(1, bossEvents.bossEvents.size());

        }
        else {
            DefaultEventCollection defaultEvents;
            JsonParser parser;
            parser.parse(defaultEvents, "src/domain/events/default_events.json", ParsingPath::FILE_FORMAT);
            std::uniform_int_distribution<> dis(1, defaultEvents.defaultEvents.size());

            // combatSystem.enemyHealth = event health
            // and other attributes
            int eventIndex = dis(gen);
            combatSystem.EnemyHealth = defaultEvents.defaultEvents[eventIndex].health;
            combatSystem.EnemyDamage = defaultEvents.defaultEvents[eventIndex].damage;
            combatSystem.Fear = defaultEvents.defaultEvents[eventIndex].fear;
            combatSystem.Combat(character); // Pass the character to the Combat function
        }
    }

    void toForest() {
        IsInForest = true;
    }

    void toVillage() {
        IsInForest = false;
    }

private:
    MainCharacter& character;
    CombatSystem& combatSystem;
};

#endif // !EVENTS_SYSTEM_H
