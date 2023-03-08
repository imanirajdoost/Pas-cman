#ifndef PAS_CMAN_FRUIT_H
#define PAS_CMAN_FRUIT_H

#include "../StaticGameObject.h"
#include "../component/EatableComponent.h"

class Fruit : public StaticGameObject ,public EatableComponent {
public:
    Fruit(int x, int y);
    void getEaten(const EatableComponent& dot) override;
};


#endif //PAS_CMAN_FRUIT_H
