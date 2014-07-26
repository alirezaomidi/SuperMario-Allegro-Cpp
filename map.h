#ifndef MAP_H
#define MAP_H

#include "maploader.h"
#include "gameobject.h"
#include "position.h"
#include "block.h"
#include "bush.h"
#include "castle.h"
#include "cloud.h"
#include "hill.h"
#include "pipe.h"
#include "secretbox.h"
#include "wall.h"
#include "brick.h"
#include "flag.h"
#include "owl.h"
#include "turtle.h"
#include <string>

class Map {
private:
    MapLoader loader;
    const static int numOfObjects = 30;
    std::string objectNames[numOfObjects];

    void initObjectNames();
public:
    std::vector<GameObject*> *objects;
    Map(std::string mapID);

    void update(ALLEGRO_EVENT event);
    void draw();
    void moveMapToLeft();
};

#endif // MAP_H
