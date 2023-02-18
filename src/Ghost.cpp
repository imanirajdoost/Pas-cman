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

//@TODO
SDL_Rect Inky::inky_r1 = { 3,161, 14,14 };
SDL_Rect Inky::inky_r2 = { 3,161, 14,14 };
SDL_Rect inky_l1 = { 37,161, 14,14 };
SDL_Rect inky_l2 = { 37,161, 14,14 };
SDL_Rect inky_d1 = { 105,161, 14,14 };
SDL_Rect inky_d2 = { 105,161, 14,14 };
SDL_Rect inky_u1 = { 71,161, 14,14 };
SDL_Rect inky_u2 = { 71,161, 14,14 };

SDL_Rect clyde_r = { 3,180, 16,16 };
SDL_Rect clyde_l = { 37,180, 16,16 };
SDL_Rect clyde_d = { 105,180, 16,16 };
SDL_Rect clyde_u = { 71,180, 16,16 };

Ghost::Ghost(int x, int y) {
    rect.x = x;
    rect.y = y;

    _next_pos.x = x;
    _next_pos.y = y;

    rect.w = TILESIZE;
    rect.h = TILESIZE;
}


Blinky::Blinky(int x, int y): Ghost(x, y) {
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

