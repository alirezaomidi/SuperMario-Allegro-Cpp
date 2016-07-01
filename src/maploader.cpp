#include "maploader.h"

MapLoader::MapLoader() {

}

void MapLoader::loadMap(std::string mapID) {
    std::string mapPath = "res/maps/map" + mapID + ".map";
    std::ifstream openedMap(mapPath.c_str());

    while (openedMap) {
        std::string line;
        std::getline(openedMap, line);
        int i = line.find(']');
        if (i != -1)
            objects.push_back(std::make_pair(line.substr(1, i - 1), line.substr(i + 2, line.length() - i - 3)));
        else
            break;
    }
}
