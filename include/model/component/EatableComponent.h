#ifndef DOT_H
#define DOT_H

#include "../StaticGameObject.h"

class EatableComponent : public GameComponent {

protected:
    bool isEaten;

public:
    EatableComponent();

    void getEaten(const EatableComponent &dot);

    void setIndex(short indexToSet);

    short getIndex() const;

    bool hasBeenEaten() const;

private:
    short index;
};

#endif