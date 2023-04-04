//
// Created by iman on 10/03/23.
//

#ifndef PAS_CMAN_SDLVIEWCONTROLLER_H
#define PAS_CMAN_SDLVIEWCONTROLLER_H

#include <list>
#include "header/model/GameObject.h"
#include "header/controller/DotController.h"
#include "header/controller/FruitController.h"
#include "header/view/TextViewController.h"


class SDLViewController {
public:
    SDLViewController(shared_ptr<std::list<shared_ptr<GameObject>>> sps,
                      shared_ptr<TextViewController> tViewController, shared_ptr<DotController>
                      dController,
                      shared_ptr<FruitController> fController
    );

    void tick();

    void drawSprites();

    void drawUI();

    void drawDots();

    void drawFruit();

    void drawDebug(std::list<GameObject> &debugList);

private:
    SDL_Window *pWindow = nullptr;
    SDL_Surface *win_surf = nullptr;
    SDL_Surface *plancheSprites = nullptr;
    SDL_Renderer *renderer = nullptr;

    SDL_Rect src_bg = {368, 3, 168, 216}; // x,y, w,h (0,0) en haut a gauche
    SDL_Rect bg = {2, 2, 672, 864}; // ici scale x4

    SDL_Rect blackBg = {0, 0, 1, 1};
    SDL_Rect UIRect = {700, 0, 200, 200};

    SDL_Rect playerHealth = {169, 76, 10, 12};

    shared_ptr<DotController> dotController;
    shared_ptr<FruitController> fruitController;
    shared_ptr<TextViewController> textViewController;
    shared_ptr<std::list<shared_ptr<GameObject>>> spritesToDraw;

    void draw_collider(const GameObject &obj, int r, int g, int b);

    void draw_grid(int r, int g, int b);

    void drawTarget(SDL_Rect *spriteToDraw, SDL_Rect *drawRect);
};


#endif //PAS_CMAN_SDLVIEWCONTROLLER_H
