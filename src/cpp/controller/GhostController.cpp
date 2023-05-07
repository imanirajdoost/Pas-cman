#include <iostream>
#include "header/controller/GhostController.h"
#include "header/GameVars.h"

void GhostController::tick() {

    if (getGhostsMode() == Mode::FRIGHTENED) {
        elapsedTime += timeController->getLastFrameTime();

        if (elapsedTime > default_variables::reset_ghost_time - default_variables::time_to_blink_white)
            setAnimation("afraid_white");
        else
            setAnimation("afraid");

        if (elapsedTime > default_variables::reset_ghost_time)
            resetGhostMode();
    }

    // TODO: Calculate next pos and pass it here
    auto path = aiController->getPath(TilePosition(inky->getTileY(), inky->getTileX()),
                          TilePosition(player->getTileY(), player->getTileX()));

    // if path is not empty, then set next moveIntent based on the next path tile
    if (!path.empty()) {
        auto nextTile = path.front();
        std::cout << "Next tile: " << nextTile.indexX << ", " << nextTile.indexY << std::endl;

        // !!!! ATTENTION: X and Y are inversed in the MAP !!!!
        if(nextTile.indexY > inky->getTileX() && nextTile.indexX  == inky->getTileY())
            inky->setMoveIntent(MoveDirection::RIGHT);
        else if(nextTile.indexY < inky->getTileX() && nextTile.indexX  == inky->getTileY())
            inky->setMoveIntent(MoveDirection::LEFT);
        else if(nextTile.indexX > inky->getTileY() && nextTile.indexY  == inky->getTileX())
            inky->setMoveIntent(MoveDirection::DOWN);
        else if(nextTile.indexX < inky->getTileY() && nextTile.indexY  == inky->getTileX())
            inky->setMoveIntent(MoveDirection::UP);
    }


    inky->controlMove(*collisionController);
    pinky->controlMove(*collisionController);
    blinky->controlMove(*collisionController);
    clyde->controlMove(*collisionController);
//    inky->setNextPos(Map::map, MoveDirection::RIGHT);
//    pinky->setNextPos(Map::map, MoveDirection::RIGHT);
//    blinky->setNextPos(Map::map, MoveDirection::RIGHT);
//    clyde->setNextPos(Map::map, MoveDirection::RIGHT);
//
//    inky->move();
//    pinky->move();
//    blinky->move();
//    clyde->move();
}

void GhostController::resetGhostMode() {
    elapsedTime = 0;
    changeMode(Mode::CHASE);
}

Mode GhostController::getGhostsMode() {
    return inky->getMode();
}

void GhostController::setAnimation(const string &animation) {
    for (auto &ghost: *allGhosts) {
        ghost->setAnimation(animation);
    }
}

GhostController::GhostController(shared_ptr<Inky> iGhost, shared_ptr<Pinky> pGhost, shared_ptr<Blinky> bGhost,
                                 shared_ptr<Clyde> cGhost,
                                 shared_ptr<TimeController> tController, shared_ptr<CollisionController> colController,
                                 shared_ptr<AIController> ghostAIController, shared_ptr<Player> p) {
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

    timeController = std::move(tController);
    collisionController = std::move(colController);
    aiController = std::move(ghostAIController);
    player = std::move(p);
}

shared_ptr<vector<shared_ptr<Ghost>>> GhostController::getAllGhosts() {
    return allGhosts;
}

void GhostController::changeMode(Mode mode) {
    auto ghosts = getAllGhosts();
    elapsedTime = 0;

    // set mode for all ghosts
    for (auto &ghost: *ghosts) {
        ghost->setMode(mode);
    }
}

void GhostController::reset_state() {
    changeMode(Mode::CHASE);
}
