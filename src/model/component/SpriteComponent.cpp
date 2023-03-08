//
// Created by iman on 08/03/23.
//

#include <SDL2/SDL_rect.h>
#include "../../../include/model/component/SpriteComponent.h"

SDL_Rect SpriteComponent::getRect() const {
    return rect;
}