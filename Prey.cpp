#include "Prey.h"
#include <cstdlib>

Prey::Prey(int x, int y) : Character(x, y) {}

void Prey::moveRandomly(int size) {
    int dx = rand() % 3 - 1;
    int dy = rand() % 3 - 1;
    Character::move(dx, dy, size);  // Using Character's move method
}

void Prey::move(int direction, int size) {
    switch (direction) {
    case 1: Character::move(0, -1, size); break; // Up
    case 2: Character::move(1, -1, size); break;  // Upright
    case 3: Character::move(-1, -1, size); break;  // Upleft
    case 4: Character::move(0, 1, size); break;  // Down
    case 5: Character::move(1, 1, size); break;  // Downright
    case 6: Character::move(-1, 1, size); break;  // Downleft
    case 7: Character::move(-1, 0, size); break; // Left
    case 8: Character::move(1, 0, size); break;  // Right
    default: break;
    }
}
