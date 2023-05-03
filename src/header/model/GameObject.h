/**
 * @file GameObject.h
 * @brief Base class for all game objects in the game, with transform and animation components.
 */

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "header/model/component/TransformComponent.h"
#include "header/model/component/AnimationComponent.h"
#include "header/controller/IResettable.h"

class GameObject : public TransformComponent, public AnimationComponent, public IResettable {
public:
    /**
     * @brief Default constructor for GameObject.
     * @param initPos The initial position of the GameObject.
     */
    GameObject(SDL_Rect initPos);

    /**
     * @brief Constructor for GameObject with default sprite.
     * @param defaultSp The default sprite for the GameObject.
     * @param initPos The initial position of the GameObject.
     */
    explicit GameObject(SDL_Rect defaultSp, SDL_Rect initPos);

    /**
     * @brief Constructor for GameObject with animation sprites.
     * @param newName The name of the GameObject.
     * @param sps The sprites for the GameObject's animation.
     * @param _isAnimated Whether the GameObject is animated.
     * @param initPos The initial position of the GameObject.
     */
    GameObject(const string &newName, const vector<SDL_Rect> &sps, bool _isAnimated, SDL_Rect initPos);

    /**
     * @brief resets the state of the object
     */
    void reset_state() override;

protected:
    SDL_Rect _init_pos; ///< The initial position of the object.
};

#endif
