// Arena.h
#ifndef ARENA_H
#define ARENA_H

#include "Character.h"
#include "Prey.h"
#include "Predator.h"

class Arena {
public:
    Arena();
    ~Arena();

    void startGame();
    void moveCharacters(const std::string& Direction);
    bool isGameOver();

private:
    Character* player;
    Prey* prey;
    Predator* predator;
    int maxSteps;
    int currentStep;
};

#endif // ARENA_H
