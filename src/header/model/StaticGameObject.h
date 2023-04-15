#ifndef STATICGAMEOBJECT_H
#define STATICGAMEOBJECT_H

#include "GameObject.h"

/**
 * @brief Base class for static game objects like dots and fruits
 */
class StaticGameObject : public GameObject {
public:
    /**
     * @brief Constructor for StaticGameObject.
     * @param defaultSp The default sprite for the GameObject.
     * @param initPos The initial position of the GameObject.
     */
    StaticGameObject(SDL_Rect defaultSp, SDL_Rect initPos);

    /**
     * @brief Constructor for StaticGameObject.
     * @param initPos The initial position of the GameObject.
     */
    explicit StaticGameObject(SDL_Rect initPos);
};

#endif