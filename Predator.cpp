#include "Predator.h"
#include "Character.h"

Predator::Predator(int x, int y) : Character(x, y) {
    this->x = x;
    this->y = y;
}

Predator::~Predator() {}

void Predator::Move(const std::string& Direction) {
    // The Predator can move a distance from 1 to 3 (player's choice), but only in 4 directions

    if (Direction == "Up") {
        y--;
    }
    else if (Direction == "Down") {
        y++;
    }
    else if (Direction == "Right") {
        x++;
    }
    else if (Direction == "Left") {
        x--;
    }
    std::cout << "the predator is moving in " << Direction << std::endl;
}
