#include "MovableGameObject.h"

#include <iostream>

int MovableGameObject::getX() const{
    return rect.x;
}

int MovableGameObject::getY() const{
    return rect.y;
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
    setDirectionSprite(newDirection);
}

void MovableGameObject::setDirectionSprite(const MoveDirection& newDirection) {
    switch (newDirection) {
        case MoveDirection::DOWN:
            _sprite_in = &(_d_sprite);
            break;
        case MoveDirection::UP:
            _sprite_in = &(_u_sprite);
            break;
        case MoveDirection::LEFT:
            _sprite_in = &(_l_sprite);
            break;
        case MoveDirection::RIGHT:
        default:
            _sprite_in = &(_r_sprite);
            break;
    }
}


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