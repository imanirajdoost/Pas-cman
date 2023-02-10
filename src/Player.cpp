#include "Player.h"
#include "DotBig.h"
#include <typeinfo>
#include <iostream>
#include "GameVars.h"
#include "GameController.h"
#include "CollisionManager.h"

// get pacman's sprite from the sprite sheet
SDL_Rect player_r = {20, 89, 16, 16};
SDL_Rect player_l = {46, 89, 16, 16};
SDL_Rect player_d = {109, 89, 16, 16};
SDL_Rect player_u = {75, 89, 16, 16};

Player::Player(int x, int y, int initHealth) : _health{initHealth} {
    // _health = initHealth;
    // @todo : Update health UI

    rect.x = x;
    rect.y = y;
    rect.w = 32;
    rect.h = 32;

    _r_sprite = player_r;
    _l_sprite = player_l;
    _d_sprite = player_d;
    _u_sprite = player_u;
}

void Player::setNextPos(const std::vector<std::vector<MTYPE>> &map, const MoveDirection &direction) {

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

SDL_Rect Player::getNextStepRect(MoveDirection dir) {

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

void Player::eat(const Dot &dotToEat) const {
    dotToEat.getEaten(dotToEat);
}

void Player::die() {
    // @todo implement dying
    _health--;

    if (_health <= 0) {
        gameOver();
    }
}

void Player::gameOver() {
    // @todo show game over UI or reset the game
}

MoveDirection Player::getMoveIntent() const {
    return moveIntent;
}

void Player::setMoveIntent(const MoveDirection &direction) {
    moveIntent = direction;
}

void Player::setRawNextPos(const SDL_Rect nextPos) {
    _next_pos = nextPos;
}

void Player::controlMove() {

    bool shouldMove = true;

    if (moveIntent == MoveDirection::NONE)
        shouldMove = false;

    Collider nextCol = CollisionManager::getRectAtDirection(rect, direction);
    Collider intentionCol = CollisionManager::getRectAtDirection(rect, moveIntent);
    SDL_Rect currentRect = CollisionManager::getRectAt(rect);
    SDL_Rect nextStep = getNextStepRect(direction);

    if (moveIntent == direction && nextCol.getType() != MTYPE::WALL) {
        setNextPos(Map::map, direction);
        shouldMove = true;
    } else if (moveIntent == direction && nextCol.getType() == MTYPE::WALL) {
        if (CollisionManager::hasCollision(nextStep, nextCol.getRect())) {
            shouldMove = false;
            resetNextPos();
        } else {
            shouldMove = true;
            setNextPos(Map::map, direction);
        }
    } else if (moveIntent != direction && intentionCol.getType() == MTYPE::WALL) {
        if (nextCol.getType() == MTYPE::WALL && CollisionManager::hasCollision(nextStep, nextCol.getRect())) {
            resetNextPos();
            shouldMove = false;
        } else {
            setNextPos(Map::map, direction);
            shouldMove = true;
        }
    } else if (moveIntent != direction && intentionCol.getType() != MTYPE::WALL) {
        if ((direction == MoveDirection::LEFT && moveIntent == MoveDirection::RIGHT) ||
            (direction == MoveDirection::RIGHT && moveIntent == MoveDirection::LEFT) ||
            (direction == MoveDirection::UP && moveIntent == MoveDirection::DOWN) ||
            (direction == MoveDirection::DOWN && moveIntent == MoveDirection::UP)) {
            // Can change direction instantly
            setNextPos(Map::map, moveIntent);
            shouldMove = true;
        } else {
            // Check for center to change vertical or horizontal axis
            if (rect.x + (rect.w / 2) == currentRect.x + (currentRect.w / 2) &&
                rect.y + (rect.y / 2) == currentRect.y + (currentRect.y / 2)) {
                setNextPos(Map::map, moveIntent);
                shouldMove = true;
            } else {
                if (nextCol.getType() == MTYPE::WALL && CollisionManager::hasCollision(nextStep, nextCol.getRect())) {
                    resetNextPos();
                    shouldMove = false;
                } else {
                    setNextPos(Map::map, direction);
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
