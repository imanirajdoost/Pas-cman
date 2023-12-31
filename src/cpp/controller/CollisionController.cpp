

#include "header/controller/CollisionController.h"
#include "header/GameVars.h"

bool CollisionController::hasCollision(const SDL_Rect &rect1, const SDL_Rect &rect2) {
    // Checks intersection and puts the intersection rect result in result
    SDL_bool result = SDL_HasIntersection(&rect1, &rect2);

    if (result == SDL_TRUE)
        return true;
    return false;
}

bool CollisionController::isWallDetectedAtDirection(const SDL_Rect &sourceRect, const MoveDirection &direction) {
    int mapX = getMapX(sourceRect);
    int mapY = getMapY(sourceRect);

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

    if (nextMapTile == MTYPE::WALL)
        return true;
    return false;
}

bool CollisionController::isCollision(const std::vector<std::vector<MTYPE>> &map, const MovableGameObject &targetObj,
                                      const MTYPE &obj, const SDL_Rect &collisionOffset) {

    SDL_Rect targetPosWithOffset = targetObj.getNextPos();
    MoveDirection direction = targetObj.getMoveDirection();

    targetPosWithOffset.x += collisionOffset.x * TILESIZE;
    targetPosWithOffset.y += collisionOffset.y * TILESIZE;

    MTYPE offsetColObj;
    SDL_Rect targetPos = targetPosWithOffset;

    switch (direction) {
        case MoveDirection::UP:
        case MoveDirection::DOWN:
            targetPos.x += TILESIZE - 1;
            offsetColObj = getNextCOLOBJ(map, targetPos);
            break;
        case MoveDirection::RIGHT:
        case MoveDirection::LEFT:
            targetPos.y += TILESIZE - 1;
            offsetColObj = getNextCOLOBJ(map, targetPos);

            break;
        default:
            // Possible none movement
            return true;
    }

    MTYPE nextMapTile = getNextCOLOBJ(map, targetPosWithOffset);

    return CollisionController::collisionMatrix[static_cast<int>(obj)][static_cast<int>(nextMapTile)] ||
           CollisionController::collisionMatrix[static_cast<int>(obj)][static_cast<int>(offsetColObj)];
}

MTYPE CollisionController::getNextCOLOBJ(const std::vector<std::vector<MTYPE>> &map, const SDL_Rect &targetPos) {

    int mapX = targetPos.x / TILESIZE;
    int mapY = targetPos.y / TILESIZE;

    MTYPE nextMapTile = map[mapY][mapX];

    return nextMapTile;
}

int CollisionController::getMapX(SDL_Rect targetPos) {
    return (targetPos.x + (targetPos.w / 2)) / TILESIZE;
}

int CollisionController::getMapY(SDL_Rect targetPos) {
    return (targetPos.y + (targetPos.h / 2)) / TILESIZE;
}

MTYPE CollisionController::getObjectTypeAt(const SDL_Rect &targetPos) {

    int mapX = getMapX(targetPos);
    int mapY = getMapY(targetPos);

    MTYPE nextMapTile = Map::map[mapY][mapX];

    return nextMapTile;
}

SDL_Rect CollisionController::getRectAt(const SDL_Rect &targetPos) {
    int mapX = getMapX(targetPos);
    int mapY = getMapY(targetPos);

    SDL_Rect newRect;
    newRect.x = mapX * TILESIZE;
    newRect.y = mapY * TILESIZE;
    newRect.w = newRect.h = TILESIZE;
    return newRect;
}

Collider CollisionController::getRectAtDirection(const SDL_Rect &targetPos, const MoveDirection &direction) {

    Collider col{};

    SDL_Rect tempRect = targetPos;

    int mapX = getMapX(targetPos);
    int mapY = getMapY(targetPos);

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

vector<Collider> CollisionController::getRectsAtDirection(const SDL_Rect &targetPos, const MoveDirection &direction) {
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

int CollisionController::getCollisionWithTeleportDoor(const SDL_Rect &targetPos) {
    if(getObjectTypeAt(targetPos) == MTYPE::TP) {
        // TODO: Improve this code (remove the magic number)
        // Check if it's the left teleport door or right (0: left, 1: right)
        if(targetPos.x < 350)
            return 0;
        else
            return 1;
    }
    return -1;
}
