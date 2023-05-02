//
// Created by iman on 04/04/23.
//

#include "header/controller/GhostController.h"
#include "header/GameVars.h"

void GhostController::tick() {

    if(getGhostsMode() == Mode::FRIGHTENED) {
        elapedTime += timeController->getElapsedTime();

        if(elapedTime > default_variables::reset_ghost_time - default_variables::time_to_blink_white)
            setAnimation("afraid_white");

        if(elapedTime > default_variables::reset_ghost_time)
            resetGhostMode();
    }

    // TODO: Calculate next pos and pass it here
    inky->setNextPos(Map::map, MoveDirection::RIGHT);
    pinky->setNextPos(Map::map, MoveDirection::RIGHT);
    blinky->setNextPos(Map::map, MoveDirection::RIGHT);
    clyde->setNextPos(Map::map, MoveDirection::RIGHT);

    inky->move();
    pinky->move();
    blinky->move();
    clyde->move();
}

void GhostController::resetGhostMode()
{
    elapedTime = 0;
    changeMode(Mode::CHASE);
}

Mode GhostController::getGhostsMode()
{
    return inky->getMode();
}

void GhostController::setAnimation(const string &animation) {
    for (auto &ghost: *allGhosts) {
        ghost->setAnimation(animation);
    }
}

GhostController::GhostController(shared_ptr<Inky> iGhost, shared_ptr<Pinky> pGhost, shared_ptr<Blinky> bGhost,
                                 shared_ptr<Clyde> cGhost, shared_ptr<CollisionController> colController,
                                 shared_ptr<TimeController> tController) {
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
    timeController = std::move(tController);
}

shared_ptr<vector<shared_ptr<Ghost>>> GhostController::getAllGhosts() {
    return allGhosts;
}

void GhostController::changeMode(Mode mode) {
    auto ghosts = getAllGhosts();

    // set mode for all ghosts
    for (auto &ghost: *ghosts) {
        ghost->setMode(mode);
    }
}
