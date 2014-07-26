#ifndef BLOCK_H
#define BLOCK_H

#include "gameobject.h"

class Block : public GameObject {
    int size;
public:
    Block(int size, Position *pos);
};

#endif // BLOCK_H
