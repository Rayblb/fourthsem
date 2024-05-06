
#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include<string>


class Character{
public:
	int x;
	int y;
	Character(int x, int y);
	virtual ~Character();
	virtual void Move(const std::string& Direction);
};
#endif
