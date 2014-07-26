#ifndef SECRETBOX_H
#define SECRETBOX_H

#include "gameobject.h"

class SecretBox : public GameObject {
private:
    bool isHidden = false;
public:
    enum SecretBoxType {Coin, Mushroom, Brick_Coin, Brick_Star, Hidden};
    SecretBoxType type;
    SecretBox(SecretBoxType type, Position *pos);

    void update(ALLEGRO_EVENT event);
    void draw();
    void moveLeft();
};

#endif // SECRETBOX_H
