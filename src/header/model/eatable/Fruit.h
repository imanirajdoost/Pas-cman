/**
 * @file Fruit.h
 * @brief Header file for the Fruit class
 *
 */

#ifndef PAS_CMAN_FRUIT_H
#define PAS_CMAN_FRUIT_H

#include "header/model/StaticGameObject.h"
#include "header/model/component/EatableComponent.h"

using namespace std;

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

    /**
     * @brief Picks a random fruit sprite from the fruit_sprites vector.
     */
    void pick_sprite_randomly();

    vector<shared_ptr<SDL_Rect>> get_sprites();

private:
    const SDL_Rect sp_fruit1 = {290, 238, 12, 13 }; ///< The sprite sheet coordinates for the 1st fruit
    const SDL_Rect sp_fruit2 = {307, 238, 11, 12 }; ///< The sprite sheet coordinates for the 2nd fruit
    const SDL_Rect sp_fruit3 = {322, 238, 12, 12 }; ///< The sprite sheet coordinates for the 3rd fruit
    const SDL_Rect sp_fruit4 = {338, 238, 12, 13 }; ///< The sprite sheet coordinates for the 4th fruit

    vector<shared_ptr<SDL_Rect>> fruit_sprites; ///< A vector containing all the fruit sprites
};

#endif //PAS_CMAN_FRUIT_H
