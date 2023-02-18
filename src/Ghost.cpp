#include <iostream>

#include "Ghost.h"
#include "GameVars.h"
#include "GameController.h"

SDL_Rect Blinky::blinky_r1 = { 4,124, 14,14 };
SDL_Rect Blinky::blinky_r2 = { 21,124, 14,14 };
SDL_Rect Blinky::blinky_l1 = { 38,124, 14,14 };
SDL_Rect Blinky::blinky_l2 = { 55,124, 14,14 };
SDL_Rect Blinky::blinky_d1 = { 106,124, 14,14 };
SDL_Rect Blinky::blinky_d2 = { 123,124, 14,14 };
SDL_Rect Blinky::blinky_u1 = { 72,124, 14,14 };
SDL_Rect Blinky::blinky_u2 = { 89,124, 14,14 };

SDL_Rect Pinky::pinky_r1 = { 4,142, 14,14 };
SDL_Rect Pinky::pinky_r2 = { 21,142, 14,14 };
SDL_Rect Pinky::pinky_l1 = { 38,142, 14,14 };
SDL_Rect Pinky::pinky_l2 = { 55,142, 14,14 };
SDL_Rect Pinky::pinky_d1 = { 106,142, 14,14 };
SDL_Rect Pinky::pinky_d2 = { 123,142, 14,14 };
SDL_Rect Pinky::pinky_u1 = { 72,142, 14,14 };
SDL_Rect Pinky::pinky_u2 = { 89,142, 14,14 };

SDL_Rect Inky::inky_r1 = { 4,160, 14,14 };
SDL_Rect Inky::inky_r2 = { 21,160, 14,14 };
SDL_Rect Inky::inky_l1 = { 38,160, 14,14 };
SDL_Rect Inky::inky_l2 = { 55,160, 14,14 };
SDL_Rect Inky::inky_d1 = { 106,160, 14,14 };
SDL_Rect Inky::inky_d2 = { 123,160, 14,14 };
SDL_Rect Inky::inky_u1 = { 72,160, 14,14 };
SDL_Rect Inky::inky_u2 = { 89,160, 14,14 };

SDL_Rect Clyde::clyde_r1 = { 4,178, 14,14 };
SDL_Rect Clyde::clyde_r2 = { 21,178, 14,14 };
SDL_Rect Clyde::clyde_l1 = { 38,178, 14,14 };
SDL_Rect Clyde::clyde_l2 = { 55,178, 14,14 };
SDL_Rect Clyde::clyde_d1 = { 106,178, 14,14 };
SDL_Rect Clyde::clyde_d2 = { 123,178, 14,14 };
SDL_Rect Clyde:: clyde_u1 = { 72,178, 14,14 };
SDL_Rect Clyde:: clyde_u2 = { 89,178, 14,14 };

Ghost::Ghost(int x, int y) {
    rect.x = x;
    rect.y = y;

    _next_pos.x = x;
    _next_pos.y = y;

    rect.w = TILESIZE;
    rect.h = TILESIZE;
}


Blinky::Blinky(int x, int y): Ghost(x, y) {
    // Set default animation and sprite and add animations
    addAnimation({"default", {Blinky::blinky_r1, Blinky::blinky_r2}});
    addAnimation({"move_up", {Blinky::blinky_u1, Blinky::blinky_u2}});
    addAnimation({"move_down", {Blinky::blinky_d1, Blinky::blinky_d2}});
    addAnimation({"move_left", {Blinky::blinky_l1, Blinky::blinky_l2}});
    addAnimation({"move_right", {Blinky::blinky_r1, Blinky::blinky_r2}});

    setAnimation("default");
//    _r_sprite = blinky_r;
//    _l_sprite = blinky_l;
//    _d_sprite = blinky_d;
//    _u_sprite = blinky_u;
}


void Blinky::setNextPos(const std::vector<std::vector<MTYPE>>& map, const MoveDirection& direction) {
    if (GameController::animationCounter%4 == 0) {
        _next_pos.x += speed;
    }

    setMoveDirection(direction);
}

Pinky::Pinky(int x, int y): Ghost(x, y) {
    // Set default animation and sprite and add animations
    addAnimation({"default", {Pinky::pinky_r1, Pinky::pinky_r2}});
    addAnimation({"move_up", {Pinky::pinky_u1, Pinky::pinky_u2}});
    addAnimation({"move_down", {Pinky::pinky_d1, Pinky::pinky_d2}});
    addAnimation({"move_left", {Pinky::pinky_l1, Pinky::pinky_l2}});
    addAnimation({"move_right", {Pinky::pinky_r1, Pinky::pinky_r2}});

    setAnimation("default");
//    _r_sprite = pinky_r;
//    _l_sprite = pinky_l;
//    _d_sprite = pinky_d;
//    _u_sprite = pinky_u;
}

void Pinky::setNextPos(const std::vector<std::vector<MTYPE>>& map, const MoveDirection& direction) {
    if (GameController::animationCounter%4 == 0) {
        _next_pos.x += speed;
    }

    setMoveDirection(direction);
}

Inky::Inky(int x, int y): Ghost(x, y) {
    // Set default animation and sprite and add animations
    addAnimation({"default", {Inky::inky_r1, Inky::inky_r2}});
    addAnimation({"move_up", {Inky::inky_u1, Inky::inky_u2}});
    addAnimation({"move_down", {Inky::inky_d1, Inky::inky_d2}});
    addAnimation({"move_left", {Inky::inky_l1, Inky::inky_l2}});
    addAnimation({"move_right", {Inky::inky_r1, Inky::inky_r2}});

    setAnimation("default");
//    _r_sprite = inky_r;
//    _l_sprite = inky_l;
//    _d_sprite = inky_d;
//    _u_sprite = inky_u;
}

void Inky::setNextPos(const std::vector<std::vector<MTYPE>>& map, const MoveDirection& direction) {
    if (GameController::animationCounter%4 == 0) {
        _next_pos.x += speed;
    }

    setMoveDirection(direction);
}

Clyde::Clyde(int x, int y): Ghost(x, y) {
    // Set default animation and sprite and add animations
    addAnimation({"default", {Clyde::clyde_r1, Clyde::clyde_r2}});
    addAnimation({"move_up", {Clyde::clyde_u1, Clyde::clyde_u2}});
    addAnimation({"move_down", {Clyde::clyde_d1, Clyde::clyde_d2}});
    addAnimation({"move_left", {Clyde::clyde_l1, Clyde::clyde_l2}});
    addAnimation({"move_right", {Clyde::clyde_r1, Clyde::clyde_r2}});

    setAnimation("default");
//    _r_sprite = clyde_r;
//    _l_sprite = clyde_l;
//    _d_sprite = clyde_d;
//    _u_sprite = clyde_u;
}

void Clyde::setNextPos(const std::vector<std::vector<MTYPE>>& map, const MoveDirection& direction) {
    if (GameController::animationCounter%4 == 0) {
        _next_pos.x += speed;
    }

    setMoveDirection(direction);
}

