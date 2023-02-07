#include "MovableGameObject.h"

int MovableGameObject::getX() const{
    return rect.x;
}

int MovableGameObject::getY() const{
    return rect.y;
}

SDL_Rect MovableGameObject::getRect() const {
    return rect;
}

void MovableGameObject::setX(int x) {
    rect.x = x;
}

void MovableGameObject::setY(int y) {
    rect.y = y;
}


MoveDirection MovableGameObject::getMoveDirection() const {
    return direction;
}

void MovableGameObject::setMoveDirection(const MoveDirection& newDirection) {
    direction = newDirection;
}


//void MovableGameObject::draw(SDL_Surface* plancheSprites, SDL_Surface* win_surf) {
//
//    _sprite_in = nullptr;
//
//    switch (direction)
//    {
//    case MoveDirection::RIGHT:
//        _sprite_in = &(_r_sprite);
//        break;
//    case MoveDirection::LEFT:
//        _sprite_in = &(_l_sprite);
//        break;
//    case MoveDirection::DOWN:
//        _sprite_in = &(_d_sprite);
//        break;
//    case MoveDirection::UP:
//        _sprite_in = &(_u_sprite);
//        break;
//    default:
//        _sprite_in = &(_r_sprite);
//        break;
//    }
//
//    SDL_Rect sprite_in2 = *_sprite_in;
//
//    // if (_animationCounter%4 == 0) {
//    //     sprite_in2.x += 17;
//    // }
//
//    SDL_BlitScaled(plancheSprites, &sprite_in2, win_surf, &rect);
//}

SDL_Rect MovableGameObject::getNextPos() const{
    return _next_pos;
}

void MovableGameObject::resetNextPos() {
    _next_pos = rect;
}

void MovableGameObject::move() {
    rect.x = _next_pos.x;
    rect.y = _next_pos.y;
}