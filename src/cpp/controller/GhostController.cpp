//
// Created by iman on 04/04/23.
//

#include "header/controller/GhostController.h"

void GhostController::tick() {
    // TODO: Calculate next pos and pass it here
    ghost->setNextPos(Map::map, MoveDirection::RIGHT);
//    ghost->move();

    // TODO: Check for collision with player
}

GhostController::GhostController(std::shared_ptr<Ghost> _ghost, std::shared_ptr<CollisionController> colController) {
    ghost = std::move(_ghost);
    collisionController = std::move(colController);
}
