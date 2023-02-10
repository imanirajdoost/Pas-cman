#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include <SDL.h>
#include "MovableGameObject.h"
#include "Collider.h"

#include "Map.h"

class CollisionManager {
    public:
        static bool isWallDetectedAtDirection(const SDL_Rect& sourceRect, const MoveDirection& direction);
        static Collider getRectAtDirection(const SDL_Rect& targetPos, const MoveDirection& direction);
        static vector<Collider> getRectsAtDirection(const SDL_Rect& targetPos, const MoveDirection& direction);
        static MTYPE getObjectTypeAt(const SDL_Rect& targetPos);
//        static MTYPE getObjectsTypeAt(const SDL_Rect& targetPos);
        static SDL_Rect getRectAt(const SDL_Rect& targetPos);
        static bool hasCollision(const SDL_Rect& rect1, const SDL_Rect& rect2);
        static bool isCollision(const std::vector<std::vector<MTYPE>>& map, const MovableGameObject& targetObj, const MTYPE& obj, const SDL_Rect& collisionOffset);
        static MTYPE getNextCOLOBJ(const std::vector<std::vector<MTYPE>>& map, const SDL_Rect& targetPos);
        // int [7][7]
        static std::vector<std::vector<int>> collisionMatrix;
};

#endif