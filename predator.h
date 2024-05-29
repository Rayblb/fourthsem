#ifndef PREDATOR_H
#define PREDATOR_H

#include "Character.h"
#include "Prey.h"

class Predator : public Character {
public:
    Predator(int x = 0, int y = 0);

    void moveToPrey(const Prey& prey, int maxDistance, int size);

    void move(int direction, int distance, int size);
};

#endif // PREDATOR_H
