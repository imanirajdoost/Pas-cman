#include <iostream>
#include "Map.h"

Map::Map() {}

template <typename T>
MTYPE Map::getCurrentTileType(T gameObject) {

    int px_x = gameObject->getX();
    int px_y = gameObject->getY();

    int map_x = px_x / 32;
    int map_y = px_y / 32;

    if ((map_x < 0 || map_x > 20) || (map_y < 0 || map_y > 26)) {
        std::cerr << "An error with the map coordonites (dont know how to fucking spell that word) has occured\n" << std::endl;
    }

    return map[map_y][map_x];
}