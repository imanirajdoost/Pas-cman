#ifndef GHOST_H
#define GHOST_H

#include <SDL.h>
#include "model/MovableGameObject.h"
#include "Map.h"

class Ghost : public MovableGameObject {
protected:
    bool isVulnerable = false;

public:
    Ghost();

};

class Blinky : public Ghost {
public:
    Blinky();

private:
    const SDL_Rect blinky_r1 = {4, 124, 14, 14};
    const SDL_Rect blinky_r2 = {21, 124, 14, 14};
    const SDL_Rect blinky_l1 = {38, 124, 14, 14};
    const SDL_Rect blinky_l2 = {55, 124, 14, 14};
    const SDL_Rect blinky_d1 = {106, 124, 14, 14};
    const SDL_Rect blinky_d2 = {123, 124, 14, 14};
    const SDL_Rect blinky_u1 = {72, 124, 14, 14};
    const SDL_Rect blinky_u2 = {89, 124, 14, 14};
};

class Pinky : public Ghost {
public:
    Pinky();

private:
    const SDL_Rect pinky_r1 = {4, 142, 14, 14};
    const SDL_Rect pinky_r2 = {21, 142, 14, 14};
    const SDL_Rect pinky_l1 = {38, 142, 14, 14};
    const SDL_Rect pinky_l2 = {55, 142, 14, 14};
    const SDL_Rect pinky_d1 = {106, 142, 14, 14};
    const SDL_Rect pinky_d2 = {123, 142, 14, 14};
    const SDL_Rect pinky_u1 = {72, 142, 14, 14};
    const SDL_Rect pinky_u2 = {89, 142, 14, 14};
};

class Inky : public Ghost {
public:
    Inky();

private:
    const SDL_Rect inky_r1 = {4, 160, 14, 14};
    const SDL_Rect inky_r2 = {21, 160, 14, 14};
    const SDL_Rect inky_l1 = {38, 160, 14, 14};
    const SDL_Rect inky_l2 = {55, 160, 14, 14};
    const SDL_Rect inky_d1 = {106, 160, 14, 14};
    const SDL_Rect inky_d2 = {123, 160, 14, 14};
    const SDL_Rect inky_u1 = {72, 160, 14, 14};
    const SDL_Rect inky_u2 = {89, 160, 14, 14};
};

class Clyde : public Ghost {
public:
    Clyde();

private:
    const SDL_Rect clyde_r1 = {4, 178, 14, 14};
    const SDL_Rect clyde_r2 = {21, 178, 14, 14};
    const SDL_Rect clyde_l1 = {38, 178, 14, 14};
    const SDL_Rect clyde_l2 = {55, 178, 14, 14};
    const SDL_Rect clyde_d1 = {106, 178, 14, 14};
    const SDL_Rect clyde_d2 = {123, 178, 14, 14};
    const SDL_Rect clyde_u1 = {72, 178, 14, 14};
    const SDL_Rect clyde_u2 = {89, 178, 14, 14};
};

#endif