#ifndef BRICK_H
#define BRICK_H

#include "gameobject.h"

class Brick : public GameObject {
public:
    Brick(Position *pos);
    void update(ALLEGRO_EVENT event);
    void draw();
    void moveLeft();
};

#endif // BRICK_H
