#ifndef PREDATOR_H
#define PREDATOR_H
#include "Character.h"

class Predator : public Character {
public:
    Predator(int x, int y);
    ~Predator();
    void Move(const std::string& Direction) override;
};

#endif
