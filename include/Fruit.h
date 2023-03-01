#ifndef PAS_CMAN_FRUIT_H
#define PAS_CMAN_FRUIT_H

#include "StaticGameObject.h"
#include "Eatable.h"

class Fruit : public Eatable {
public:
    Fruit(int x, int y);
    void getEaten(const Eatable& dot) override;
};


#endif //PAS_CMAN_FRUIT_H
