#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_audio.h>
#include "mario.h"
#include "map.h"

#define SCREEN_HEIGHT 500
#define SCREEN_WIDTH 1067

class GameScreen {
private:
    Mario *mario;
    Map *map;
    float currentX = SCREEN_WIDTH;
protected:
    InputManager input;
public:
    GameScreen(SoundManager *sound);

    void loadContent();
    void unloadContent();
    void update(ALLEGRO_EVENT event);
    void draw();
    void checkCollides();
};

#endif // GAMESCREEN_H
