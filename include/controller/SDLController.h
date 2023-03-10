//
// Created by iman on 10/03/23.
//

#ifndef PAS_CMAN_SDLCONTROLLER_H
#define PAS_CMAN_SDLCONTROLLER_H

class SDLController {
public:
    SDLController();
    virtual void tick();
private:
    SDL_Window *pWindow = nullptr;
    SDL_Surface *win_surf = nullptr;
    SDL_Surface *plancheSprites = nullptr;
    SDL_Renderer *renderer = nullptr;

    const SDL_Rect src_bg = {368, 3, 168, 216}; // x,y, w,h (0,0) en haut a gauche
    const SDL_Rect bg = {2, 2, 672, 864}; // ici scale x4
};


#endif //PAS_CMAN_SDLCONTROLLER_H
