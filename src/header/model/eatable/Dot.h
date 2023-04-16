#ifndef PAS_CMAN_DOT_H
#define PAS_CMAN_DOT_H

#include "header/model/StaticGameObject.h"
#include "header/model/component/EatableComponent.h"

enum class DotType {
    SMALL,
    BIG
};

/**
 * A small dot that Pac-Man eats for points
 */
class Dot : public StaticGameObject, public EatableComponent {
public:
    /**
     * Constructor
     */
    Dot();

    /**
     * Returns the type of the dot
     * @return The type of the dot
     */
    virtual DotType getDotType() const = 0;
};

#endif //PAS_CMAN_DOT_H
