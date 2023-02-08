#ifndef DOT_H
#define DOT_H

#include "StaticGameObject.h"

class Dot : public StaticGameObject {

public:
    Dot(int x, int y);
    virtual void getEaten(const Dot& dot) const = 0;
    void setIndex(u_short indexToSet);
    u_short getIndex() const;

private:
    u_short index;
};

#endif