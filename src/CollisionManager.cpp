#include "CollisionManager.h"
#include "Ghost.h"
#include "GameVars.h"

#include <SDL.h>
#include <iostream>

std::vector<std::vector<int>> CollisionManager::collisionMatrix = {
            {0,1,0,1,1,0,1},
            {1,0,0,1,0,0,0},
            {0,0,0,0,0,0,0},
            {1,1,0,0,0,0,0},
            {1,1,0,0,0,0,0},
            {1,0,0,0,0,0,0},
            {1,0,0,0,0,0,0}, 
        };

bool CollisionManager::isCollision(const std::vector<std::vector<MTYPE>>& map, const MovableGameObject& targetObj, const MTYPE& obj, const SDL_Rect& collisionOffset) {

    SDL_Rect targetPosWithOffset = targetObj.getNextPos();
    MoveDirection direction = targetObj.getMoveDirection();

    targetPosWithOffset.x += collisionOffset.x * TILESIZE;
    targetPosWithOffset.y += collisionOffset.y * TILESIZE;

    MTYPE TAGUEULE;
    SDL_Rect targetPos = targetPosWithOffset;

    switch (direction) {
        case MoveDirection::UP:
        case MoveDirection::DOWN:
            targetPos.x += TILESIZE-1;
            TAGUEULE = getNextCOLOBJ(map, targetPos);
            break;
        case MoveDirection::RIGHT:
        case MoveDirection::LEFT:
            targetPos.y += TILESIZE-1;
            TAGUEULE = getNextCOLOBJ(map, targetPos);

            break;
        default:
            // Possible none movement
            return true;
    }

    MTYPE nextMapTile = getNextCOLOBJ(map, targetPosWithOffset);

    return CollisionManager::collisionMatrix[static_cast<int>(obj)][static_cast<int>(nextMapTile)] ||
            CollisionManager::collisionMatrix[static_cast<int>(obj)][static_cast<int>(TAGUEULE)];
}

MTYPE CollisionManager::getNextCOLOBJ(const std::vector<std::vector<MTYPE>>& map, const SDL_Rect& targetPos) {
    
    int mapX = targetPos.x/TILESIZE;
    int mapY = targetPos.y/TILESIZE;

    MTYPE nextMapTile = map[mapY][mapX];
    std::cout << mapY << ", " << mapX << std::endl;

    return nextMapTile;
}

