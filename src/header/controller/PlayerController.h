//
// Created by iman on 10/03/23.
//

#ifndef PAS_CMAN_PLAYERCONTROLLER_H
#define PAS_CMAN_PLAYERCONTROLLER_H

#include "header/model/Player.h"
#include "DotController.h"
#include "FruitController.h"

class PlayerController {
public:
    PlayerController(shared_ptr<CollisionController> colController, shared_ptr<Player> p, shared_ptr<DotController> dController, shared_ptr<FruitController> fController);

    void setMoveIntent(MoveDirection direction);

    void tick();

private:
    shared_ptr<CollisionController> collisionController;
    shared_ptr<DotController> dotController;
    shared_ptr<FruitController> fruitController;
    shared_ptr<Player> player;
};


#endif //PAS_CMAN_PLAYERCONTROLLER_H
