//
// Created by iman on 10/03/23.
//

#include <SDL2/SDL_video.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include "../../header/controller/SDLController.h"

SDLController::SDLController() {
    pWindow = SDL_CreateWindow("PacMan", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 900, 900, SDL_WINDOW_SHOWN);
    win_surf = SDL_GetWindowSurface(pWindow);

    renderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_SOFTWARE);

    plancheSprites = SDL_LoadBMP("./pacman_sprites.bmp");
}

void SDLController::tick() {
    SDL_UpdateWindowSurface(pWindow);
    // LIMITE A 60 FPS
    SDL_Delay(16); // utiliser SDL_GetTicks64() pour plus de precisions
}
