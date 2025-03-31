#ifndef SMITHY_H
#define SMITHY_H

#include "../npc/blacksmith.h"
#include "../../../services/json/core/json_parser.h"
#include "../../../services/json/models/swords/swords.h"
#include "../../../entities/character/character.h"
#include "../../../repositories/inventory_repository/inventory_repository.h"
#include <iostream>
using namespace std;

class Smithy {
private:
    Blacksmith blacksmith;
public:
    void BuySword(MainCharacter& character);
    void RepairSword(MainCharacter& character);
};

#endif // SMITHY_H
