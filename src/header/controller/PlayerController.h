//
// Created by iman on 10/03/23.
//

#ifndef PAS_CMAN_PLAYERCONTROLLER_H
#define PAS_CMAN_PLAYERCONTROLLER_H

#include "header/model/Player.h"

class PlayerController {
public:
    PlayerController();

    void setMoveIntent(Player& player, MoveDirection direction);

    void tick(Player &player);
};


#endif //PAS_CMAN_PLAYERCONTROLLER_H
