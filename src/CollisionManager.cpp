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

bool CollisionManager::isCollision(const std::vector<std::vector<MTYPE>>& map, const SDL_Rect& targetPos, const MTYPE& obj, const SDL_Rect& collisionOffset) {

    SDL_Rect targetPosWithOffset = targetPos;

    targetPosWithOffset.x += collisionOffset.x * TILESIZE;
    targetPosWithOffset.y += collisionOffset.y * TILESIZE;

    MTYPE nextMapTile = getNextCOLOBJ(map, targetPosWithOffset);

    return CollisionManager::collisionMatrix[static_cast<int>(obj)][static_cast<int>(nextMapTile)] == 1;
}

MTYPE CollisionManager::getNextCOLOBJ(const std::vector<std::vector<MTYPE>>& map, const SDL_Rect& targetPos) {
    
    int mapX = targetPos.x/TILESIZE;
    int mapY = targetPos.y/TILESIZE;

    MTYPE nextMapTile = map[mapY][mapX];

    return nextMapTile;
}

