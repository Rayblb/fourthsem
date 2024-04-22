#pragma once
#ifndef PREY_H
#define PREY_H
#include "Character.h"

class Prey : public Character {
public:
    Prey(int x, int y);
    ~Prey();
    void Move(const std::string& Direction) ;
};

#endif
