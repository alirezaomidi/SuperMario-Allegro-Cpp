#include "block.h"

Block::Block(int size, Position *pos) : size(size) {
    image = al_load_bitmap("res/images/block.png");
    imageWidth = al_get_bitmap_width(image);
    imageHeight = al_get_bitmap_height(image);
    scaledWidth = imageWidth * SCALE;
    scaledHeight = imageHeight * SCALE;
    position = pos;
    box = new Rectangle(position->x, position->y, scaledWidth, scaledHeight);
    objectType = GameObject::Block;
}
