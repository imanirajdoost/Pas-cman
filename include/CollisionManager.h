#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include <SDL.h>

#include "Map.h"

class CollisionManager {
    public:
        static bool isCollision(const std::vector<std::vector<MTYPE>>& map, const SDL_Rect& targetPos, const MTYPE& obj, const SDL_Rect& collisionOffset);
        static MTYPE getNextCOLOBJ(const std::vector<std::vector<MTYPE>>& map, const SDL_Rect& targetPos);
        // int [7][7]
        static std::vector<std::vector<int>> collisionMatrix;
};

#endif