//
// Created by iman on 08/03/23.
//

#ifndef PAS_CMAN_TRANSFORMCOMPONENT_H
#define PAS_CMAN_TRANSFORMCOMPONENT_H

#include "GameComponent.h"
#include <SDL_rect.h>

class TransformComponent : public GameComponent {
public:
    TransformComponent();
    void setPos(int x, int y);

    SDL_Rect getRect() const;

    int getX() const;

    int getY() const;

    void setX(int x);

    void setY(int Y);

protected:
    SDL_Rect rect;
};


#endif //PAS_CMAN_TRANSFORMCOMPONENT_H
