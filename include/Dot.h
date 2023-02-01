#ifndef DOT_H
#define DOT_H

#include "StaticGameObject.h"

class Dot : StaticGameObject {

public:
    void getEaten();

protected:
    unsigned int _score;

};

#endif