#include "../../include/model/Player.h"
#include <vector>
#include <iostream>
#include "../../include/GameVars.h"
#include "../../include/Map.h"
#include "../../include/model/component/MoveComponent.h"
#include "../../include/controller/CollisionController.h"
#include "controller/GameController.h"

Player::Player(short initHealth) : HealthComponent(initHealth) {

    // Set the initial pos
    setPos(10 * TILESIZE, 13 * TILESIZE);

    setMoveIntent(MoveDirection::NONE);

    // Set default animation and sprite and add animations
    addAnimation({"default", {player_fill, player_r1, player_r2}});
    addAnimation({"move_up", {player_fill, player_u1, player_u2}});
    addAnimation({"move_down", {player_fill, player_d1, player_d2}});
    addAnimation({"move_left", {player_fill, player_l1, player_l2}});
    addAnimation({"move_right", {player_fill, player_r1, player_r2}});
    addAnimation({"die", {player_die1, player_die2, player_die3, player_die4,
                          player_die5, player_die6, player_die7, player_die8,
                          player_die9}});

    setAnimation("default");
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

//void Player::eat(EatableComponent &dotToEat) const {
//    dotToEat.getEaten(dotToEat);
//}

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

    Collider nextCol = CollisionController::getRectAtDirection(rect, direction);
    Collider intentionCol = CollisionController::getRectAtDirection(rect, moveIntent);
    SDL_Rect currentRect = CollisionController::getRectAt(rect);
    SDL_Rect nextStep = getNextStepRect(direction);

    if (moveIntent == direction && nextCol.getType() != MTYPE::WALL) {
        setNextPos(Map::map, direction);
        shouldMove = true;
    } else if (moveIntent == direction && nextCol.getType() == MTYPE::WALL) {
        if (CollisionController::hasCollision(nextStep, nextCol.getRect())) {
            shouldMove = false;
            resetNextPos();
        } else {
            shouldMove = true;
            setNextPos(Map::map, direction);
        }
    } else if (moveIntent != direction && intentionCol.getType() == MTYPE::WALL) {
        if (nextCol.getType() == MTYPE::WALL && CollisionController::hasCollision(nextStep, nextCol.getRect())) {
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
            // Add a threshold so that the position changing is not pixel perfect
            if (abs((rect.x + (rect.w / 2)) - (currentRect.x + (currentRect.w / 2))) <= Player::PLAYER_MOVE_THRESHOLD &&
                abs((rect.y + (rect.h / 2)) - (currentRect.y + (currentRect.h / 2))) <= Player::PLAYER_MOVE_THRESHOLD) {
                // Reset position of the player if it has been changed based on the margin
                setX(currentRect.x);
                setY(currentRect.y);
                resetNextPos();
                setNextPos(Map::map, moveIntent);
                shouldMove = true;
            } else {
                if (nextCol.getType() == MTYPE::WALL &&
                    CollisionController::hasCollision(nextStep, nextCol.getRect())) {
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

void Player::move() {
    MovableGameObject::move();

    // Check for collision with coins
    for (auto i = GameController::dots.begin(); i < GameController::dots.end(); ++i) {
        if (CollisionController::hasCollision(getRect(), i->get()->getRect())) {
            eat(*i->get());
            break;
        }
    }

    // Check for collision with bonus objs
    if (CollisionController::hasCollision(getRect(), GameController::fruit.getRect()))
        eat(GameController::fruit);
}
