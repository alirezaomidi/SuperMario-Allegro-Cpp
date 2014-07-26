#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
public:
    float left, right, top, bottom, width, height;
    Rectangle(float x, float y, float w, float h);
    enum Edge {Top = 1, Bottom = 2, Left = 4, Right = 8, None = 0};
    int intersects(Rectangle *box);
    void update(float x, float y);
    void updateWithBottom(float bottom);
    void updateWithLeft(float left);
    void updateWithRight(float right);
    void updateWithTop(float top);
};

#endif // FLOATRECT_H
