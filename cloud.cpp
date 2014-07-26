#include "cloud.h"

Cloud::Cloud(CloudType type, Position *pos) : type(type) {
    switch (type) {
    case Cloud::Big:
        image = al_load_bitmap("res/images/cloud-big.png");
        break;
    case Cloud::Medium:
        image = al_load_bitmap("res/images/cloud-medium.png");
        break;
    case Cloud::Small:
        image = al_load_bitmap("res/images/cloud-small.png");
        break;
    }
    imageWidth = al_get_bitmap_width(image);
    imageHeight = al_get_bitmap_height(image);
    scaledWidth = imageWidth * SCALE;
    scaledHeight = imageHeight * SCALE;
    position = pos;
    box = new Rectangle(position->x, position->y, scaledWidth, scaledHeight);
    objectType = GameObject::Cloud;
}

void Cloud::update(ALLEGRO_EVENT event) {

}

void Cloud::draw() {
    al_draw_scaled_bitmap(image, 0, 0, imageWidth, imageHeight, box->left, box->top, scaledWidth, scaledHeight, 0);
}

void Cloud::moveLeft() {
    box->update(box->left - 5, box->top);
}
