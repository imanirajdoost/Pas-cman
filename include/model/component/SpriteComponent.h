//
// Created by iman on 08/03/23.
//

#ifndef PAS_CMAN_SPRITECOMPONENT_H
#define PAS_CMAN_SPRITECOMPONENT_H


#include <memory>
#include "GameComponent.h"

class SpriteComponent : public GameComponent {
public:
        SDL_Rect getRect() const;

protected:
    shared_ptr<SDL_Rect> current_sp = nullptr;
    SDL_Rect rect;

    SDL_Rect default_sp;
};


#endif //PAS_CMAN_SPRITECOMPONENT_H
