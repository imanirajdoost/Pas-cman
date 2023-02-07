#include "GameObject.h"
#include "GameVars.h"
#include "GameController.h"

void GameObject::draw(SDL_Surface* plancheSprites, SDL_Surface* win_surf) {

    if (_sprite_in == nullptr) {
        _sprite_in = &(_r_sprite);
    }

    SDL_Rect sprite_in2 = *_sprite_in;

    if ((GameController::animationCounter/ANIMATION_FRAME_RATE)%2 == 1) {
        sprite_in2.x += 14;
    }

    SDL_Rect drawRect = rect;

    if (rect.w < TILESIZE) {
        drawRect.x += rect.w/2;
    }

    if (rect.h < TILESIZE) {
        drawRect.y += rect.h/2;
    }

    SDL_BlitScaled(plancheSprites, &sprite_in2, win_surf, &drawRect);
}

SDL_Rect GameObject::getRect() const {
    return rect;
}