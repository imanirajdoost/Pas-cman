#include "header/model/MovableGameObject.h"

MoveDirection MovableGameObject::getMoveDirection() const {
    return direction;
}

void MovableGameObject::setMoveDirection(const MoveDirection &newDirection) {
    direction = newDirection;
    setDirectionSprite(newDirection);
}

void MovableGameObject::resetMoveDirection() {
    setMoveDirection(lastDirection);
}

void MovableGameObject::setDirectionSprite(const MoveDirection &newDirection) {

    if (!isMoveEnabled)
        return;

    switch (newDirection) {
        case MoveDirection::DOWN:
            setAnimation("move_down");
            break;
        case MoveDirection::UP:
            setAnimation("move_up");
            break;
        case MoveDirection::LEFT:
            setAnimation("move_left");
            break;
        case MoveDirection::RIGHT:
            setAnimation("move_right");
        default:
//            setAnimation("default");
            break;
    }
}


SDL_Rect MovableGameObject::getNextPos() const {
    return _next_pos;
}

int MovableGameObject::getSpeed() const {
    return speed;
}

void MovableGameObject::resetNextPos() {
    _next_pos = rect;
}

void MovableGameObject::move() {
    if (isMoveEnabled) {
        rect.x = _next_pos.x;
        rect.y = _next_pos.y;
    }
}

MovableGameObject::MovableGameObject(SDL_Rect defaultSp, SDL_Rect initPos) : GameObject(defaultSp, initPos) {
    isMoveEnabled = true;
}

MovableGameObject::MovableGameObject(const string &animName, const vector<SDL_Rect> &sprites, bool _isAnimated,
                                     SDL_Rect initPos)
        : GameObject(animName, sprites, _isAnimated, initPos){
    isMoveEnabled = true;
}

MovableGameObject::MovableGameObject(SDL_Rect initPos) : GameObject(initPos) {
    isMoveEnabled = true;
}

void MovableGameObject::reset_state() {
    GameObject::reset_state();
    resetNextPos();
    resetMoveDirection();
    setMoveDirection(MoveDirection::NONE);
    isMoveEnabled = true;
    setAnimation("default");
    getNextSprite();
}
