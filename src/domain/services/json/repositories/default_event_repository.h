#pragma once

#include <iostream>
#include "../models/events/default_events/default_events.h"

class DefaultEventRepository {
public:
    static void print(const DefaultEvent& defaultEvent) {
        std::cout << "=== Default Event Details ===\n";
        std::cout << "ID: " << defaultEvent.id << '\n';
        std::cout << "Name: " << defaultEvent.name << '\n';
        std::cout << "Description: " << defaultEvent.description << '\n';
        std::cout << "Type: " << defaultEvent.type << '\n';
        std::cout << "Location: " << defaultEvent.location << '\n';
        std::cout << "Damage: " << defaultEvent.damage << '\n';
        std::cout << "Fear: " << defaultEvent.fear << '\n';
        std::cout << "=============================\n";
    }
};

