#ifndef DOT_H
#define DOT_H

#include "StaticGameObject.h"

class Dot : public StaticGameObject {

protected:
    bool isEaten;

public:
    Dot(int x, int y);
    virtual void getEaten(const Dot& dot) = 0;
    void setIndex(u_short indexToSet);
    u_short getIndex() const;
    bool hasBeenEaten() const;

private:
    u_short index;
};

#endif