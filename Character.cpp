#include "Character.h"

Character::Character(int x, int y) : position(x, y) {}

void Character::move(int dx, int dy, int size) {
    position.moveWithinBounds(dx, dy, 0, size - 1, 0, size - 1);
}

Point2D Character::getPosition() const {
    return position;
}
