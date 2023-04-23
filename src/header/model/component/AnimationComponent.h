/**
 * @file AnimationModelComponent.h
 * @brief This file contains the model for the animation component, which is responsible for handling the animation of sprites and objects in the game.
 */

#ifndef PAS_CMAN_ANIMATIONCOMPONENT_H
#define PAS_CMAN_ANIMATIONCOMPONENT_H

#include <string>
#include <SDL2/SDL_rect.h>
#include <vector>
#include <memory>
#include "GameComponent.h"
#include "header/model/AnimationModel.h"

using namespace std;

/**
 * @class AnimationComponent
 * @brief The model for the animation component, which is responsible for handling the animation of sprites and objects in the game.
 */
class AnimationComponent : public GameComponent, public enable_shared_from_this<AnimationComponent> {
private:
    /**
    * @brief The vector of AnimationModel objects that represents the different animations available for this component.
    */
    vector<AnimationModel> animation_list;

    /**
     * @brief The current animation frame.
     */
    u_short animation_frame;

protected:
    /**
     * @brief The current sprite being displayed.
     */
    shared_ptr<SDL_Rect> current_sp;

    /**
     * @brief The default sprite to display when not animating.
     */
    SDL_Rect default_sp;

    /**
    * @brief Whether or not this component is currently animating.
    */
    bool isAnimated = false;

    /**
     * @brief The current animation being played.
     */
    shared_ptr<AnimationModel> current_anim = nullptr;

public:

    /**
     * @brief Constructs an empty AnimationComponent object.
     */
    AnimationComponent();

    /**
 * @brief Stops the current animation.
 */
    void stopAnimation();

    /**
     * @brief Starts the current animation.
     */
    void startAnimation();

    /**
 * @brief Sets the current animation based on the given animation name.
 * @param animName The name of the animation to set.
 * @return True if the animation was successfully set, false otherwise.
 */
    bool setAnimation(const string &animName);

    /**
     * @brief Constructs an AnimationComponent object with a default sprite.
     * @param defaultSp The default sprite to use.
     */
    explicit AnimationComponent(SDL_Rect defaultSp);

    /**
     * @brief Constructs an AnimationComponent object with a specified name, list of sprites, and animation status.
     * @param newName The name of the component.
     * @param sps The list of sprites to use.
     * @param _isAnimated Whether or not the component should animate.
     */
    AnimationComponent(const string &newName, const vector<SDL_Rect> &sps, bool _isAnimated);

    /**
     * @brief Adds a new animation to the component.
     * @param animName The name of the new animation.
     * @param sps The list of sprites for the animation.
     * @param shouldLoop Whether or not the animation should loop.
     */
    void addAnimation(const string &animName, const vector<SDL_Rect> &sps, int speed = 1, bool shouldLoop = true);

    /**
     * @brief Sets the default sprite to the first sprite in the current animation.
     */
    void setDefaultSprite();

    /**
     * @brief Returns the next sprite in the current animation.
     * @return The next sprite in the animation.
     */
    shared_ptr<SDL_Rect> getNextSprite();

    /**
     * @brief Returns the current sprite being displayed.
     * @return The current sprite.
     */
    shared_ptr<SDL_Rect> getCurrentSprite();

    /**
     * @brief Returns the current animation.
     * @return The current animation.
     */
    shared_ptr<AnimationComponent> getAnimatorComponent();
};


#endif //PAS_CMAN_ANIMATIONCOMPONENT_H
