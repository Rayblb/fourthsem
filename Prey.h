#ifndef PREY_H
#define PREY_H

#include "Character.h"

class Prey : public Character {
public:
    Prey(int x = 0, int y = 0);

    void moveRandomly(int size);

    void move(int direction, int size);
};

#endif // PREY_H
