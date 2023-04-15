/**
 * @file HealthComponent.h
 * @brief Class inherited by all objects with health management such as Pacman player
 */

#ifndef PAS_CMAN_HEALTHCOMPONENT_H
#define PAS_CMAN_HEALTHCOMPONENT_H

#include "GameComponent.h"

class HealthComponent : public GameComponent {
private:
    short _health; /**< The health value of the object */
public:
    /**
     * @brief Constructor for HealthComponent class
     * @param initHealth The initial health value for the object
     */
    explicit HealthComponent(short initHealth);

    /**
     * @brief Getter for the health value of the object
     * @return The health value of the object
     */
    short getHealth() const;

    /**
     * @brief Method to handle the object's death when hit by a ghost
     */
    virtual short die();
};

#endif //PAS_CMAN_HEALTHCOMPONENT_H
