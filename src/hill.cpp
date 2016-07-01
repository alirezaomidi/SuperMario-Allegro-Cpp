#include "hill.h"

Hill::Hill(HillType type, Position *pos) : type(type) {
    switch (type) {
    case Hill::Big:
        image = al_load_bitmap("res/images/hill-big.png");
        break;
    case Hill::Small:
        image = al_load_bitmap("res/images/hill-small.png");
        break;
    }
    imageWidth = al_get_bitmap_width(image);
    imageHeight = al_get_bitmap_height(image);
    scaledWidth = imageWidth * SCALE;
    scaledHeight = imageHeight * SCALE;
    position = pos;
    box = new Rectangle(position->x, position->y, scaledWidth, scaledHeight);
    objectType = GameObject::Hill;
}

void Hill::update(ALLEGRO_EVENT event) {

}

void Hill::draw() {
    al_draw_scaled_bitmap(image, 0, 0, imageWidth, imageHeight, box->left, box->top, scaledWidth, scaledHeight, 0);
}

void Hill::moveLeft() {
    box->update(box->left - 5, box->top);
}
