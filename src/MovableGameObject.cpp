#include "MovableGameObject.h"

int MovableGameObject::getX() {
    return rect.x;
}

int MovableGameObject::getY() {
    return rect.y;
}

void MovableGameObject::setX(int x) {
    rect.x = x;
}

void MovableGameObject::setY(int y) {
    rect.y = y;
}

void MovableGameObject::draw(SDL_Surface* plancheSprites, SDL_Surface *win_surf) {

    _sprite_in = &(_r_sprite);
    SDL_Rect sprite_in2 = *sprite_in;
    
    if (_animationCounter%4 == 0) {
        ghost_in2.x += 17;
    }

    SDL_BlitScaled(plancheSprites, &sprite2, win_surf, &rect);
}