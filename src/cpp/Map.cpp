#include <iostream>
#include "../header/Map.h"


vector<vector<MTYPE>> Map::map = {
        {MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL},
        {MTYPE::WALL,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::WALL,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::WALL},
        {MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL},
        {MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL},
        {MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL},
        {MTYPE::WALL,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::WALL},
        {MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL},
        {MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL},
        {MTYPE::WALL,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::WALL,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::WALL,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::WALL,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::WALL},
        {MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL},
        {MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::EMPTY,MTYPE::EMPTY,MTYPE::EMPTY,MTYPE::EMPTY,MTYPE::EMPTY,MTYPE::EMPTY,MTYPE::EMPTY,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL},
        {MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::EMPTY,MTYPE::WALL,MTYPE::DOOR,MTYPE::DOOR,MTYPE::DOOR,MTYPE::WALL,MTYPE::EMPTY,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL},
        {MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::EMPTY,MTYPE::WALL,MTYPE::EMPTY,MTYPE::EMPTY,MTYPE::EMPTY,MTYPE::WALL,MTYPE::EMPTY,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL},
        {MTYPE::TP,MTYPE::EMPTY,MTYPE::EMPTY,MTYPE::EMPTY,MTYPE::EMPTY,MTYPE::ITEM,MTYPE::EMPTY,MTYPE::EMPTY,MTYPE::WALL,MTYPE::EMPTY,MTYPE::EMPTY,MTYPE::EMPTY,MTYPE::WALL,MTYPE::EMPTY,MTYPE::EMPTY,MTYPE::ITEM,MTYPE::EMPTY,MTYPE::EMPTY,MTYPE::EMPTY,MTYPE::EMPTY,MTYPE::TP},
        {MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::EMPTY,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::EMPTY,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL},
        {MTYPE::WALL,MTYPE::EMPTY,MTYPE::EMPTY,MTYPE::EMPTY,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::EMPTY,MTYPE::EMPTY,MTYPE::EMPTY,MTYPE::EMPTY,MTYPE::EMPTY,MTYPE::EMPTY,MTYPE::EMPTY,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::EMPTY,MTYPE::EMPTY,MTYPE::EMPTY,MTYPE::WALL},
        {MTYPE::WALL,MTYPE::EMPTY,MTYPE::EMPTY,MTYPE::EMPTY,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::EMPTY,MTYPE::EMPTY,MTYPE::EMPTY,MTYPE::WALL},
        {MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL},
        {MTYPE::WALL,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::WALL,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::WALL},
        {MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL},
        {MTYPE::WALL,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::WALL,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::EMPTY,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::WALL,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::WALL},
        {MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL},
        {MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL},
        {MTYPE::WALL,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::WALL,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::WALL,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::WALL,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::WALL},
        {MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::ITEM,MTYPE::WALL},
        {MTYPE::WALL,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::ITEM,MTYPE::WALL},
        {MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL,MTYPE::WALL},
};

template <typename T>
MTYPE Map::getCurrentTileType(const T& gameObject) const{

    int px_x = gameObject->getX();
    int px_y = gameObject->getY();

    int map_x = px_x / 32;
    int map_y = px_y / 32;

    if ((map_x < 0 || map_x > 20) || (map_y < 0 || map_y > 26)) {
        std::cerr << "An error with the char_map coordonites (dont know how to fucking spell that word) has occured\n" << std::endl;
    }

    return map[map_y][map_x];
}