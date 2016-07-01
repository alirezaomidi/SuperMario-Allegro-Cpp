#include "mario.h"

void Mario::initMarioRects() {
    imageHeight = al_get_bitmap_height(image);
    imageWidth = al_get_bitmap_width(image);
    scaledWidth = imageWidth / 3 * SCALE;
    scaledHeight = imageHeight / 3 * SCALE;
    stand = new Rectangle(imageWidth / 3 * 2, imageHeight / 3, imageWidth / 3, imageHeight / 3);
    run = new Rectangle(imageWidth / 3, imageHeight / 3, imageWidth / 3, imageHeight / 3);
    crouchOrDie = new Rectangle(0, 0, imageWidth / 3, imageHeight / 3);
    for (int i = 0; i < 2; i++)
        hang[i] = new Rectangle(imageWidth / 3 * (i + 1), 0, imageWidth / 3, imageHeight / 3);
    for (int i = 0; i < 3; i++)
        walk[i] = new Rectangle(imageWidth / 3 * i, imageHeight / 3 * 2, imageWidth / 3, imageHeight / 3);
}

Mario::Mario(SoundManager *sound) {
    image = al_load_bitmap("res/images/mario-small.png");
    type = Mario::Small;
    initMarioRects();
    currentFrame = stand;
    jumpSpeed = 9;
    moveSpeed = 5;
    gravity = 0.5;
    position = new Position(32 * SCALE, 184 * SCALE);
    box = new Rectangle(position->x, position->y, scaledWidth, scaledHeight);
    objectType = GameObject::Mario;
    isCollidable = true;

    this->sound = sound;
}

void Mario::loadContent() {

}

void Mario::unloadContect() {

}

void Mario::update(ALLEGRO_EVENT event, InputManager input) {
    input.update();
    if (input.isKeyDown(ALLEGRO_KEY_UP) || input.isKeyDown(ALLEGRO_KEY_DOWN)
            || input.isKeyDown(ALLEGRO_KEY_LEFT) || input.isKeyDown(ALLEGRO_KEY_RIGHT)) {
        if (input.isKeyDown(ALLEGRO_KEY_UP)) {
            if (!isOnAir) {
                if (type == Mario::Big)
                    sound->playJumpBig();
                else
                    sound->playJumpSmall();
                dir = Up;
                isOnAir = true;
                velocity.second = -jumpSpeed;
                activeGravity = true;
            }
        } if (input.isKeyDown(ALLEGRO_KEY_LEFT)) {
            dir = Left;
            rightOrLeftFlag = 1;
            if (!isObstacleOnLeft)
                velocity.first = -moveSpeed;
            currentFrameNumber += frameChangeSpeed;
            if (currentFrameNumber >= 9)
                currentFrameNumber = 0;
            currentFrame = walk[(int)currentFrameNumber / 3];
        } if (input.isKeyDown(ALLEGRO_KEY_RIGHT)) {
            dir = Right;
            rightOrLeftFlag = 0;
            if (!isObstacleOnRight)
                velocity.first = moveSpeed;
            currentFrameNumber += frameChangeSpeed;
            if (currentFrameNumber >= 9)
                currentFrameNumber = 0;
            currentFrame = walk[(int)currentFrameNumber / 3];
        } if (input.isKeyDown(ALLEGRO_KEY_DOWN)){
            dir = Down;
        }
    } else {
        velocity.first = 0;
    }

    if (velocity.first == 0 && velocity.second == 0) {
        currentFrame = stand;
        currentFrameNumber = 0;
    }

    if (activeGravity)
        velocity.second += gravity;

    position->x += velocity.first;
    position->y += velocity.second;

    box->update(position->x, position->y);

    isObstacleOnBottom = isObstacleOnLeft = isObstacleOnRight = isObstacleOnTop = false;
}
void Mario::draw() {
    al_draw_scaled_bitmap(image, currentFrame->left, currentFrame->top, currentFrame->width, currentFrame->height
                          , box->left, box->top, scaledWidth, scaledHeight, rightOrLeftFlag);
}

bool Mario::haveCollideWith(GameObject *obj) {
    if (this->isCollidable && obj->isCollidable && this->box->intersects(obj->box)) {
        return true;
    }
    return false;
}

void Mario::collide(GameObject *obj) {
    if (obj->objectType == GameObject::Wall) {
        velocity.second = 0;
        box->updateWithBottom(obj->box->top);
        isOnAir = false;
        activeGravity = false;
    } else if (obj->objectType == GameObject::Pipe) {
        int edge = this->box->intersects(obj->box);
        if ((edge & Rectangle::Bottom) == Rectangle::Bottom) {
            velocity.second = 0;
            box->updateWithBottom(obj->box->top);
            isObstacleOnBottom = true;
            isOnAir = false;
            activeGravity = false;
        } if ((edge & Rectangle::Right) == Rectangle::Right) {
            velocity.first = 0;
            box->updateWithRight(obj->box->left);
            isObstacleOnRight = true;
        } if ((edge & Rectangle::Left) == Rectangle::Left) {
            velocity.first = 0;
            box->updateWithLeft(obj->box->right);
            isObstacleOnLeft = true;
        }
    } else if (obj->objectType == GameObject::Enemy) {
        sound->PlayPlayerDie();
    }
}
