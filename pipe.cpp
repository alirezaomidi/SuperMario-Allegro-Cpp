#include "pipe.h"

Pipe::Pipe(PipeType type, Position *pos) : type(type) {
    switch (type) {
    case Pipe::Big:
        image = al_load_bitmap("res/images/pipe-big.png");
        break;
    case Pipe::Medium:
        image = al_load_bitmap("res/images/pipe-medium.png");
        break;
    case Pipe::Small:
        image = al_load_bitmap("res/images/pipe-small.png");
        break;
    }
    position = pos;
    isCollidable = true;
    imageWidth = al_get_bitmap_width(image);
    imageHeight = al_get_bitmap_height(image);
    scaledWidth = imageWidth * SCALE;
    scaledHeight = imageHeight * SCALE;
    box = new Rectangle(position->x, position->y, scaledWidth, scaledHeight);
    objectType = GameObject::Pipe;
}

void Pipe::update(ALLEGRO_EVENT event) {

}

void Pipe::draw() {
     al_draw_scaled_bitmap(image, 0, 0, imageWidth, imageHeight, box->left, box->top, scaledWidth, scaledHeight, 0);
}

void Pipe::moveLeft() {
    box->update(box->left - 5, box->top);
}
