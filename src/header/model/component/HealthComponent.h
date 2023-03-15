//
// Created by iman on 08/03/23.
//

#ifndef PAS_CMAN_HEALTHCOMPONENT_H
#define PAS_CMAN_HEALTHCOMPONENT_H

#include "GameComponent.h"

class HealthComponent : public GameComponent {
private:
    short _health;
public:
    explicit HealthComponent(short initHealth);
    short getHealth() const;

    void die();                                  // Die when hit by a ghost
    void gameOver();                             // Game over when no more health is remaining

};


#endif //PAS_CMAN_HEALTHCOMPONENT_H
