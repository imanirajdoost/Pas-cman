//
// Created by iman on 10/03/23.
//

#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_system.h>
#include <list>
#include "header/view/SDLViewController.h"
#include "header/GameVars.h"
#include "header/model/Map.h"

void SDLViewController::tick() {
    drawSprites();
    SDL_UpdateWindowSurface(pWindow);
    // LIMITE A 60 FPS
//    SDL_Delay(16); // utiliser SDL_GetTicks64() pour plus de precisions
}

void SDLViewController::drawSprites() {

    // create a black rectangle to update the screen for next frame
    SDL_FillRect(win_surf, nullptr, SDL_MapRGB(win_surf->format, 0, 0, 0));

    SDL_SetColorKey(plancheSprites, false, 0);

    // Draw the background
    drawTarget(&src_bg, &bg);

    // couleur transparente
    SDL_SetColorKey(plancheSprites, true, 0);

    // Draw the dots
    drawDots();

    // Draw the sprites
    for (const auto &sp: *spritesToDraw) {
        auto nextSp = sp->getNextSprite();

        auto drawRect = sp->getDrawRect();

        drawTarget(nextSp.get(), &drawRect);
    }

    // Draw UI
    drawUI();

    drawFruit();

    if (DEBUG_MODE)
        drawDebug(*spritesToDraw);
}

void SDLViewController::drawTarget(SDL_Rect *spriteToDraw, SDL_Rect *drawRect) {

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

void SDLViewController::drawDots() {
    for (auto &dotSmall: dotController->dots) {
        auto draw_rect = dotSmall->getDrawRect();
        drawTarget(dotSmall->getNextSprite().get(), &draw_rect);
    }
}

void SDLViewController::drawUI() {

    for (auto j = textViewController->name_txt_maps.begin(); j < textViewController->name_txt_maps.end(); j++) {
        auto rects = get<4>(*j->get());
        SDL_Rect posRect;
        posRect.x = get<2>(*j->get());
        posRect.y = get<3>(*j->get());
        posRect.w = textViewController->FONT_SIZE;
        posRect.h = textViewController->FONT_SIZE;

        for (auto it = rects.begin(); it != rects.end(); ++it) {
            drawTarget(it->get(), &posRect);
            posRect.x += textViewController->FONT_SPACE;
        }
    }

    // Update Health on UI
    for (auto i = textViewController->health_list.begin(); i < textViewController->health_list.end(); i++)
        drawTarget(&playerHealth, i->get());
}

void SDLViewController::drawFruit() {
    auto draw_rect = fruitController->fruit.getDrawRect();
    drawTarget(fruitController->fruit.getNextSprite().get(), &draw_rect);
}

SDLViewController::SDLViewController(shared_ptr<std::list<shared_ptr<GameObject>>> sps,
                                     shared_ptr<TextViewController> tViewController,
                                     shared_ptr<DotController> dController,
                                     shared_ptr<FruitController> fController, shared_ptr<PauseController> pController) {
    pWindow = SDL_CreateWindow("PacMan", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 900, 900, SDL_WINDOW_SHOWN);
    win_surf = SDL_GetWindowSurface(pWindow);

    renderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_SOFTWARE);

    plancheSprites = SDL_LoadBMP("./pacman_sprites.bmp");

    dotController = std::move(dController);
    fruitController = std::move(fController);
    spritesToDraw = std::move(sps);
    textViewController = std::move(tViewController);
    pauseController = std::move(pController);
}

void SDLViewController::drawDebug(const std::list<shared_ptr<GameObject>> &debugList) {

    // drawSprites the level grid
    draw_grid(100, 100, 20);

    // Draw the collider boxes on the screen
    for (auto &sp: debugList) {
        draw_collider(*sp);
    }
//        draw_collider(player);
//        draw_collider(blinky);
//        draw_collider(pinky);
//        draw_collider(inky);
//        draw_collider(clyde);

//        for (auto & dotSmall : dots) {
//            draw_collider(*dotSmall);
//        }

}
