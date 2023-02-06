#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include <SDL.h>

#include "Map.h"

enum class COLOBJ {
    PACMAN,
    GHOST,
    CWALL,
    CCOIN,
    TP,
    CDOOR, 
    CEMPTY
};

class CollisionManager {
    public:
        static bool isCollision(const Map& map, const SDL_Rect& targetPos, const COLOBJ& obj, const SDL_Rect& collisionOffset);
        static MTYPE getNextCOLOBJ(const Map& map, const SDL_Rect& targetPos);
        static int collisionMatrix[7][7];
};

#endif