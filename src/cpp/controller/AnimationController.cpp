#include "header/controller/AnimationController.h"

int AnimationController::animationCounter = 0;

AnimationController::AnimationController(shared_ptr<vector<shared_ptr<AnimationComponent>>> &anims) : animations(
        anims) {

}

void AnimationController::tick() {
    animationCounter++;
    // if animationCounter is greater than integer max, reset it to 0
    if (animationCounter >= 2147483647) {
        animationCounter = 0;
    }
}

void AnimationController::stopAllAnimations() {
    if (animations == nullptr)
        return;
    for (auto &anim: *animations) {
        anim->stopAnimation();
    }
}

void AnimationController::startAllAnimations() {
    if (animations == nullptr)
        return;
    for (auto &anim: *animations) {
        anim->startAnimation();
    }
}

void AnimationController::resetAllAnimations() {
    if (animations == nullptr)
        return;
    for (auto &anim: *animations) {
        anim->setAnimation("default");
    }
}

void AnimationController::stopAnimation(const shared_ptr<AnimationComponent>& anim) {
    if (anim != nullptr)
        anim->stopAnimation();
}

void AnimationController::startAnimation(const shared_ptr<AnimationComponent>& anim) {
    if (anim != nullptr)
        anim->startAnimation();
}
