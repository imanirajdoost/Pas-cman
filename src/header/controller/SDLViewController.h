//
// Created by iman on 10/03/23.
//

#ifndef PAS_CMAN_SDLVIEWCONTROLLER_H
#define PAS_CMAN_SDLVIEWCONTROLLER_H

#include "../model/GameObject.h"

class SDLViewController {
public:
    SDLViewController();
    virtual void tick();
    void draw();
    void draw_sprite(SDL_Rect *spriteToDraw, SDL_Rect *drawRect);
private:
    SDL_Window *pWindow = nullptr;
    SDL_Surface *win_surf = nullptr;
    SDL_Surface *plancheSprites = nullptr;
    SDL_Renderer *renderer = nullptr;

    SDL_Rect src_bg = {368, 3, 168, 216}; // x,y, w,h (0,0) en haut a gauche
    SDL_Rect bg = {2, 2, 672, 864}; // ici scale x4

    SDL_Rect blackBg = {0, 0, 1, 1};
    SDL_Rect UIRect  = {700, 0, 200, 200};

    void draw_collider(const GameObject &obj, int r, int g, int b);

    void draw_grid(int r, int g, int b);
};


#endif //PAS_CMAN_SDLVIEWCONTROLLER_H
