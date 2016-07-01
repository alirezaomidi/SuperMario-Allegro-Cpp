#ifndef MARIO_H
#define MARIO_H

#include "gameobject.h"
#include "inputmanager.h"
#include "soundmanager.h"

class Mario : public GameObject {
private:
    SoundManager *sound;

    ALLEGRO_BITMAP *image;
    enum MarioType {Big, Small};
    MarioType type;
    Rectangle *stand, *walk[3], *run, *hang[2], *crouchOrDie;
    Rectangle *currentFrame;
    int rightOrLeftFlag = 0; // right = 0, left = 1
    float jumpSpeed, moveSpeed;
    bool isOnAir = false;
    float frameChangeSpeed = 0.5;
    float currentFrameNumber = 0;
    bool isObstacleOnTop = false, isObstacleOnBottom = false, isObstacleOnRight = false, isObstacleOnLeft = false;

    void initMarioRects();

public:
    enum Direction {Up, Down, Left, Right};
    Direction dir;

    Mario(SoundManager *sound);

    void loadContent();
    void unloadContect();
    void update(ALLEGRO_EVENT event, InputManager input);
    void draw();
    bool haveCollideWith(GameObject *obj);
    void collide(GameObject *obj);
};

#endif // MARIO_H
