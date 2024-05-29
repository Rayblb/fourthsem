#include "Predator.h"
#include <algorithm>
#include <cmath>

Predator::Predator(int x, int y) : Character(x, y) {}

void Predator::moveToPrey(const Prey& prey, int maxDistance, int size) {
    Point2D preyPosition = prey.getPosition();
    Point2D predatorPosition = this->getPosition();

    int dx = preyPosition.x - predatorPosition.x;
    int dy = preyPosition.y - predatorPosition.y;

    int directionX = 0;
    int directionY = 0;

    if (dx != 0) {
        directionX = (dx > 0) ? 1 : -1;
    }
    if (dy != 0) {
        directionY = (dy > 0) ? 1 : -1;
    }

    // Adjust distance based on the distance to the prey and the max distance
    int distance = std::min({ std::abs(dx), std::abs(dy), maxDistance });

    Character::move(directionX * distance, directionY * distance, size);
}

void Predator::move(int direction, int distance, int size) {
    switch (direction) {
    case 1: Character::move(0, -distance, size); break; // Up
    case 2: Character::move(0, distance, size); break;  // Down
    case 3: Character::move(-distance, 0, size); break; // Left
    case 4: Character::move(distance, 0, size); break;  // Right
    default: break;
    }
}
