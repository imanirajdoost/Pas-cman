#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include <SDL.h>
#include "model/MovableGameObject.h"
#include "Collider.h"

#include "Map.h"

/**
 * Handles collision between two objects
 */
class CollisionController {
    public:
    // Methods
        bool isWallDetectedAtDirection(const SDL_Rect& sourceRect, const MoveDirection& direction);
        Collider getRectAtDirection(const SDL_Rect& targetPos, const MoveDirection& direction);
        vector<Collider> getRectsAtDirection(const SDL_Rect& targetPos, const MoveDirection& direction);
        MTYPE getObjectTypeAt(const SDL_Rect& targetPos);
        SDL_Rect getRectAt(const SDL_Rect& targetPos);
        bool hasCollision(const SDL_Rect& rect1, const SDL_Rect& rect2);
        bool isCollision(const std::vector<std::vector<MTYPE>>& map, const MovableGameObject& targetObj, const MTYPE& obj, const SDL_Rect& collisionOffset);
        MTYPE getNextCOLOBJ(const std::vector<std::vector<MTYPE>>& map, const SDL_Rect& targetPos);

     // Variables
        const std::vector<std::vector<int>> collisionMatrix = {
        {0,1,0,1,1,0,1},
        {1,0,0,1,0,0,0},
        {0,0,0,0,0,0,0},
        {1,1,0,0,0,0,0},
        {1,1,0,0,0,0,0},
        {1,0,0,0,0,0,0},
        {1,0,0,0,0,0,0},
    };
};

#endif