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

bool CollisionManager::isCollision(const Map& map, const SDL_Rect& targetPos, const COLOBJ& obj) {

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
            nextTileObjType = COLOBJ::CCOIN;
            break;
        case WALL:
            nextTileObjType = COLOBJ::CWALL;
            break;
        case TPR:
        case TPL:
            nextTileObjType = COLOBJ::TP;
            break;
        case DOOR:
            nextTileObjType = COLOBJ::CDOOR;
            break;
        case EMPTY:
            nextTileObjType = COLOBJ::CEMPTY;
            break;
    }

    return CollisionManager::collisionMatrix[static_cast<int>(obj)][static_cast<int>(nextTileObjType)] == 1;
}