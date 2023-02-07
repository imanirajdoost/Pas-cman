#include "GameObject.h"

void GameObject::draw(SDL_Surface* plancheSprites, SDL_Surface* win_surf) {

    if (_sprite_in == nullptr) {
        _sprite_in = &(_r_sprite);
    }

    SDL_Rect sprite_in2 = *_sprite_in;

    SDL_BlitScaled(plancheSprites, &sprite_in2, win_surf, &rect);
}