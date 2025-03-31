#ifndef BOSS_EVENT_REPOSITORY_H
#define BOSS_EVENT_REPOSITORY_H
#include <iostream>
#include "../models/events/boss_events/boss_events.h"

class BossEventRepository {
public:
    static void print(const BossEvent& bossEvent) {
        std::cout << "=== Boss Event Details ===\n";
        std::cout << "Name: " << bossEvent.name << '\n';
        std::cout << "Description: " << bossEvent.description << '\n';
        std::cout << "Type: " << bossEvent.type << '\n';
        std::cout << "Location: " << bossEvent.location << '\n';
        std::cout << "Damage: " << bossEvent.damage << '\n';
        std::cout << "Fear: " << bossEvent.fear << '\n';
        std::cout << "==========================\n";
    }
};

#endif // !BOSS_EVENT_REPOSITORY_H