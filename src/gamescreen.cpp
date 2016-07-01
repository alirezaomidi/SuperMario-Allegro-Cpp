#include "gamescreen.h"
#include <iostream>

GameScreen::GameScreen(SoundManager *sound) {
    mario = new Mario(sound);
    map = new Map("1");
}

void GameScreen::loadContent() {

}

void GameScreen::unloadContent() {

}

void GameScreen::update(ALLEGRO_EVENT event) {
    map->update(event);
    mario->update(event, input);
}

void GameScreen::draw() {
    map->draw();
    mario->draw();
}

void GameScreen::checkCollides() {
    bool thereIsAtLeastOneCollide = false;
    for (std::vector<GameObject*>::iterator itr = map->objects->begin(); itr != map->objects->end(); itr++) {
        if (mario->haveCollideWith(*itr)) {
            thereIsAtLeastOneCollide = true;
            mario->collide(*itr);
            (*itr)->collide(mario);
        }
    }
    if (!thereIsAtLeastOneCollide) {
        mario->activeGravity = true;
    }
    if (mario->box->right > SCREEN_WIDTH / 4 * 3) {
        if (currentX <= 3390 * SCALE) {
            if (mario->velocity.first > 0) {
                map->moveMapToLeft();
                mario->box->updateWithRight(SCREEN_WIDTH / 4 * 3);
            }
        } else
            currentX = 3392 * SCALE;
        currentX += 5;
    }
}
