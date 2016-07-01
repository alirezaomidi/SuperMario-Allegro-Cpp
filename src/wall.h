#ifndef WALL_H
#define WALL_H

#include "gameobject.h"

class Wall : public GameObject {
private:
    std::pair<float, float> xRange;
    float y;
    float width, height;
public:
    Wall(std::pair<int, int> xRange, int y);
    void update(ALLEGRO_EVENT event);
    void draw();
    void moveLeft();
};

#endif // WALL_H
