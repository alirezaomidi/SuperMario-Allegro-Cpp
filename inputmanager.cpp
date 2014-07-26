#include "inputmanager.h"

InputManager::InputManager() {

}

void InputManager::update() {
    al_get_keyboard_state(&keyState);
}

bool InputManager::isKeyPressed(ALLEGRO_EVENT event, int key) {
    if (event.type == ALLEGRO_EVENT_KEY_DOWN)
        if (event.keyboard.keycode == key)
            return true;
    return false;
}

bool InputManager::isKeyDown(int key) {
    if (al_key_down(&keyState, key))
        return true;
    return false;
}

bool InputManager::isKeyReleased(ALLEGRO_EVENT event, int key) {
    if (event.type == ALLEGRO_EVENT_KEY_UP)
        if (event.keyboard.keycode == key)
            return true;
    return false;
}
