#ifndef PAS_CMAN_FRUIT_H
#define PAS_CMAN_FRUIT_H

#include "header/model/StaticGameObject.h"
#include "header/model/component/EatableComponent.h"

class Fruit : public StaticGameObject , public EatableComponent {
public:
    Fruit();
private:
    const SDL_Rect sp_fruit = {290, 238, 12, 13 };
};


#endif //PAS_CMAN_FRUIT_H
