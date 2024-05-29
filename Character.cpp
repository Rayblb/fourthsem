#include "Character.h"

Character::Character(int x, int y) : position(x, y) {}

void Character::move(int dx, int dy) {
    position.x += dx;
    position.y += dy;
}

Point2D Character::getPosition() const {
    return position;
}
