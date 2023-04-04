#ifndef DOT_H
#define DOT_H

#include "GameComponent.h"

class EatableComponent : public GameComponent {

public:
    EatableComponent();

    short getEaten();

    void setIndex(short indexToSet);

    short getIndex() const;

private:
    short index;
};

#endif