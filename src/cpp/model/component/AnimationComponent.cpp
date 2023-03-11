//
// Created by iman on 18/02/23.
//

#include <iostream>
#include <SDL2/SDL_rect.h>
#include <vector>
#include "../../../header/model/component/AnimationComponent.h"


std::string AnimationComponent::getName() const {
    return name;
}

void AnimationComponent::setName(const std::string& newName) {
    name = newName;
}

std::vector<SDL_Rect> AnimationComponent::getSpritesList() const {
    return sprites_list;
}

inline void AnimationComponent::addSprite(const SDL_Rect& sp) {
    sprites_list.push_back(sp);
}

void AnimationComponent::addSprites(const std::vector<SDL_Rect>& sps) {
    for (const auto& sp: sps) {
        addSprite(sp);
    }
}

AnimationComponent::AnimationComponent(const string &newName, const vector<SDL_Rect> &sps) {
    setName(newName);
    addSprites(sps);
    animation_frame = 0;
    startAnimation();
}

/**
 * sets the game object's animation to the given name
 * @param animName name of the target anim
 * @return true if animation is found and played
 */
bool AnimationComponent::setAnimation(const std::string &animName) {
    // if the current animation is already playing then ignore it
    if(current_anim != nullptr && current_anim->getName() == animName)
        return true;

    // Go through the list and check for the animation names
    for (auto &anim: animation_list) {
        if (anim.getName() == animName) {
            // Reset the animation frame to zero
            animation_frame = 0;
            // Set the current playing animation to the reference anim
            current_anim = make_shared<AnimationComponent>(anim);
            return true;
        }
    }
    // No animation found with this name :(
    std::cout << "AnimationComponent not found: " << animName << std::endl;
    return false;
}

/**
 * Stops the animation on this object
 */
void AnimationComponent::stopAnimation() {
    isAnimated = false;
}

/**
 * Starts the animation on this object
 */
void AnimationComponent::startAnimation() {
    isAnimated = true;
}

void AnimationComponent::addAnimation(const AnimationComponent& anim) {
    for (auto& a:animation_list) {
        if(a.getName() == anim.getName())
            return;
    }
    animation_list.push_back(anim);
}

AnimationComponent::AnimationComponent() {

}
