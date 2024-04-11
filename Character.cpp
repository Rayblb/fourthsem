#include "Character.h"

Character::Character(int x, int y) {

	this ->x = x;
	this ->y = y;

};

Character::~Character() {};

void  Character::Move(const std::string& Direction) {
	if (Direction == "Up") {
		y--;
	}
	else if(Direction == "Down") {
		y++;
	}
	else if (Direction == "Right") {
		x++;
	}
	else if (Direction == "Left") {
		x--;
	}
	std::cout << "the character is moving in " << Direction << std::endl;
}