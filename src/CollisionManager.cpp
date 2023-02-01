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

bool CollisionManager::isCollision(Map map, SDL_Rect targetPos, COLOBJ obj) {

    // std::cout << "x: " << targetPos.x << std::endl;
    // std::cout << "y: " << targetPos.y << std::endl;

    int mapX = targetPos.x/TILESIZE;
    int mapY = targetPos.y/TILESIZE;

    // std::cout << "mapx: " << mapX << std::endl;
    // std::cout << "mapy: " << mapY << std::endl;

    // std::cout << "tile: " << map.map[mapX][mapY] << std::endl; 

    MTYPE nextMapTile = map.map[mapX][mapY];

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