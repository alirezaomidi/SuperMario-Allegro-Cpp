#ifndef FLAG_H
#define FLAG_H

#include "gameobject.h"

class Flag : public GameObject {
public:
    Flag(Position *pos);
    void update(ALLEGRO_EVENT event);
    void draw();
    void moveLeft();
};

#endif // FLAG_H
