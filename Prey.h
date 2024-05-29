#ifndef PREY_H
#define PREY_H

#include "Character.h"

class Prey : public Character {
public:
    Prey(int x = 0, int y = 0);

    void moveRandomly();
    void move(int direction);
};

#endif // PREY_H
