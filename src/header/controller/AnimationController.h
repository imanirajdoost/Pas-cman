/**
 * @file   AnimationController.h
 * @brief  The header file for the AnimationController class, which controls the animation logic of the game.
 */

#ifndef PAS_CMAN_ANIMATIONCONTROLLER_H
#define PAS_CMAN_ANIMATIONCONTROLLER_H

#include <vector>
#include "header/model/component/AnimationComponent.h"

using namespace std;

/**
 * @brief The AnimationController class, which controls the animation logic of the game.
 */
class AnimationController {
public:
    /**
     * @brief Constructor for the AnimationController class.
     */
    explicit AnimationController(
            shared_ptr<vector<shared_ptr<AnimationComponent>>> &anims); // Initialize the class member with the shared_ptr

    /**
     * @brief Method that is called each frame to update the animation state.
     */
    void tick();

    /**
     * @brief Method that is called when the game is reset.
     */
    void stopAllAnimations();

    /**
     * @brief Method that starts all animations.
     */
    void startAllAnimations();

    /**
     * @brief Method that is called when the game is reset.
     */
    void resetAllAnimations();

    /**
    * @brief Method that starts a specific animation.
    */
    void startAnimation(const shared_ptr<AnimationComponent> &anim);

    /**
     * @brief Method that stops a specific animation.
     */
    void stopAnimation(const shared_ptr<AnimationComponent> &anim);

    /**
     * @brief Static counter for animations.
     */
    static int animationCounter;

    shared_ptr<vector<shared_ptr<AnimationComponent>>> animations; // Declare the class member as a shared_ptr

};

#endif //PAS_CMAN_ANIMATIONCONTROLLER_H
