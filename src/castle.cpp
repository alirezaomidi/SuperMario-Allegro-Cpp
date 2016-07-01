#include "castle.h"

Castle::Castle(Position *pos) {
    image = al_load_bitmap("res/images/castle.png");
    position = pos;
    imageWidth = al_get_bitmap_width(image);
    imageHeight = al_get_bitmap_height(image);
    scaledWidth = imageWidth * SCALE;
    scaledHeight = imageHeight * SCALE;
    box = new Rectangle(position->x, position->y, scaledWidth, scaledHeight);
    objectType = GameObject::Castle;
}

void Castle::update(ALLEGRO_EVENT event) {

}

void Castle::draw() {
    al_draw_scaled_bitmap(image, 0, 0, imageWidth, imageHeight, box->left, box->top, scaledWidth, scaledHeight, 0);
}

void Castle::moveLeft() {
    box->update(box->left - 5, box->top);
}
