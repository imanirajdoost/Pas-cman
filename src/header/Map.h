#ifndef MAP_H
#define MAP_H

#include <vector>

using namespace std;

enum class MTYPE {
    PACMAN,
    GHOST,
    EMPTY,
    WALL,
    DOOR,
    ITEM,
    TP,
};

class Map {
public:

    // original char_map size is [27][21]
    static vector<vector<MTYPE>> map;

    template <typename T>
    MTYPE getCurrentTileType(const T& gameObject) const;
};

#endif