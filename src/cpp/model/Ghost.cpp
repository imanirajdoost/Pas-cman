#include <iostream>
#include <unordered_set>
#include <random>
#include <ctime>
#include "header/model/Ghost.h"
#include "header/GameVars.h"
#include "header/controller/CollisionController.h"


Ghost::Ghost(SDL_Rect default_sp, SDL_Rect initPos) : MovableGameObject(default_sp, initPos) {
    speed = 1;
}

void Ghost::setNextPos(const vector<std::vector<MTYPE>> &map, const MoveDirection &direction) {
    // TODO: Implement this

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

void Ghost::move() {
    MovableGameObject::move();
    if (getMoveDirection() != MoveDirection::NONE)
        startAnimation();
}

void Ghost::reset_state() {
    MovableGameObject::reset_state();
    startAnimation();
}

SDL_Rect Ghost::getNextStepRect(MoveDirection dir) {

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

void Ghost::setMoveIntent(const MoveDirection &direction) {
    moveIntent = direction;
}

void Ghost::controlMove(CollisionController &collisionController) {

    unordered_set<int> possibleDirections;

    bool shouldMove = true;
    bool canChangeDir = false;
    stopAnimation();

    if (moveIntent == MoveDirection::NONE)
        shouldMove = false;

    // for each direction, (Except NONE), calculate the possiblity that the ghost can move in that direction
    // if the ghost can move in that direction, add it to the possibleDirections vector
    std::vector<int> allAvailableMoves;
    for (int i = 1; i < 5; i++) {
        allAvailableMoves.push_back(i);
    }
    for (auto &mv: allAvailableMoves) {
        setMoveIntent(static_cast<MoveDirection>(mv));

        Collider nextCol = collisionController.getRectAtDirection(rect, direction);
        Collider intentionCol = collisionController.getRectAtDirection(rect, moveIntent);
        SDL_Rect currentRect = collisionController.getRectAt(rect);
        SDL_Rect nextStep = getNextStepRect(direction);

        if (moveIntent == direction && nextCol.getType() != MTYPE::WALL) {
//            setNextPos(Map::map, direction);
            shouldMove = true;
            possibleDirections.emplace(static_cast<int>(direction));
        } else if (moveIntent == direction && nextCol.getType() == MTYPE::WALL) {
            if (collisionController.hasCollision(nextStep, nextCol.getRect())) {
                shouldMove = false;
//                resetNextPos();
            } else {
                shouldMove = true;
//                setNextPos(Map::map, direction);
                possibleDirections.emplace(static_cast<int>(direction));
            }
        } else if (moveIntent != direction && intentionCol.getType() == MTYPE::WALL) {
            if (nextCol.getType() == MTYPE::WALL && collisionController.hasCollision(nextStep, nextCol.getRect())) {
//                resetNextPos();
                shouldMove = false;
            } else {
//                setNextPos(Map::map, direction);
                shouldMove = true;
                if(static_cast<int>(direction) == 0) {
                    cout << "direction is 0" << endl;
                    continue;
                }
                possibleDirections.emplace(static_cast<int>(direction));
            }
        } else if (moveIntent != direction && intentionCol.getType() != MTYPE::WALL) {
            if ((direction == MoveDirection::LEFT && moveIntent == MoveDirection::RIGHT) ||
                (direction == MoveDirection::RIGHT && moveIntent == MoveDirection::LEFT) ||
                (direction == MoveDirection::UP && moveIntent == MoveDirection::DOWN) ||
                (direction == MoveDirection::DOWN && moveIntent == MoveDirection::UP)) {
                // Can change direction instantly
//                setNextPos(Map::map, moveIntent);
                shouldMove = true;
                possibleDirections.emplace(static_cast<int>(moveIntent));
            } else {
                // Check for center to change vertical or horizontal axis
                // Add a threshold so that the position changing is not pixel perfect
                if (abs((rect.x + (rect.w / 2)) - (currentRect.x + (currentRect.w / 2))) <=
                    Ghost::GHOST_MOVE_THRESHOLD &&
                    abs((rect.y + (rect.h / 2)) - (currentRect.y + (currentRect.h / 2))) <=
                    Ghost::GHOST_MOVE_THRESHOLD) {
                    // Reset position of the player if it has been changed based on the margin
                    setX(currentRect.x);
                    setY(currentRect.y);
//                    resetNextPos();
//                    setNextPos(Map::map, moveIntent);
                    shouldMove = true;
                    possibleDirections.emplace(static_cast<int>(moveIntent));
                } else {
                    if (nextCol.getType() == MTYPE::WALL &&
                        collisionController.hasCollision(nextStep, nextCol.getRect())) {
//                        resetNextPos();
                        shouldMove = false;
                    } else {
//                        setNextPos(Map::map, direction);
                        shouldMove = true;
                        possibleDirections.emplace(static_cast<int>(direction));
                    }
                }
            }
        } else {
            std::cout << "ERROR : Case not handled" << endl;
        }
    }

    // print the possible directions
    for (auto &mv: possibleDirections) {
        std::cout << "Possible direction : " << static_cast<int>(mv) << endl;
    }


    // Pick a random move among the possible directions
    if (possibleDirections.size() > 0) {
        shouldMove = true;

        if (possibleDirections.size() > 2)
            canChangeDir = true;

        // Only change the direction if the canChangeDir is true
        if (!canChangeDir)
            setMoveDirection(lastDirection);
        else {
            // Seed the random number generator with the current time
            std::mt19937 rng(std::time(0));

            // Generate a random index from 0 to the size of the set - 1
            std::uniform_int_distribution<int> distribution(0, possibleDirections.size() - 1);

            // Choose a random element from the unordered_set
            auto it = possibleDirections.begin();
            std::advance(it, distribution(rng));

//            int randomIndex = rand() % possibleDirections.size();
//        setMoveDirection(possibleDirections[randomIndex]);
            setNextPos(Map::map, static_cast<MoveDirection>(*it));
        }
    }
    else {
        shouldMove = false;
        resetNextPos();
    }


    if (shouldMove)
        move();
}

MoveDirection Ghost::getRandomMove() const {
    // return a random move among move direction enum (except NONE)
    return static_cast<MoveDirection>(rand() % 4 + 1);
}

MoveDirection Ghost::getRandomMoveExcept(vector<MoveDirection> &exceptDirections) {
    // Return a random move among move direction enum (except NONE) and except the ones in the vector
    std::vector<MoveDirection> allAvailableMoves;
    for (int i = 1; i < 5; i++) {
        allAvailableMoves.push_back(static_cast<MoveDirection>(i));
    }

    // Now remove the except directions from the available moves
    for (auto &exceptDirection: exceptDirections) {
        for (auto it = allAvailableMoves.begin(); it != allAvailableMoves.end(); ++it) {
            if (*it == exceptDirection) {
                allAvailableMoves.erase(it);
                break;
            }
        }
    }

    // Now return a random move from all available moves
    return allAvailableMoves[rand() % allAvailableMoves.size()];
}

Blinky::Blinky() : Ghost(default_sprites::blinky_sp_default, default_positions::blinky_default_pos) {

    // Initial pos
    setPos(32, 32);
    resetNextPos();

    // Set default animation and sprite and add animations
    addAnimation("default", {blinky_r1, blinky_r2}, GHOST_ANIMATION_SPEED);
    addAnimation("move_up", {blinky_u1, blinky_u2}, GHOST_ANIMATION_SPEED);
    addAnimation("move_down", {blinky_d1, blinky_d2}, GHOST_ANIMATION_SPEED);
    addAnimation("move_left", {blinky_l1, blinky_l2}, GHOST_ANIMATION_SPEED);
    addAnimation("move_right", {blinky_r1, blinky_r2}, GHOST_ANIMATION_SPEED);

    setAnimation("default");

    startAnimation();
}


//void Blinky::setNextPos(const std::vector<std::vector<MTYPE>>& map, const MoveDirection& direction) {
//    if (GameController::animationCounter%4 == 0) {
//        _next_pos.x += speed;
//    }
//
//    setMoveDirection(direction);
//}

Pinky::Pinky() : Ghost(default_sprites::pinky_sp_default, default_positions::pinky_default_pos) {

    resetNextPos();

    // Set default animation and sprite and add animations
    addAnimation("default", {pinky_r1, pinky_r2}, GHOST_ANIMATION_SPEED);
    addAnimation("move_up", {pinky_u1, pinky_u2}, GHOST_ANIMATION_SPEED);
    addAnimation("move_down", {pinky_d1, pinky_d2}, GHOST_ANIMATION_SPEED);
    addAnimation("move_left", {pinky_l1, pinky_l2}, GHOST_ANIMATION_SPEED);
    addAnimation("move_right", {pinky_r1, pinky_r2}, GHOST_ANIMATION_SPEED);

    setAnimation("default");

    startAnimation();
}

Inky::Inky() : Ghost(default_sprites::inky_sp_default, default_positions::inky_default_pos) {

    resetNextPos();

    // Set default animation and sprite and add animations
    addAnimation("default", {inky_r1, inky_r2}, GHOST_ANIMATION_SPEED);
    addAnimation("move_up", {inky_u1, inky_u2}, GHOST_ANIMATION_SPEED);
    addAnimation("move_down", {inky_d1, inky_d2}, GHOST_ANIMATION_SPEED);
    addAnimation("move_left", {inky_l1, inky_l2}, GHOST_ANIMATION_SPEED);
    addAnimation("move_right", {inky_r1, inky_r2}, GHOST_ANIMATION_SPEED);

    setAnimation("default");

    startAnimation();

    setMoveDirection(MoveDirection::RIGHT);
    setMoveIntent(MoveDirection::RIGHT);
}

Clyde::Clyde() : Ghost(default_sprites::clyde_sp_default, default_positions::clyde_default_pos) {
    resetNextPos();

    // Set default animation and sprite and add animations
    addAnimation("default", {clyde_r1, clyde_r2}, GHOST_ANIMATION_SPEED);
    addAnimation("move_up", {clyde_u1, clyde_u2}, GHOST_ANIMATION_SPEED);
    addAnimation("move_down", {clyde_d1, clyde_d2}, GHOST_ANIMATION_SPEED);
    addAnimation("move_left", {clyde_l1, clyde_l2}, GHOST_ANIMATION_SPEED);
    addAnimation("move_right", {clyde_r1, clyde_r2}, GHOST_ANIMATION_SPEED);

    setAnimation("default");

    startAnimation();
}
