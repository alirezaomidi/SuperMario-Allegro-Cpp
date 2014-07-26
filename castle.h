#ifndef CASTLE_H
#define CASTLE_H

#include "gameobject.h"

class Castle : public GameObject {
public:
    Castle(Position *pos);
    void update(ALLEGRO_EVENT event);
    void draw();
    void moveLeft();
};

#endif // CASTLE_H
