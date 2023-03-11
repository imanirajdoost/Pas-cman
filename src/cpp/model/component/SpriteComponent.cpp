//
// Created by iman on 08/03/23.
//

#include <SDL2/SDL_rect.h>
#include "../../../header/model/component/SpriteComponent.h"
#include "../../../header/GameVars.h"

SpriteComponent::SpriteComponent(SDL_Rect _defaultSprite) : default_sp{_defaultSprite} {

}

SpriteComponent::SpriteComponent() {

}

SDL_Rect SpriteComponent::getDrawRect() {
    SDL_Rect drawRect = getRect();

    if (rect.w < TILESIZE) {
        drawRect.x += rect.w / 2;
    }

    if (rect.h < TILESIZE) {
        drawRect.y += rect.h / 2;
    }
    return drawRect;
}
