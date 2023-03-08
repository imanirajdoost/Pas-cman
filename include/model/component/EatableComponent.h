#ifndef DOT_H
#define DOT_H

#include "../StaticGameObject.h"

class EatableComponent : public GameComponent {

protected:
    bool isEaten;

public:
    EatableComponent(SDL_Rect defaultSprite, int x, int y);
    virtual void getEaten(const EatableComponent& dot) = 0;
    void setIndex(u_short indexToSet);
    u_short getIndex() const;
    bool hasBeenEaten() const;

private:
    u_short index;
};

#endif