//
// Created by iman on 10/03/23.
//


#include "../../header/controller/AnimationController.h"

int AnimationController::animationCounter = 0;

AnimationController::AnimationController() {

}

void AnimationController::tick() {
    animationCounter++;
}
