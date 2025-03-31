#ifndef MAINCHARACTER_PROVIDER_H
#define MAINCHARACTER_PROVIDER_H
#include "../../domain/entities/character/character.h"

class MainCharacterProvider {
public:
    MainCharacter& character;

    MainCharacterProvider(MainCharacter& character) : character(character) {}
};


#endif // !MAINCHARACTER_PROVIDER_H
