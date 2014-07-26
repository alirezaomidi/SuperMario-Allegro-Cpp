#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <allegro5/allegro.h>
#include <allegro5/keyboard.h>
#include <vector>

class InputManager {
private:
    ALLEGRO_KEYBOARD_STATE keyState;
public:
    InputManager();
    void update();

    bool isKeyPressed(ALLEGRO_EVENT event, int key);
    bool isKeyDown(int key);
    bool isKeyReleased(ALLEGRO_EVENT event, int key);
};

#endif // INPUTMANAGER_H
