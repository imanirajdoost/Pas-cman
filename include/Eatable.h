#ifndef DOT_H
#define DOT_H

#include "StaticGameObject.h"

class Eatable : public StaticGameObject {

protected:
    bool isEaten;

public:
    Eatable(SDL_Rect defaultSprite, int x, int y);
    virtual void getEaten(const Eatable& dot) = 0;
    void setIndex(u_short indexToSet);
    u_short getIndex() const;
    bool hasBeenEaten() const;

private:
    u_short index;
};

#endif