#ifndef EVENTS_PROVIDER_H
#define EVENTS_PROVIDER_H
#include "../../domain/events/events_system/events_system.h"


class EventsProvider : EventsSystem{

public:
	EventsProvider(CombatSystem& combatSystem, MainCharacter& character)
		: EventsSystem(combatSystem, character) {}
	bool IsInForest = false;

	void Event() {
		while (IsInForest) {
			randomEvent();
		}
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(10000, 30000);
		int time = dis(gen);
		std::this_thread::sleep_for(std::chrono::milliseconds(time));
		randomEvent();
		cout << "Wanna back to village? 1 - yes 0 - no" << endl;
		int choice;
		cin >> choice;
		if (choice == 1) {
			toVillage();
		}
		else {
			system("cls");
		}
	}

};

#endif // !EVENTS_PROVIDER_H