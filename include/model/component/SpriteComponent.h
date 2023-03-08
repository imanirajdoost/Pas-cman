//
// Created by iman on 08/03/23.
//

#ifndef PAS_CMAN_SPRITECOMPONENT_H
#define PAS_CMAN_SPRITECOMPONENT_H


#include <memory>
#include <SDL_rect.h>
#include "GameComponent.h"

class SpriteComponent : public GameComponent {
public:
    explicit SpriteComponent(SDL_Rect _defaultSprite);

    SpriteComponent();

protected:
    std::shared_ptr<SDL_Rect> current_sp = nullptr;
    SDL_Rect default_sp;
};


#endif //PAS_CMAN_SPRITECOMPONENT_H
