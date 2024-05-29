#ifndef ARENA_H
#define ARENA_H

#include "Prey.h"
#include "Predator.h"
#include <vector>

class Arena {
private:
    int size;
    Prey prey;
    Predator predator;
    int steps;
    const int maxSteps;
    int predatorMoveDistance;

public:
    Arena(int size, Prey prey, Predator predator, int maxSteps = 7, int difficulty = 1);

    void printArena();

    void playGame();

    void movePrey(int direction);
    void movePredator(int direction);
    void movePrey();
    void movePredator();

    bool isGameOver();
};

#endif // ARENA_H
