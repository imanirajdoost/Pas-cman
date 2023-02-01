#include "CollisionManager.h"
#include "Ghost.h"

#include <SDL.h>
#include <iostream>

template <typename T>
bool CollisionManager::isCollision(Map map, SDL_Rect targetPos, COLOBJ obj) {

    MTYPE nextMapTile = map.map[targetPos.y][targetPos.x];

    COLOBJ nextTileObjType;

    switch (nextMapTile) {
        case COIN:
        case BCOIN:
            nextTileObjType = COIN;
            break;
        case WALL:
            nextTileObjType = WALL;
            break;
        case TPR:
        case TPL:
            nextTileObjType = TP;
            break;
        case DOOR:
            nextTileObjType = DOOR;
            break;
        case EMPTY:
            nextTileObjType = EMPTY;
            break;
    }

    return CollisionManager::collisionMatrix[obj][nextTileObjType] == 1;

}