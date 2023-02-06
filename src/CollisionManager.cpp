#include "CollisionManager.h"
#include "Ghost.h"
#include "GameVars.h"

#include <SDL.h>
#include <iostream>

int CollisionManager::collisionMatrix[7][7] = {
            {0,1,1,1,1,1,0},
            {1,0,1,0,1,0,0},
            {1,1,0,0,0,0,0},
            {1,0,0,0,0,0,0},
            {1,1,0,0,0,0,0},
            {1,0,0,0,0,0,0},
            {0,0,0,0,0,0,0}, 
        };

bool CollisionManager::isCollision(const Map& map, const SDL_Rect& targetPos, const COLOBJ& obj, const SDL_Rect& collisionOffset) {

    SDL_Rect targetPosWithOffset = targetPos;
    targetPosWithOffset.x += collisionOffset.x * collisionOffset.w;
    targetPosWithOffset.y += collisionOffset.y * collisionOffset.h;

    

    MTYPE nextMapTile = getNextCOLOBJ(map, targetPosWithOffset);

    COLOBJ nextTileObjType;

    switch (nextMapTile) {
        case MTYPE::COIN:
        case MTYPE::BCOIN:
            nextTileObjType = COLOBJ::CCOIN;
            break;
        case MTYPE::WALL:
            nextTileObjType = COLOBJ::CWALL;
            break;
        case MTYPE::TPR:
        case MTYPE::TPL:
            nextTileObjType = COLOBJ::TP;
            break;
        case MTYPE::DOOR:
            nextTileObjType = COLOBJ::CDOOR;
            break;
        case MTYPE::EMPTY:
            nextTileObjType = COLOBJ::CEMPTY;
            break;
    }

    return CollisionManager::collisionMatrix[static_cast<int>(obj)][static_cast<int>(nextTileObjType)] == 1;
}

MTYPE CollisionManager::getNextCOLOBJ(const Map& map, const SDL_Rect& targetPos) {
    
    int mapX = targetPos.x/TILESIZE;
    int mapY = targetPos.y/TILESIZE;

    MTYPE nextMapTile = map.map[mapY][mapX];

    return nextMapTile;
}

