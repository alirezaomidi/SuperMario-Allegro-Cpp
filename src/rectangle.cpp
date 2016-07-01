#include "rectangle.h"

Rectangle::Rectangle(float x, float y, float w, float h) {
    left = x;
    top = y;
    right = x + w;
    bottom = y + h;
    width = w;
    height = h;
}

int Rectangle::intersects(Rectangle *rect) {
    int res = Rectangle::None;
    if (!(this->right < rect->left || this->top > rect->bottom || this->left > rect->right || this->bottom < rect->top)) {
        if (this->right >= rect->left && this->left <= rect->left)
            res |= Rectangle::Right;
        if (this->top <= rect->bottom && this->bottom >= rect->bottom)
            res |= Rectangle::Top;
        if (this->left <= rect->right && this->right >= rect->right)
            res |= Rectangle::Left;
        if (this->bottom >= rect->top && this->top <= rect->top)
            res |= Rectangle::Bottom;
    }
    return res;
}

void Rectangle::update(float x, float y) {
    left = x;
    top = y;
    right = left + width;
    bottom = top + height;
}

void Rectangle::updateWithBottom(float bottom) {
    this->bottom = bottom;
    this->top = this->bottom - height;
}

void Rectangle::updateWithLeft(float left) {
    this->left = left;
    this->right = this->left + width;
}

void Rectangle::updateWithRight(float right) {
    this->right = right;
    this->left = this->right - width;
}

void Rectangle::updateWithTop(float top) {
    this->top = top;
    this->bottom = this->top + height;
}
