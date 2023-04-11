/**
 * @file Fruit.h
 * @brief Header file for the Fruit class
 *
 */

#ifndef PAS_CMAN_FRUIT_H
#define PAS_CMAN_FRUIT_H

#include "header/model/StaticGameObject.h"
#include "header/model/component/EatableComponent.h"

/**
 * @brief The Fruit class
 *
 * The Fruit class is a subclass of StaticGameObject and EatableComponent. It represents a fruit object in the game that Pacman can eat.
 */
class Fruit : public StaticGameObject , public EatableComponent {
public:
    /**
     * @brief Constructs a new Fruit object
     */
    Fruit();

private:
    const SDL_Rect sp_fruit = {290, 238, 12, 13 }; ///< The sprite sheet coordinates for the fruit
};

#endif //PAS_CMAN_FRUIT_H
