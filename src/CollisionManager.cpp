#include "CollisionManager.h"
#include "Ghost.h"

#include <SDL.h>
#include <iostream>

bool CollisionManager::isCollision(Map map, SDL_Rect targetPos, COLOBJ obj) {

    MTYPE nextMapTile = map.map[targetPos.y][targetPos.x];

    COLOBJ nextTileObjType;

    switch (nextMapTile) {
        case COIN:
        case BCOIN:
            nextTileObjType = CCOIN;
            break;
        case WALL:
            nextTileObjType = CWALL;
            break;
        case TPR:
        case TPL:
            nextTileObjType = TP;
            break;
        case DOOR:
            nextTileObjType = CDOOR;
            break;
        case EMPTY:
            nextTileObjType = CEMPTY;
            break;
    }

    return CollisionManager::collisionMatrix[obj][nextTileObjType] == 1;    
}