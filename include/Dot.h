#ifndef DOT_H
#define DOT_H

#include "StaticGameObject.h"

class Dot : public StaticGameObject {

public:
    Dot(int x, int y);
    void getEaten() const;

protected:
    unsigned int _score;

};

#endif