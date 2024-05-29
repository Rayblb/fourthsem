#ifndef CHARACTER_H
#define CHARACTER_H

#include "Point2D.h"

class Character {
protected:
    Point2D position;

public:
    Character(int x = 0, int y = 0);

    void move(int dx, int dy); 

    Point2D getPosition() const;
};

#endif // CHARACTER_H
