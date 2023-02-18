#include <iostream>
#include "GameObject.h"
#include "GameVars.h"
#include "GameController.h"

GameObject::GameObject() {
    animation_frame = 0;
}

void GameObject::draw(SDL_Surface *plancheSprites, SDL_Surface *win_surf) {

    if (current_sp == nullptr) {
        current_sp = make_shared<SDL_Rect>(default_sp);
    }

    SDL_Rect sprite_in2 = *current_sp;

    if (isAnimated && current_anim != nullptr && (GameController::animationCounter / ANIMATION_FRAME_RATE) % 2 == 1) {
        const auto &anim_rects = current_anim->getSpritesList();
        if (animation_frame >= anim_rects.size())
            animation_frame = 0;

        sprite_in2 = anim_rects[animation_frame];
        animation_frame++;
//        sprite_in2.x += 14;
    }

    SDL_Rect drawRect = rect;

    if (rect.w < TILESIZE) {
        drawRect.x += rect.w / 2;
    }

    if (rect.h < TILESIZE) {
        drawRect.y += rect.h / 2;
    }

    SDL_BlitScaled(plancheSprites, &sprite_in2, win_surf, &drawRect);
}

SDL_Rect GameObject::getRect() const {
    return rect;
}

////////////////
// ANIMATION //
///////////////

/**
 * sets the game object's animation to the given name
 * @param animName name of the target anim
 * @return true if animation is found and played
 */
bool GameObject::setAnimation(const std::string &animName) {
    // if the current animation is already playing then ignore it
    if(current_anim != nullptr && current_anim->getName() == animName)
        return true;

    // Go through the list and check for the animation names
    for (auto &anim: animation_list) {
        if (anim.getName() == animName) {
            // Reset the animation frame to zero
            animation_frame = 0;
            // Set the current playing animation to the reference anim
            current_anim = make_shared<Animation>(anim);
            return true;
        }
    }
    // No animation found with this name :(
    std::cout << "Animation not found: " << animName << std::endl;
    return false;
}

/**
 * Stops the animation on this object
 */
void GameObject::stopAnimation() {
    isAnimated = false;
}

/**
 * Starts the animation on this object
 */
void GameObject::startAnimation() {
    isAnimated = true;
}

void GameObject::addAnimation(const Animation& anim) {
    animation_list.push_back(anim);
}
////////////////
// END OF ANIMATION
///////////////
