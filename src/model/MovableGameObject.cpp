#include "model/MovableGameObject.h"

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

void MovableGameObject::resetMoveDirection() {
    setMoveDirection(lastDirection);
}


void MovableGameObject::setDirectionSprite(const MoveDirection& newDirection) {
    switch (newDirection) {
        case MoveDirection::DOWN:
            setAnimation("move_down");
//            current_sp = &(_d_sprite);
            break;
        case MoveDirection::UP:
            setAnimation("move_up");
//            current_sp = &(_u_sprite);
            break;
        case MoveDirection::LEFT:
            setAnimation("move_left");
//            current_sp = &(_l_sprite);
            break;
        case MoveDirection::RIGHT:
            setAnimation("move_right");
        default:
//            setAnimation("default");
//            current_sp = make_shared<SDL_Rect>(default_sp);
//            current_sp = &(_r_sprite);
            break;
    }
}


SDL_Rect MovableGameObject::getNextPos() const{
    return _next_pos;
}

int MovableGameObject::getSpeed() const {
    return speed;
}

void MovableGameObject::resetNextPos() {
    _next_pos = rect;
}

void MovableGameObject::move() {
    rect.x = _next_pos.x;
    rect.y = _next_pos.y;
}

MovableGameObject::MovableGameObject(SDL_Rect defaultSprite) : GameObject(defaultSprite) {
    startAnimation();
}
