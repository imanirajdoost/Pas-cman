//
// Created by iman on 10/03/23.
//


#include "../../header/controller/AnimationController.h"

AnimationController::AnimationController(): animationCounter(0) {

}

void AnimationController::tick() {
    animationCounter++;
}
