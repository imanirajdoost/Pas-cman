#include <iostream>

#include "MovableGameObject.h"
#include "CollisionManager.h"

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

void MovableGameObject::setNextPos(const MoveDirection &direction) {

    lastDirection = getMoveDirection();
    setMoveDirection(direction);

    switch (direction) {
        case MoveDirection::LEFT:
            _next_pos.x -= speed;
            break;
        case MoveDirection::RIGHT:
            _next_pos.x += speed;
            break;
        case MoveDirection::UP:
            _next_pos.y -= speed;
            break;
        case MoveDirection::DOWN:
            _next_pos.y += speed;
            break;
        case MoveDirection::NONE:
            _next_pos.y = getRect().y;
            _next_pos.x = getRect().x;
            break;
    }
}

void MovableGameObject::controlMove() {
    bool shouldMove = true;

    if (moveIntent == MoveDirection::NONE)
        shouldMove = false;

    Collider nextCol = CollisionManager::getRectAtDirection(rect, direction);
    Collider intentionCol = CollisionManager::getRectAtDirection(rect, moveIntent);
    SDL_Rect currentRect = CollisionManager::getRectAt(rect);
    SDL_Rect nextStep = getNextStepRect(direction);

    if (moveIntent == direction && nextCol.getType() != MTYPE::WALL) {
        setNextPos(direction);
        shouldMove = true;
    } else if (moveIntent == direction && nextCol.getType() == MTYPE::WALL) {
        if (CollisionManager::hasCollision(nextStep, nextCol.getRect())) {
            shouldMove = false;
            resetNextPos();
        } else {
            shouldMove = true;
            setNextPos(direction);
        }
    } else if (moveIntent != direction && intentionCol.getType() == MTYPE::WALL) {
        if (nextCol.getType() == MTYPE::WALL && CollisionManager::hasCollision(nextStep, nextCol.getRect())) {
            resetNextPos();
            shouldMove = false;
        } else {
            setNextPos(direction);
            shouldMove = true;
        }
    } else if (moveIntent != direction && intentionCol.getType() != MTYPE::WALL) {
        if ((direction == MoveDirection::LEFT && moveIntent == MoveDirection::RIGHT) ||
            (direction == MoveDirection::RIGHT && moveIntent == MoveDirection::LEFT) ||
            (direction == MoveDirection::UP && moveIntent == MoveDirection::DOWN) ||
            (direction == MoveDirection::DOWN && moveIntent == MoveDirection::UP)) {
            // Can change direction instantly
            setNextPos(moveIntent);
            shouldMove = true;
        } else {
            // Check for center to change vertical or horizontal axis
            // Add a threshold so that the position changing is not pixel perfect
            if (abs((rect.x + (rect.w / 2)) - (currentRect.x + (currentRect.w / 2))) <= PLAYER_MOVE_THRESHOLD &&
                abs((rect.y + (rect.h / 2)) - (currentRect.y + (currentRect.h / 2))) <= PLAYER_MOVE_THRESHOLD) {
                // Reset position of the player if it has been changed based on the margin
                setX(currentRect.x);
                setY(currentRect.y);
                resetNextPos();
                setNextPos(moveIntent);
                shouldMove = true;
            } else {
                if (nextCol.getType() == MTYPE::WALL && CollisionManager::hasCollision(nextStep, nextCol.getRect())) {
                    resetNextPos();
                    shouldMove = false;
                } else {
                    setNextPos(direction);
                    shouldMove = true;
                }
            }
        }
    } else {
        std::cout << "ERROR : Case not handled" << endl;
    }

    if (shouldMove)
        move();
}

MoveDirection MovableGameObject::getMoveIntent() const {
    return moveIntent;
}

void MovableGameObject::setMoveIntent(const MoveDirection &direction) {
    moveIntent = direction;
}