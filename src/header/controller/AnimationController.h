/**
 * @file   AnimationController.h
 * @brief  The header file for the AnimationController class, which controls the animation logic of the game.
 */

#ifndef PAS_CMAN_ANIMATIONCONTROLLER_H
#define PAS_CMAN_ANIMATIONCONTROLLER_H

/**
 * @brief The AnimationController class, which controls the animation logic of the game.
 */
class AnimationController {
public:
    /**
     * @brief Constructor for the AnimationController class.
     */
    AnimationController();

    /**
     * @brief Method that is called each frame to update the animation state.
     */
    void tick();

    /**
     * @brief Static counter that keeps track of the number of animations created.
     */
    static int animationCounter;
};

#endif //PAS_CMAN_ANIMATIONCONTROLLER_H
