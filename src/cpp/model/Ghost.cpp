#include <iostream>
#include "header/model/Ghost.h"
#include "header/GameVars.h"


Ghost::Ghost(SDL_Rect default_sp, SDL_Rect initPos) : MovableGameObject(default_sp, initPos) {
    speed = 1;

    addAnimation("afraid", {afraid_sp, afraid_sp2}, GHOST_ANIMATION_SPEED);
    addAnimation("afraid_white", {afraid_white_sp, afraid_white_sp2, afraid_sp, afraid_sp2}, GHOST_ANIMATION_SPEED);

    setMode(Mode::CHASE);
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
}

void Ghost::reset_state() {
    MovableGameObject::reset_state();
    startAnimation();
}

void Ghost::setMode(Mode mode) {
    ghostMode = mode;
    switch (mode) {
        case Mode::CHASE:
            setAnimation("default");
            break;
        case Mode::SCATTER:
            setAnimation("default");
            break;
        case Mode::FRIGHTENED:
            //TODO
            setAnimation("afraid");
            break;
    }
}

void Ghost::setDirectionSprite(const MoveDirection &newDirection) {
    if(ghostMode == Mode::FRIGHTENED)
        return;
    else
        MovableGameObject::setDirectionSprite(newDirection);
}

Mode Ghost::getMode() {
    return ghostMode;
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
