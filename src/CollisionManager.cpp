#include "CollisionManager.h"
#include "Ghost.h"
#include "GameVars.h"

#include <SDL.h>
#include <iostream>

int CollisionManager::collisionMatrix[7][7] = {
            {0,1,0,1,1,0,1},
            {1,0,0,1,0,0,0},
            {0,0,0,0,0,0,0},
            {1,1,0,0,0,0,0},
            {1,1,0,0,0,0,0},
            {1,0,0,0,0,0,0},
            {1,0,0,0,0,0,0}, 
        };

bool CollisionManager::isCollision(const MTYPE map[27][21], const SDL_Rect& targetPos, const MTYPE& obj, const SDL_Rect& collisionOffset) {

    SDL_Rect targetPosWithOffset = targetPos;
    int nb_tilesX = targetPos.x / 32;
    int nb_tilesY = targetPos.y / 32;
    if (targetPos.x%32 != 0) {
        targetPosWithOffset.x = (nb_tilesX + collisionOffset.x)*TILESIZE;
    }
    if (targetPos.y%32 != 0) {
        targetPosWithOffset.y = (nb_tilesY + collisionOffset.y)*TILESIZE;
    }

    //targetPosWithOffset.x += collisionOffset.x * collisionOffset.w;
    //targetPosWithOffset.y += collisionOffset.y * collisionOffset.h;

    MTYPE nextMapTile = getNextCOLOBJ(map, targetPosWithOffset);

<<<<<<< HEAD
    //if (obj == MTYPE::PACMAN)
        //std::cout << static_cast<int>(nextMapTile) << std::endl;
=======
    if (obj == MTYPE::PACMAN)
        //std::cout << "next tile: " << static_cast<int>(nextMapTile) << std::endl;
        //std::cout << "x: " << targetPosWithOffset.x/32 << std::endl;
        //std::cout << "y: " << targetPosWithOffset.y/32 << std::endl;
        std::cout << static_cast<int>(map[targetPosWithOffset.y/32][targetPosWithOffset.x/32]) << std::endl;
>>>>>>> f76c7534341274e07904208a80051352f9e420ff

    return CollisionManager::collisionMatrix[static_cast<int>(obj)][static_cast<int>(nextMapTile)] == 1;
}

MTYPE CollisionManager::getNextCOLOBJ(const MTYPE map[27][21], const SDL_Rect& targetPos) {
    
    int mapX = targetPos.x/TILESIZE;
    int mapY = targetPos.y/TILESIZE;

    MTYPE nextMapTile = map[mapY][mapX];

    return nextMapTile;
}

