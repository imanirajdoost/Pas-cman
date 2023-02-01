#include <iostream>

#include "Ghost.h"

SDL_Rect blinky_r = { 3,123, 16,16 }; 
SDL_Rect blinky_l = { 37,123, 16,16 }; 
SDL_Rect blinky_d = { 105,123, 16,16 }; 
SDL_Rect blinky_u = { 71,123, 16,16 };

SDL_Rect pinky_r = { 3,142, 16,16 }; 
SDL_Rect pinky_l = { 37,142, 16,16 }; 
SDL_Rect pinky_d = { 105,142, 16,16 }; 
SDL_Rect pinky_u = { 71,142, 16,16 };

SDL_Rect inky_r = { 3,161, 16,16 }; 
SDL_Rect inky_l = { 37,161, 16,16 }; 
SDL_Rect inky_d = { 105,161, 16,16 }; 
SDL_Rect inky_u = { 71,161, 16,16 };

SDL_Rect clyde_r = { 3,180, 16,16 }; 
SDL_Rect clyde_l = { 37,180, 16,16 }; 
SDL_Rect clyde_d = { 105,180, 16,16 }; 
SDL_Rect clyde_u = { 71,180, 16,16 };

Ghost::Ghost(int x, int y) {
    rect.x = x;
    rect.y = y;
    rect.w = 32;
    rect.h = 32;
}


Blinky::Blinky(int x, int y): Ghost(x, y) {
    _r_sprite = blinky_r;
    _l_sprite = blinky_l;
    _d_sprite = blinky_d;
    _u_sprite = blinky_u;
}


void Blinky::setNextPos(Map map) {
    if (_animationCounter == 0) {
        rect.x++;
    }
    _animationCounter = (_animationCounter+1)%4;
}

Pinky::Pinky(int x, int y): Ghost(x, y) {
    _r_sprite = pinky_r;
    _l_sprite = pinky_l;
    _d_sprite = pinky_d;
    _u_sprite = pinky_u;
}

void Pinky::setNextPos(Map map) {
    if (_animationCounter == 0) {
        rect.x++;
    }
    _animationCounter = (_animationCounter+1)%4;
}

Inky::Inky(int x, int y): Ghost(x, y) {
    _r_sprite = inky_r;
    _l_sprite = inky_l;
    _d_sprite = inky_d;
    _u_sprite = inky_u;
}

void Inky::setNextPos(Map map) {
    if (_animationCounter == 0) {
        rect.x++;
    }
    _animationCounter = (_animationCounter+1)%4;
}

Clyde::Clyde(int x, int y): Ghost(x, y) {
    _r_sprite = clyde_r;
    _l_sprite = clyde_l;
    _d_sprite = clyde_d;
    _u_sprite = clyde_u;
}

void Clyde::setNextPos(Map map) {
    if (_animationCounter == 0) {
        rect.x++;
    }
    _animationCounter = (_animationCounter+1)%4;
}

