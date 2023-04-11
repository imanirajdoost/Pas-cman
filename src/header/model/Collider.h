#ifndef COLLIDER_H
#define COLLIDER_H

#include <SDL2/SDL_rect.h>
#include "Map.h"

/**
 * @brief The Collider class is used for defining the collision properties of an object
 */
class Collider {
private:
    MTYPE type; /**< The type of the collision */
    SDL_Rect rect; /**< The bounding box of the collider */

public:
    /**
     * @brief Sets the type of the collision
     * @param typeToSet The type of the collision
     */
    void setType(const MTYPE& typeToSet);

    /**
     * @brief Gets the type of the collision
     * @return The type of the collision
     */
    MTYPE getType() const;

    /**
     * @brief Sets the bounding box of the collider
     * @param rectToSet The bounding box of the collider
     */
    void setRect(const SDL_Rect& rectToSet);

    /**
     * @brief Gets the bounding box of the collider
     * @return The bounding box of the collider
     */
    SDL_Rect getRect();
};

#endif
