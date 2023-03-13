//
// Created by iman on 10/03/23.
//

#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_system.h>
#include <list>
#include "../../header/view/SDLViewController.h"
#include "../../header/GameVars.h"
#include "../../header/model/GameObject.h"
#include "../../header/Map.h"

SDLViewController::SDLViewController() {
    pWindow = SDL_CreateWindow("PacMan", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 900, 900, SDL_WINDOW_SHOWN);
    win_surf = SDL_GetWindowSurface(pWindow);

    renderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_SOFTWARE);

    plancheSprites = SDL_LoadBMP("./pacman_sprites.bmp");
}

void SDLViewController::tick() {
    draw();
    SDL_UpdateWindowSurface(pWindow);
    // LIMITE A 60 FPS
    SDL_Delay(16); // utiliser SDL_GetTicks64() pour plus de precisions
}

void SDLViewController::draw(std::list<GameObject> sprites) {
    SDL_SetColorKey(plancheSprites, false, 0);
    SDL_BlitScaled(plancheSprites, &src_bg, win_surf, &bg);
    // @TODO: This is a hack to avoid writing on top of the previous rect in UI, improve this
    SDL_BlitScaled(plancheSprites, &blackBg, win_surf, &UIRect);


    // couleur transparente
    SDL_SetColorKey(plancheSprites, true, 0);


    // copie du sprite zoomé

    for (auto sp : sprites) {
        sp.getNextSprite();
        sp.getDrawRect();
    }

    blinky.draw(plancheSprites, win_surf);
    pinky.draw(plancheSprites, win_surf);
    inky.draw(plancheSprites, win_surf);
    clyde.draw(plancheSprites, win_surf);

    player.draw(plancheSprites, win_surf);

    // Draw UI
    ViewManager::drawUI(plancheSprites, win_surf);

    for (auto &dotSmall: GameController::dots) {
        dotSmall->draw(plancheSprites, win_surf);
    }

    GameController::fruit.draw(plancheSprites, win_surf);

    if (DEBUG_MODE) {

        // draw the level grid
        draw_grid(100, 100, 20);

        // Draw the collider boxes on the screen
        draw_collider(player);
        draw_collider(blinky);
        draw_collider(pinky);
        draw_collider(inky);
        draw_collider(clyde);

//        for (auto & dotSmall : dots) {
//            draw_collider(*dotSmall);
//        }
    }
}

void SDLViewController::draw_sprite(SDL_Rect* spriteToDraw, SDL_Rect* drawRect) {

    SDL_BlitScaled(plancheSprites, spriteToDraw, win_surf, drawRect);
}

void SDLViewController::draw_collider(const GameObject &obj, int r = 255, int g = 0, int b = 9) {
    // set renderer color
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    //SDL_RenderClear( renderer );
    SDL_Rect debugRect = obj.getRect();
    // Render rect
    SDL_RenderDrawRect(renderer, &debugRect);
    // Render the rect to the screen
    SDL_RenderPresent(renderer);
}

void SDLViewController::draw_grid(int r = 255, int g = 0, int b = 0) {
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    auto map = Map::map;

    for (int i = 0; i < map.size(); i++) {
        SDL_RenderDrawLine(renderer, 0, i * TILESIZE, map[0].size() * TILESIZE, i * TILESIZE);
    }

    for (int i = 0; i < map[0].size(); i++) {
        SDL_RenderDrawLine(renderer, i * TILESIZE, 0, i * TILESIZE, map.size() * TILESIZE);
    }

    SDL_RenderPresent(renderer);
}