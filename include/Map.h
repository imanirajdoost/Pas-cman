#ifndef MAP_H
#define MAP_H

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
    
    static MTYPE map[27][21];

    template <typename T>
    MTYPE getCurrentTileType(const T& gameObject) const;
};

#endif