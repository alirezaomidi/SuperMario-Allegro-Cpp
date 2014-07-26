#include "map.h"

void Map::initObjectNames() {
    objectNames[0] = "hill-big";
    objectNames[1] = "hill-small";
    objectNames[2] = "bush-big";
    objectNames[3] = "bush-medium";
    objectNames[4] = "bush-small";
    objectNames[5] = "wall";
    objectNames[6] = "cloud-big";
    objectNames[7] = "cloud-medium";
    objectNames[8] = "cloud-small";
    objectNames[9] = "castle";
    objectNames[10] = "pipe-big";
    objectNames[11] = "pipe-medium";
    objectNames[12] = "pipe-small";
    objectNames[13] = "secret-box-coin";
    objectNames[14] = "secret-box-mushroom";
    objectNames[15] = "hidden-secret-box";
    objectNames[16] = "brick-secret-box-coin";
    objectNames[17] = "brick-secret-box-star";
    objectNames[18] = "brick";
    objectNames[19] = "block-1";
    objectNames[20] = "block-2";
    objectNames[21] = "block-3";
    objectNames[22] = "block-4";
    objectNames[23] = "block-5";
    objectNames[24] = "block-6";
    objectNames[25] = "block-7";
    objectNames[26] = "block-8";
    objectNames[27] = "flag";
    objectNames[28] = "owl";
    objectNames[29] = "turtle";
}

Map::Map(std::string mapID) {
    initObjectNames();
    loader.loadMap(mapID);
    objects = new std::vector<GameObject*>;
    for (int i = 0; i < loader.objects.size(); i++) {
        float x, y;
        std::pair<float, float> xRange;
        std::string xString, yString;
        bool isX = true;
        for (int j = 0; j < loader.objects[i].second.length(); j++) {
            if (loader.objects[i].second[j] == ',') {
                isX = false;
                continue;
            }
            if (isX)
                xString += loader.objects[i].second[j];
            else
                yString += loader.objects[i].second[j];
        }

        if (loader.objects[i].first != "wall") {
            x = atof(xString.c_str());
        } else {
            int dashPos = xString.find('-');
            x = xRange.first = atof(xString.substr(0, dashPos).c_str());
            xRange.second = atof(xString.substr(dashPos + 1, xString.length() - dashPos - 1).c_str());
        }
        y = atoi(yString.c_str());

        x *= SCALE;
        y *= SCALE;
        xRange.first *= SCALE;
        xRange.second *= SCALE;

        if (loader.objects[i].first == objectNames[0]) {
            objects->push_back(new Hill(Hill::Big, new Position(x, y)));
        } else if (loader.objects[i].first == objectNames[1]) {
            objects->push_back(new Hill(Hill::Small, new Position(x, y)));
        } else if (loader.objects[i].first == objectNames[2]) {
            objects->push_back(new Bush(Bush::Big, new Position(x, y)));
        } else if (loader.objects[i].first == objectNames[3]) {
            objects->push_back(new Bush(Bush::Medium, new Position(x, y)));
        } else if (loader.objects[i].first == objectNames[4]) {
            objects->push_back(new Bush(Bush::Small, new Position(x, y)));
        } else if (loader.objects[i].first == objectNames[5]) {
            objects->push_back(new Wall(xRange, y));
        } else if (loader.objects[i].first == objectNames[6]) {
            objects->push_back(new Cloud(Cloud::Big, new Position(x, y)));
        } else if (loader.objects[i].first == objectNames[7]) {
            objects->push_back(new Cloud(Cloud::Medium, new Position(x, y)));
        } else if (loader.objects[i].first == objectNames[8]) {
            objects->push_back(new Cloud(Cloud::Small, new Position(x, y)));
        } else if (loader.objects[i].first == objectNames[9]) {
            objects->push_back(new Castle(new Position(x, y)));
        } else if (loader.objects[i].first == objectNames[10]) {
            objects->push_back(new Pipe(Pipe::Big, new Position(x, y)));
        } else if (loader.objects[i].first == objectNames[11]) {
            objects->push_back(new Pipe(Pipe::Medium, new Position(x, y)));
        } else if (loader.objects[i].first == objectNames[12]) {
            objects->push_back(new Pipe(Pipe::Small, new Position(x, y)));
        } else if (loader.objects[i].first == objectNames[13]) {
            objects->push_back(new SecretBox(SecretBox::Coin, new Position(x, y)));
        } else if (loader.objects[i].first == objectNames[14]) {
            objects->push_back(new SecretBox(SecretBox::Mushroom, new Position(x, y)));
        } else if (loader.objects[i].first == objectNames[15]) {
            objects->push_back(new SecretBox(SecretBox::Hidden, new Position(x, y)));
        } else if (loader.objects[i].first == objectNames[16]) {
            objects->push_back(new SecretBox(SecretBox::Brick_Coin, new Position(x, y)));
        } else if (loader.objects[i].first == objectNames[17]) {
            objects->push_back(new SecretBox(SecretBox::Brick_Star, new Position(x, y)));
        } else if (loader.objects[i].first == objectNames[18]) {
            objects->push_back(new Brick(new Position(x, y)));
        } else if (loader.objects[i].first == objectNames[19]) {
            objects->push_back(new Block(1, new Position(x, y)));
        } else if (loader.objects[i].first == objectNames[20]) {
            objects->push_back(new Block(2, new Position(x, y)));
        } else if (loader.objects[i].first == objectNames[21]) {
            objects->push_back(new Block(3, new Position(x, y)));
        } else if (loader.objects[i].first == objectNames[22]) {
            objects->push_back(new Block(4, new Position(x, y)));
        } else if (loader.objects[i].first == objectNames[23]) {
            objects->push_back(new Block(5, new Position(x, y)));
        } else if (loader.objects[i].first == objectNames[24]) {
            objects->push_back(new Block(6, new Position(x, y)));
        } else if (loader.objects[i].first == objectNames[25]) {
            objects->push_back(new Block(7, new Position(x, y)));
        } else if (loader.objects[i].first == objectNames[26]) {
            objects->push_back(new Block(8, new Position(x, y)));
        } else if (loader.objects[i].first == objectNames[27]) {
            objects->push_back(new Flag(new Position(x, y)));
        } else if (loader.objects[i].first == objectNames[28]) {
            objects->push_back(new Owl(new Position(x, y)));
        }/* else if (loader.objects[i].first == objectNames[29]) {
            objects->push_back(new Turtle(new Position(x, y)));
        }*/
    }
}

void Map::update(ALLEGRO_EVENT event) {
    for (std::vector<GameObject*>::iterator itr = objects->begin(); itr != objects->end(); itr++) {
        (*itr)->update(event);
    }
}

void Map::draw() {
    for (std::vector<GameObject*>::iterator itr = objects->begin(); itr != objects->end(); itr++) {
        (*itr)->draw();
    }
}

void Map::moveMapToLeft() {
    for (std::vector<GameObject*>::iterator itr = objects->begin(); itr != objects->end(); itr++) {
        (*itr)->moveLeft();
    }
}
