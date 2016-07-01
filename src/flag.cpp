#include "flag.h"

Flag::Flag(Position *pos) {
    image = al_load_bitmap("res/images/flag.png");
    imageWidth = al_get_bitmap_width(image);
    imageHeight = al_get_bitmap_height(image);
    scaledWidth = imageWidth * SCALE;
    scaledHeight = imageHeight * SCALE;
    position = pos;
    box = new Rectangle(position->x, position->y, scaledWidth, scaledHeight);
    objectType = GameObject::Bush;
}

void Flag::update(ALLEGRO_EVENT event) {

}

void Flag::draw() {
    al_draw_scaled_bitmap(image, 0, 0, imageWidth, imageHeight, box->left, box->top, scaledWidth, scaledHeight, 0);
}

void Flag::moveLeft() {
    box->update(box->left - 5, box->top);
}
