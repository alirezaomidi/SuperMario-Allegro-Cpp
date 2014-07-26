#ifndef BUSH_H
#define BUSH_H

#include "gameobject.h"

class Bush : public GameObject {
public:
    enum BushType {Big, Medium, Small};
    Bush(BushType type, Position *pos);
    void update(ALLEGRO_EVENT event);
    void draw();
    void moveLeft();

private:
    BushType type;
};

#endif // BUSH_H
