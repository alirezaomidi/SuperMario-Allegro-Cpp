#ifndef HILL_H
#define HILL_H

#include "gameobject.h"

class Hill : public GameObject {
public:
    enum HillType {Big, Small};
    Hill(HillType type, Position *pos);
    void update(ALLEGRO_EVENT event);
    void draw();
    void moveLeft();

private:
    HillType type;
};

#endif // HILL_H
