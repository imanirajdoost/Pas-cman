#include "GameObject.h"

void GameObject::draw(SDL_Surface* plancheSprites, SDL_Surface* win_surf) {

//    _sprite_in = nullptr;
    _sprite_in = &(_r_sprite);

//    switch (direction)
//    {
//        case MoveDirection::RIGHT:
//            _sprite_in = &(_r_sprite);
//            break;
//        case MoveDirection::LEFT:
//            _sprite_in = &(_l_sprite);
//            break;
//        case MoveDirection::DOWN:
//            _sprite_in = &(_d_sprite);
//            break;
//        case MoveDirection::UP:
//            _sprite_in = &(_u_sprite);
//            break;
//        default:
//            _sprite_in = &(_r_sprite);
//            break;
//    }

    SDL_Rect sprite_in2 = *_sprite_in;

    // if (_animationCounter%4 == 0) {
    //     sprite_in2.x += 17;
    // }

    SDL_BlitScaled(plancheSprites, &sprite_in2, win_surf, &rect);
}