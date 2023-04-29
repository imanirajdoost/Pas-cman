//
// Created by iman on 04/04/23.
//

#include "header/controller/GhostController.h"

void GhostController::tick() {
    // TODO: Calculate next pos and pass it here
    inky->setNextPos(Map::map, MoveDirection::RIGHT);
    pinky->setNextPos(Map::map, MoveDirection::RIGHT);
    blinky->setNextPos(Map::map, MoveDirection::RIGHT);
    clyde->setNextPos(Map::map, MoveDirection::RIGHT);

    inky->setMoveIntent(MoveDirection::RIGHT);

    inky->controlMove(*collisionController);
    pinky->controlMove(*collisionController);
    blinky->controlMove(*collisionController);
    clyde->controlMove(*collisionController);
}

GhostController::GhostController(shared_ptr<Inky> iGhost,shared_ptr<Pinky> pGhost,shared_ptr<Blinky> bGhost,shared_ptr<Clyde> cGhost ,shared_ptr<CollisionController> colController) {
    inky = std::move(iGhost);
    pinky = std::move(pGhost);
    blinky = std::move(bGhost);
    clyde = std::move(cGhost);

    vector<shared_ptr<Ghost>> ghosts;
    ghosts.emplace_back(inky);
    ghosts.emplace_back(pinky);
    ghosts.emplace_back(blinky);
    ghosts.emplace_back(clyde);

    allGhosts = make_shared<vector<shared_ptr<Ghost>>>(ghosts);

    collisionController = std::move(colController);
}

shared_ptr<vector<shared_ptr<Ghost>>> GhostController::getAllGhosts() {
    return allGhosts;
}
