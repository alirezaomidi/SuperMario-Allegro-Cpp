#ifndef TURTLE_H
#define TURTLE_H

#include "enemy.h"

class Turtle : public Enemy {
private:
    Rectangle *walk[2];
    Rectangle *currentFrame;
    enum Direction {Left, Right};
    Direction dir;
    float moveSpeed;
    float frameChangeSpeed = 0.1;
    float currentFrameNumber = 0;
    bool isObstacleOnBottom = false, isObstacleOnRight = false, isObstacleOnLeft = false;
public:
    Turtle(Position *pos);
    void update(ALLEGRO_EVENT event);
    void draw();
    void moveLeft();
};

#endif // TURTLE_H
