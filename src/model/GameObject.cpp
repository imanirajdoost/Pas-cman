#include <iostream>
#include "model/GameObject.h"
#include "GameVars.h"
#include "controller/GameController.h"

void GameObject::draw(SDL_Surface *plancheSprites, SDL_Surface *win_surf) {

    if (current_sp == nullptr) {
        current_sp = make_shared<SDL_Rect>(default_sp);
    }

//    SDL_Rect sprite_in2 = *current_sp;

    if (isAnimated && current_anim != nullptr && GameController::animationCounter % ANIMATION_FRAME_RATE == 0) {
        const auto &anim_rects = current_anim->getSpritesList();
        if (animation_frame >= anim_rects.size())
            animation_frame = 0;

//        cout << "Anim frame: " << animation_frame << " rects size: " << anim_rects.size() << " anim counter:" << GameController::animationCounter << endl;

        current_sp = make_shared<SDL_Rect>(anim_rects[animation_frame]);
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

    SDL_BlitScaled(plancheSprites, current_sp.get(), win_surf, &drawRect);
}

////////////////
// ANIMATION //
///////////////

GameObject::GameObject(SDL_Rect defaultSprite) : default_sp{defaultSprite} {
    animation_frame = 0;
}
////////////////
// END OF ANIMATION
///////////////
