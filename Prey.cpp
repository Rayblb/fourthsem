#include "Prey.h"
#include "Character.h"

Prey::Prey(int x, int y) : Character(x, y) {

   this->x = x;
   this->y = y;
}

Prey::~Prey() {}

void Prey::Move(const std::string& Direction) {
    // The Prey can move a distance = 1, but in any of 8 directions

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
    else if (Direction == "UpRight") {
        x++;
        y--;
    }
    else if (Direction == "UpLeft") {
        x--;
        y--;
    }
    else if (Direction == "DownRight") {
        x++;
        y++;
    }
    else if (Direction == "DownLeft") {
        x--;
        y++;
    }
    std::cout << "the prey is moving in " << Direction << std::endl;
}
