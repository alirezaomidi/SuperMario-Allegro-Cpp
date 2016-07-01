#include "wall.h"

Wall::Wall(std::pair<int, int> xRange, int y): xRange(xRange), y(y) {
    image = al_load_bitmap("res/images/wall.png");
    imageWidth = al_get_bitmap_width(image);
    imageHeight = al_get_bitmap_height(image);
    scaledWidth = imageWidth * SCALE;
    scaledHeight = imageHeight * SCALE;
    isCollidable = true;
    width = xRange.second - xRange.first;
    height = 100;

    box = new Rectangle(xRange.first, y, width, height);
    objectType = GameObject::Wall;
}

void Wall::update(ALLEGRO_EVENT event) {

}

void Wall::draw() {
    for (int i = box->left; i < box->right; i += scaledWidth) {
        for (int j = y; j < y + height; j += scaledHeight) {
            al_draw_scaled_bitmap(image, 0, 0, imageWidth, imageHeight, i, j, scaledWidth, scaledHeight, 0);
        }
    }
}

void Wall::moveLeft() {
    box->update(box->left - 5, box->top);
}
