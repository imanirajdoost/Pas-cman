#include <iostream>
#include "header/model/Ghost.h"
#include "header/GameVars.h"


Ghost::Ghost(SDL_Rect default_sp) : MovableGameObject(default_sp) {
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
}

Blinky::Blinky() : Ghost(default_sprites::blinky_sp_default) {

    // Initial pos
    setPos(32, 32);

    // Set default animation and sprite and add animations
    addAnimation("default", {blinky_r1, blinky_r2});
    addAnimation("move_up", {blinky_u1, blinky_u2});
    addAnimation("move_down", {blinky_d1, blinky_d2});
    addAnimation("move_left", {blinky_l1, blinky_l2});
    addAnimation("move_right", {blinky_r1, blinky_r2});

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

Pinky::Pinky() : Ghost(default_sprites::pinky_sp_default) {

    // Initial pos
    setPos(64, 32);

    // Set default animation and sprite and add animations
    addAnimation("default", {pinky_r1, pinky_r2});
    addAnimation("move_up", {pinky_u1, pinky_u2});
    addAnimation("move_down", {pinky_d1, pinky_d2});
    addAnimation("move_left", {pinky_l1, pinky_l2});
    addAnimation("move_right", {pinky_r1, pinky_r2});

    setAnimation("default");

    startAnimation();
}

Inky::Inky() : Ghost(default_sprites::inky_sp_default) {

    // Initial pos
    setPos(96, 32);

    // Set default animation and sprite and add animations
    addAnimation("default", {inky_r1, inky_r2});
    addAnimation("move_up", {inky_u1, inky_u2});
    addAnimation("move_down", {inky_d1, inky_d2});
    addAnimation("move_left", {inky_l1, inky_l2});
    addAnimation("move_right", {inky_r1, inky_r2});

    setAnimation("default");

    startAnimation();
}

Clyde::Clyde() : Ghost(default_sprites::clyde_sp_default) {

    // Initial pos
    setPos(128, 32);

    // Set default animation and sprite and add animations
    addAnimation("default", {clyde_r1, clyde_r2});
    addAnimation("move_up", {clyde_u1, clyde_u2});
    addAnimation("move_down", {clyde_d1, clyde_d2});
    addAnimation("move_left", {clyde_l1, clyde_l2});
    addAnimation("move_right", {clyde_r1, clyde_r2});

    setAnimation("default");

    startAnimation();
}
