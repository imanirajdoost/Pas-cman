#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include <SDL.h>

#include "Map.h"

class CollisionManager {
    public:
        static bool isCollision(const MTYPE map[27][21], const SDL_Rect& targetPos, const MTYPE& obj, const SDL_Rect& collisionOffset);
        static MTYPE getNextCOLOBJ(const MTYPE map[27][21], const SDL_Rect& targetPos);
        static int collisionMatrix[7][7];
};

#endif