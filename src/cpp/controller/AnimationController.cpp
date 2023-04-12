#include "header/controller/AnimationController.h"

int AnimationController::animationCounter = 0;

AnimationController::AnimationController() {

}

void AnimationController::tick() {
    animationCounter++;
    // if animationCounter is greater than integer max, reset it to 0
    if (animationCounter >= 2147483647) {
        animationCounter = 0;
    }
}
