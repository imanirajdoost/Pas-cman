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

bool CollisionManager::hasCollision(const SDL_Rect& rect1, const SDL_Rect& rect2) {
    // Checks intersection and puts the intersection rect result in result
//    SDL_bool SDL_IntersectRect(const SDL_Rect * A, const SDL_Rect * B, SDL_Rect * result);
    SDL_bool result = SDL_HasIntersection(&rect1, &rect2);

    if(result == SDL_TRUE)
        return true;
    return false;
}

bool CollisionManager::isWallDetectedAtDirection(const SDL_Rect& sourceRect, const MoveDirection& direction) {
    int mapX = (sourceRect.x + (sourceRect.w / 2)) / TILESIZE;
    int mapY = (sourceRect.y + (sourceRect.h / 2)) / TILESIZE;

    switch (direction) {
        case MoveDirection::RIGHT:
            mapX += 1;
            break;
        case MoveDirection::LEFT:
            mapX -= 1;
            break;
        case MoveDirection::DOWN:
            mapY += 1;
            break;
        case MoveDirection::UP:
            mapY -= 1;
            break;
        case MoveDirection::NONE:
            break;
    }

    MTYPE nextMapTile = Map::map[mapX][mapY];

    if(nextMapTile == MTYPE::WALL)
        return true;
    return false;


    cout << mapX << ", " << mapY << endl;
}

bool CollisionManager::isCollision(const std::vector<std::vector<MTYPE>>& map, const MovableGameObject& targetObj, const MTYPE& obj, const SDL_Rect& collisionOffset) {

    SDL_Rect targetPosWithOffset = targetObj.getNextPos();
    MoveDirection direction = targetObj.getMoveDirection();

    targetPosWithOffset.x += collisionOffset.x * TILESIZE;
    targetPosWithOffset.y += collisionOffset.y * TILESIZE;

    MTYPE offsetColObj;
    SDL_Rect targetPos = targetPosWithOffset;

    switch (direction) {
        case MoveDirection::UP:
        case MoveDirection::DOWN:
            targetPos.x += TILESIZE-1;
            offsetColObj = getNextCOLOBJ(map, targetPos);
            break;
        case MoveDirection::RIGHT:
        case MoveDirection::LEFT:
            targetPos.y += TILESIZE-1;
            offsetColObj = getNextCOLOBJ(map, targetPos);

            break;
        default:
            // Possible none movement
            return true;
    }

    MTYPE nextMapTile = getNextCOLOBJ(map, targetPosWithOffset);

    return CollisionManager::collisionMatrix[static_cast<int>(obj)][static_cast<int>(nextMapTile)] ||
            CollisionManager::collisionMatrix[static_cast<int>(obj)][static_cast<int>(offsetColObj)];
}

MTYPE CollisionManager::getNextCOLOBJ(const std::vector<std::vector<MTYPE>>& map, const SDL_Rect& targetPos) {
    
    int mapX = targetPos.x/TILESIZE;
    int mapY = targetPos.y/TILESIZE;

    MTYPE nextMapTile = map[mapY][mapX];

    return nextMapTile;
}

MTYPE CollisionManager::getObjectTypeAt(const SDL_Rect& targetPos) {

    int mapX = (targetPos.x + (targetPos.w / 2)) / TILESIZE;
    int mapY = (targetPos.y + (targetPos.h / 2)) / TILESIZE;
//    int mapX = targetPos.x / TILESIZE;
//    int mapY = targetPos.y / TILESIZE;

    MTYPE nextMapTile = Map::map[mapY][mapX];

    return nextMapTile;
}

SDL_Rect CollisionManager::getRectAt(const SDL_Rect& targetPos) {
    int mapX = (targetPos.x + (targetPos.w / 2)) / TILESIZE;
    int mapY = (targetPos.y + (targetPos.h / 2)) / TILESIZE;
//    int mapX = targetPos.x / TILESIZE;
//    int mapY = targetPos.y / TILESIZE;

    SDL_Rect newRect;
    newRect.x = mapX * TILESIZE;
    newRect.y = mapY * TILESIZE;
    newRect.w = newRect.h = TILESIZE;
    return newRect;
}

Collider CollisionManager::getRectAtDirection(const SDL_Rect& targetPos, const MoveDirection& direction) {

    Collider col{};

    SDL_Rect tempRect = targetPos;

    int mapX = (targetPos.x + (targetPos.w / 2)) / TILESIZE;
    int mapY = (targetPos.y + (targetPos.h / 2)) / TILESIZE;
//    int mapX = targetPos.x / TILESIZE;
//    int mapY = targetPos.y / TILESIZE;

    switch (direction) {
        case MoveDirection::RIGHT:
            mapX += 1;
            tempRect.x += TILESIZE;
            break;
        case MoveDirection::LEFT:
            mapX -= 1;
            tempRect.x -= TILESIZE;
            break;
        case MoveDirection::DOWN:
            mapY += 1;
            tempRect.y += TILESIZE;
            break;
        case MoveDirection::UP:
            mapY -= 1;
            tempRect.y -= TILESIZE;
            break;
        case MoveDirection::NONE:
            break;
    }

    SDL_Rect newRect;
    newRect.x = mapX * TILESIZE;
    newRect.y = mapY * TILESIZE;
    newRect.w = newRect.h = TILESIZE;

    col.setRect(newRect);

    MTYPE objType = getObjectTypeAt(tempRect);

    col.setType(objType);

    return col;
}

vector<Collider> CollisionManager::getRectsAtDirection(const SDL_Rect& targetPos, const MoveDirection& direction) {
    vector<Collider> cols;
    cols.push_back(getRectAtDirection(targetPos, direction));

    SDL_Rect tempPos = targetPos;

    switch (direction) {
        case MoveDirection::UP:
        case MoveDirection::DOWN:
            tempPos.x += TILESIZE;
            cols.push_back(getRectAtDirection(tempPos, direction));
            break;
        case MoveDirection::RIGHT:
        case MoveDirection::LEFT:
            tempPos.y += TILESIZE;
            cols.push_back(getRectAtDirection(tempPos, direction));
            break;
        case MoveDirection::NONE:
            break;
    }

    return cols;
}
