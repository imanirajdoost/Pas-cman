//
// Created by iman on 10/03/23.
//

#ifndef PAS_CMAN_ANIMATIONCONTROLLER_H
#define PAS_CMAN_ANIMATIONCONTROLLER_H


class AnimationController {
public:
    AnimationController();

    virtual void tick();

    static int animationCounter;
};


#endif //PAS_CMAN_ANIMATIONCONTROLLER_H
