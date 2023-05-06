#include "header/model/MovableGameObject.h"

MoveDirection MovableGameObject::getMoveDirection() const {
    return direction;
}

SDL_Rect MovableGameObject::getNextPos() const {
    return _next_pos;
}

void MovableGameObject::setMoveDirection(const MoveDirection &newDirection) {
    direction = newDirection;
    setDirectionSprite(newDirection);
}

MoveDirection MovableGameObject::getMoveIntent() const {
    return moveIntent;
}
    
void MovableGameObject::setMoveIntent(const MoveDirection &direction) {
    moveIntent = direction;
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

int MovableGameObject::getSpeed() const {
    return speed;
}

void MovableGameObject::resetNextPos() {
    _next_pos = rect;
}

SDL_Rect MovableGameObject::getNextStepRect(MoveDirection dir) {

    SDL_Rect nextStepRect = getRect();

    switch (dir) {
        case MoveDirection::LEFT:
            nextStepRect.x -= speed;
            break;
        case MoveDirection::RIGHT:
            nextStepRect.x += speed;
            break;
        case MoveDirection::UP:
            nextStepRect.y -= speed;
            break;
        case MoveDirection::DOWN:
            nextStepRect.y += speed;
            break;
        case MoveDirection::NONE:
            nextStepRect.y = getRect().y;
            nextStepRect.x = getRect().x;
            break;
    }
    return nextStepRect;
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
