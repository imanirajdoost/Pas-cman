/**
 * @file GameObject.h
 * @brief Base class for all game objects in the game, with transform and animation components.
 */

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "header/model/component/TransformComponent.h"
#include "header/model/component/AnimationComponent.h"

class GameObject : public TransformComponent, public AnimationComponent {
public:
    /**
     * @brief Default constructor for GameObject.
     */
    GameObject();

    /**
     * @brief Constructor for GameObject with default sprite.
     * @param defaultSp The default sprite for the GameObject.
     */
    explicit GameObject(SDL_Rect defaultSp);

    /**
     * @brief Constructor for GameObject with animation sprites.
     * @param newName The name of the GameObject.
     * @param sps The sprites for the GameObject's animation.
     * @param _isAnimated Whether the GameObject is animated.
     */
    GameObject(const string &newName, const vector<SDL_Rect> &sps, bool _isAnimated);
};

#endif
