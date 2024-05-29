#include "Prey.h"
#include <cstdlib>

Prey::Prey(int x, int y) : Character(x, y) {}

void Prey::moveRandomly() {
    int dx = rand() % 3 - 1;
    int dy = rand() % 3 - 1;
    Character::move(dx, dy);  // Using Character's move method
}

void Prey::move(int direction) {
    switch (direction) {
    case 1: Character::move(0, -1); break; // Up
    case 2: Character::move(1, -1); break;  // upright
    case 3: Character::move(-1, -1); break;  // upleft
    case 4: Character::move(0, 1); break;  // Down
    case 5: Character::move(1, 1); break;  // downright
    case 6: Character::move(-1, 1); break;  // downleft
    case 7: Character::move(-1, 0); break; // Left
    case 8: Character::move(1, 0); break;  // Right
    default: break;
    }
}
