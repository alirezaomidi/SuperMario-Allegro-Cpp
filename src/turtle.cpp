#include "turtle.h"

Turtle::Turtle(Position *pos) {
    image = al_load_bitmap("res/images/turtle.png");
    imageWidth = al_get_bitmap_width(image);
    imageHeight = al_get_bitmap_height(image);
    scaledWidth = imageWidth / 2 * SCALE;
    scaledHeight = imageHeight / 3 * SCALE;
    position = pos;
    box = new Rectangle(position->x, position->y, scaledWidth, scaledHeight);
    objectType = GameObject::Enemy;

    for (int i = 0; i < 2; i++)
        walk[i] = new Rectangle(imageWidth / 2 * i, imageHeight / 3 * 2, imageWidth / 2, imageHeight / 3);

    currentFrameNumber = 0;
    dir = Left;
    currentFrame = walk[0];
    moveSpeed = 1;
    gravity = 0.5;
    box = new Rectangle(position->x, position->y, scaledWidth, scaledHeight);
    isCollidable = true;
}

void Turtle::update(ALLEGRO_EVENT event) {
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

void Turtle::draw() {
    al_draw_scaled_bitmap(image, currentFrame->left, currentFrame->top, currentFrame->width, currentFrame->height
                          , box->left, box->top, scaledWidth, scaledHeight, 0);
}

void Turtle::moveLeft() {
    box->update(box->left - 5, box->top);
}
