#include "owl.h"

Owl::Owl(Position *pos) {
    image = al_load_bitmap("res/images/owl.png");
    imageWidth = al_get_bitmap_width(image);
    imageHeight = al_get_bitmap_height(image);
    scaledWidth = imageWidth / 2 * SCALE;
    scaledHeight = imageHeight * SCALE;
    position = pos;
    box = new Rectangle(position->x, position->y, scaledWidth, scaledHeight);
    objectType = GameObject::Enemy;

    for (int i = 0; i < 2; i++)
        walk[i] = new Rectangle(imageWidth / 2 * i, 0, imageWidth / 2, imageHeight);

    currentFrameNumber = 1;
    dir = Left;
    currentFrame = walk[1];
    moveSpeed = 1;
    gravity = 0.5;
    box = new Rectangle(position->x, position->y, scaledWidth, scaledHeight);
    isCollidable = true;
}

void Owl::update(ALLEGRO_EVENT event) {
    if (dir == Left) {
        if (!isObstacleOnLeft)
            velocity.first = -moveSpeed;
    } else {
        if (!isObstacleOnRight)
            velocity.first = moveSpeed;
    }
    currentFrameNumber += frameChangeSpeed;
    if (currentFrameNumber >= 4)
        currentFrameNumber = 0;
    currentFrame = walk[(int)currentFrameNumber / 2];
}

void Owl::draw() {
    al_draw_scaled_bitmap(image, currentFrame->left, currentFrame->top, currentFrame->width, currentFrame->height
                          , box->left, box->top, scaledWidth, scaledHeight, 0);
}

void Owl::moveLeft() {
    box->update(box->left - 5, box->top);
}
