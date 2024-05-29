#ifndef PREDATOR_H
#define PREDATOR_H

#include "Character.h"
#include "Prey.h"

class Predator : public Character {
public:
    Predator(int x = 0, int y = 0);

    void moveToPrey(const Prey& prey, int maxDistance); 
    void move(int direction, int distance);
};

#endif // PREDATOR_H
