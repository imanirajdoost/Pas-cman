/**
@file CollisionController.h
@brief Header file for CollisionController class, which handles collision between two objects
*/
#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H


#include <SDL2/SDL_rect.h>
#include "header/model/MovableGameObject.h"
#include "header/model/Collider.h"

/**
@class CollisionController
@brief Handles collision between two objects
*/
class CollisionController {
private:

    /**
     * @brief Get the Map X object
     * @param targetPos target position
     * @return int map x
     */
    int getMapX(SDL_Rect targetPos);

    /**
     * @brief Get the Map Y object
     * @param targetPos target position
     * @return int map y
     */
    int getMapY(SDL_Rect targetPos);

public:
    // Methods
    /**
@brief Checks if there is a wall detected at given direction from a given source rectangle
@param sourceRect The source rectangle to check
@param direction The direction to check for wall
@return True if there is a wall detected, false otherwise
*/
    bool isWallDetectedAtDirection(const SDL_Rect &sourceRect, const MoveDirection &direction);

    /**
@brief Gets the collider rectangle at given direction from a given target position
@param targetPos The target position to get collider from
@param direction The direction to get the collider
@return The collider rectangle at the given direction
*/
    Collider getRectAtDirection(const SDL_Rect &targetPos, const MoveDirection &direction);

    /**
@brief Gets a vector of collider rectangles at given direction from a given target position
@param targetPos The target position to get colliders from
@param direction The direction to get the colliders
@return A vector of collider rectangles at the given direction
*/
    vector<Collider> getRectsAtDirection(const SDL_Rect &targetPos, const MoveDirection &direction);

    /**
@brief Gets the object type at a given target position
@param targetPos The target position to get the object type from
@return The object type at the given target position
*/
    MTYPE getObjectTypeAt(const SDL_Rect &targetPos);

    /**
@brief Gets the rectangle at a given target position
@param targetPos The target position to get the rectangle from
@return The rectangle at the given target position
*/
    SDL_Rect getRectAt(const SDL_Rect &targetPos);

    /**
@brief Checks if there is a collision between two rectangles
@param rect1 The first rectangle to check for collision
@param rect2 The second rectangle to check for collision
@return True if there is a collision detected, false otherwise
*/
    bool hasCollision(const SDL_Rect &rect1, const SDL_Rect &rect2);

    /**
@brief Checks if there is a collision between a movable game object and a non-movable game object at given offset
@param map The game map
@param targetObj The movable game object to check collision for
@param obj The non-movable game object to check collision with
@param collisionOffset The offset to use for collision check
@return True if there is a collision detected, false otherwise
*/
    bool isCollision(const std::vector<std::vector<MTYPE>> &map, const MovableGameObject &targetObj, const MTYPE &obj,
                     const SDL_Rect &collisionOffset);

    /**
@brief Gets the next collision object type at a given target position
@param map The game map
@param targetPos The target position to get the next collision object type from
@return The next collision object type at the given target position
*/
    MTYPE getNextCOLOBJ(const std::vector<std::vector<MTYPE>> &map, const SDL_Rect &targetPos);

    /**
@brief Gets the collision with teleporter
@param targetPos The target position to get the next collision object type from
@return -1 for nothing, 0 for left collision and 1 for right collision
*/
    int getCollisionWithTeleportDoor(const SDL_Rect &targetPos);

    // Variables
    const std::vector<std::vector<int>> collisionMatrix = {
            {0, 1, 0, 1, 1, 0, 1},
            {1, 0, 0, 1, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0},
            {1, 1, 0, 0, 0, 0, 0},
            {1, 1, 0, 0, 0, 0, 0},
            {1, 0, 0, 0, 0, 0, 0},
            {1, 0, 0, 0, 0, 0, 0},
    };
};

#endif