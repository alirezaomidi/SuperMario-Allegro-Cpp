#include "secretbox.h"

SecretBox::SecretBox(SecretBoxType type, Position *pos): type(type) {
    switch (type) {
    case SecretBox::Coin:
    case SecretBox::Mushroom:
        image = al_load_bitmap("res/images/secret-box.png");
        break;
    case SecretBox::Brick_Coin:
    case SecretBox::Brick_Star:
        image = al_load_bitmap("res/images/brick.png");
        break;
    case SecretBox::Hidden:
        image = al_load_bitmap("res/images/solid.png");
        isHidden = true;
        break;
    }
    imageWidth = al_get_bitmap_width(image);
    imageHeight = al_get_bitmap_height(image);
    scaledWidth = imageWidth * SCALE;
    scaledHeight = imageHeight * SCALE;
    position = pos;
    box = new Rectangle(position->x, position->y, scaledWidth, scaledHeight);
    objectType = GameObject::SecretBox;
}

void SecretBox::update(ALLEGRO_EVENT event){

}

void SecretBox::draw(){
    al_draw_scaled_bitmap(image, 0, 0, imageWidth, imageHeight, box->left, box->top, scaledWidth, scaledHeight, 0);
}

void SecretBox::moveLeft() {
    box->update(box->left - 5, box->top);
}
