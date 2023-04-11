#ifndef PAS_CMAN_DOT_H
#define PAS_CMAN_DOT_H

#include "header/model/StaticGameObject.h"
#include "header/model/component/EatableComponent.h"

/**
 * A small dot that Pac-Man eats for points
 */
class Dot : public StaticGameObject, public EatableComponent {
public:
    /**
     * Constructor
     */
    Dot();
};

#endif //PAS_CMAN_DOT_H
