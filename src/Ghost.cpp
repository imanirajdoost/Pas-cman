#ifndef GHOST_H
#define GHOST_H

#include "../include/Ghost.h"

Ghost::Ghost(int x, int y) {
    _x = x;
    _y = y;
}

int Ghost::getX() {
    return _x;
}

int Ghost::getY() {
    return _y;
}

#endif