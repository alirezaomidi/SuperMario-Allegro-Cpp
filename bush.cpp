#include "bush.h"

Bush::Bush(BushType type, Position *pos) : type(type) {
    switch (type) {
    case Bush::Big:
        image = al_load_bitmap("res/images/bush-big.png");
        break;
    case Bush::Medium:
        image = al_load_bitmap("res/images/bush-medium.png");
        break;
    case Bush::Small:
        image = al_load_bitmap("res/images/bush-small.png");
        break;
    }
    imageWidth = al_get_bitmap_width(image);
    imageHeight = al_get_bitmap_height(image);
    scaledWidth = imageWidth * SCALE;
    scaledHeight = imageHeight * SCALE;
    position = pos;
    box = new Rectangle(position->x, position->y, scaledWidth, scaledHeight);
    objectType = GameObject::Bush;
}

void Bush::update(ALLEGRO_EVENT event) {

}

void Bush::draw() {
    al_draw_scaled_bitmap(image, 0, 0, imageWidth, imageHeight, box->left, box->top, scaledWidth, scaledHeight, 0);
}

void Bush::moveLeft() {
    box->update(box->left - 5, box->top);
}
