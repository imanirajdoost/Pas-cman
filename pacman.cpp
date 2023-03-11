#include <SDL.h>
#include <iostream>
#include "src/header/Map.h"
#include "src/header/GameVars.h"
#include "src/header/view/ViewManager.h"
#include "src/header/controller/GameController.h"

void init() {

    // Initialize dots on the screen
    ViewManager::init();

    ViewManager::writeOnUI("score_static", "score", 700, 10);
    ViewManager::writeOnUI(ViewManager::SCORE_TEXT_DYNAMIC, "0", ViewManager::SCORE_TEXT_DYNAMIC_POSX,
                           ViewManager::SCORE_TEXT_DYNAMIC_POSY);

//    ViewManager::setHealthUI(player.getHealth());
}

//void draw_collider(const GameObject &obj, int r = 255, int g = 0, int b = 9) {
//    // set renderer color
//    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
//    //SDL_RenderClear( renderer );
//    SDL_Rect debugRect = obj.getRect();
//    // Render rect
//    SDL_RenderDrawRect(renderer, &debugRect);
//    // Render the rect to the screen
//    SDL_RenderPresent(renderer);
//}

// fonction qui met à jour la surface de la fenetre "win_surf"
//void draw() {
//
//    SDL_SetColorKey(plancheSprites, false, 0);
//    SDL_BlitScaled(plancheSprites, &src_bg, win_surf, &bg);
//    // @TODO: This is a hack to avoid writing on top of the previous rect in UI, improve this
//    SDL_BlitScaled(plancheSprites, &blackBg, win_surf, &UIRect);
//
//    // couleur transparente
//    SDL_SetColorKey(plancheSprites, true, 0);
//    // copie du sprite zoomé
//    blinky.draw(plancheSprites, win_surf);
//    pinky.draw(plancheSprites, win_surf);
//    inky.draw(plancheSprites, win_surf);
//    clyde.draw(plancheSprites, win_surf);
//
//    player.draw(plancheSprites, win_surf);
//
//    // Draw UI
//    ViewManager::drawUI(plancheSprites, win_surf);
//
//    for (auto &dotSmall: GameController::dots) {
//        dotSmall->draw(plancheSprites, win_surf);
//    }
//
//    GameController::fruit.draw(plancheSprites, win_surf);
//
//    if (DEBUG_MODE) {
//
//        // draw the level grid
//        draw_grid(100, 100, 20);
//
//        // Draw the collider boxes on the screen
//        draw_collider(player);
//        draw_collider(blinky);
//        draw_collider(pinky);
//        draw_collider(inky);
//        draw_collider(clyde);
//
////        for (auto & dotSmall : dots) {
////            draw_collider(*dotSmall);
////        }
//    }
//}

int main(int argc, char **argv) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "Echec de l'initialisation de la SDL " << SDL_GetError() << std::endl;
        return 1;
    }

    init();

//    std::thread th1(GameController::initBonusTimer);
    GameController gameController;
    gameController.startGame();

    // BOUCLE PRINCIPALE
    bool quit = false;
    while (!quit) {

        SDL_Event event;
        while (!quit && SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    quit = true;
                    break;
                default:
                    break;
            }
        }

        // AFFICHAGE

//        blinky.setNextPos(Map::map, MoveDirection::RIGHT);
//        pinky.setNextPos(Map::map, MoveDirection::RIGHT);
//        inky.setNextPos(Map::map, MoveDirection::RIGHT);
//        clyde.setNextPos(Map::map, MoveDirection::RIGHT);

//        if (!CollisionController::isCollision(Map::map, blinky, MTYPE::GHOST, SDL_Rect())) {
//            blinky.move();
//        } else {
//            blinky.resetNextPos();
//        }
//
//        if (!CollisionController::isCollision(Map::map, pinky, MTYPE::GHOST, SDL_Rect())) {
//            pinky.move();
//        } else {
//            pinky.resetNextPos();
//        }
//
//        if (!CollisionController::isCollision(Map::map, inky, MTYPE::GHOST, SDL_Rect())) {
//            inky.move();
//        } else {
//            inky.resetNextPos();
//        }
//
//        if (!CollisionController::isCollision(Map::map, clyde, MTYPE::GHOST, SDL_Rect())) {
//            clyde.move();
//        } else {
//            clyde.resetNextPos();
//        }


//        player.controlMove();

        draw();
//        SDL_UpdateWindowSurface(pWindow);
        // LIMITE A 60 FPS
//        SDL_Delay(16); // utiliser SDL_GetTicks64() pour plus de precisions
    }
//    SDL_Quit(); // ON SORT
//    th1.join();
    return 0;
}
