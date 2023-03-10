//
// Created by iman on 10/03/23.
//

#ifndef PAS_CMAN_PLAYERCONTROLLER_H
#define PAS_CMAN_PLAYERCONTROLLER_H


#include "model/component/MoveComponent.h"
#include "model/Player.h"

class PlayerController {
public:
    PlayerController();

    virtual void tick();

    void setMoveIntent(MoveDirection direction);

private:
    Player player = Player(2);
};


#endif //PAS_CMAN_PLAYERCONTROLLER_H
