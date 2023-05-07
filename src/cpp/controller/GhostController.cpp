#include <iostream>
#include "header/controller/GhostController.h"
#include "header/GameVars.h"

void GhostController::tick() {

    if (getWorldMode() == Mode::FRIGHTENED) {
        elapsedTime += timeController->getLastFrameTime();

        // for each ghost, control the animation
        for (auto &g: *getAllGhosts()) {
            if (g->getMode() == Mode::FRIGHTENED) {
                if (elapsedTime > default_variables::reset_ghost_time - default_variables::time_to_blink_white)
                    g->setAnimation("afraid_white");
                else
                    g->setAnimation("afraid");
            }
        }

        if (elapsedTime > default_variables::reset_ghost_time)
            resetGhostMode();
    }

    // for each ghost, with a chance of 8/10 go to chase mode and follow player, with a chance of 2/10 go to scatter mode and go to scatter position
    for (auto &g: *getAllGhosts()) {
        if (g->getMode() == Mode::FRIGHTENED) {
            updatePath(*g, TilePosition(player->getTileY(), player->getTileX()), g->getScatterTile());

        } else if (g->getMode() == Mode::CHASE) {
            if (rand() % 10 < 8) {
                // if path is empty, then calculate a new path.
                // if not, then randomly keep the current path or calculate a new one
                if (g->pathList.empty()) {
                    updatePath(*g, TilePosition(g->getTileY(), g->getTileX()),
                               TilePosition(player->getTileY(), player->getTileX()));
                } else {
                    if (rand() % 10 < 5) {
                        updatePath(*g, TilePosition(g->getTileY(), g->getTileX()),
                                   TilePosition(player->getTileY(), player->getTileX()));
                    } else {
                        // do nothing, just use what is already in the pathlist
                    }
                }
            } else {
                g->setMode(Mode::SCATTER);
                updatePath(*g, TilePosition(g->getTileY(), g->getTileX()), g->getScatterTile());
            }
        } else if (g->getMode() == Mode::SCATTER) {
            // if in the scatter mode, the ghost is close to the scatter tile, then change the mode
            if (g->getTileX() == g->getScatterTile().indexY && g->getTileY() == g->getScatterTile().indexX) {
                g->setMode(Mode::CHASE);
                updatePath(*g, TilePosition(g->getTileY(), g->getTileX()),
                           TilePosition(player->getTileY(), player->getTileX()));

                continue;
            }

            if (rand() % 10 < 2) {
                g->setMode(Mode::CHASE);
                updatePath(*g, TilePosition(g->getTileY(), g->getTileX()),
                           TilePosition(player->getTileY(), player->getTileX()));
            } else {
                g->setMode(Mode::SCATTER);
                updatePath(*g, TilePosition(g->getTileY(), g->getTileX()), g->getScatterTile());
            }
        }


        // if path is not empty, then set next moveIntent based on the next path tile
        if (!g->pathList.empty()) {
            auto nextTile = g->pathList.front();
//            std::cout << "Next tile: " << nextTile.indexX << ", " << nextTile.indexY << std::endl;

            // !!!! ATTENTION: X and Y are inversed in the MAP !!!!
            if (nextTile.indexY > g->getTileX() && nextTile.indexX == g->getTileY())
                g->setMoveIntent(MoveDirection::RIGHT);
            else if (nextTile.indexY < g->getTileX() && nextTile.indexX == g->getTileY())
                g->setMoveIntent(MoveDirection::LEFT);
            else if (nextTile.indexX > g->getTileY() && nextTile.indexY == g->getTileX())
                g->setMoveIntent(MoveDirection::DOWN);
            else if (nextTile.indexX < g->getTileY() && nextTile.indexY == g->getTileX())
                g->setMoveIntent(MoveDirection::UP);
        }

        g->controlMove(*collisionController);
    }
}

void GhostController::updatePath(Ghost &ghost, const TilePosition &from, const TilePosition &to) {
    ghost.pathList = aiController->getPath(from, to);
}

Mode GhostController::getWorldMode() {
    return worldMode;
}

void GhostController::resetGhostMode() {
    elapsedTime = 0;
    changeMode(Mode::CHASE);
}

Mode GhostController::getGhostsMode(Ghost &ghost) {
    return ghost.getMode();
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

    worldMode = Mode::CHASE;
}

shared_ptr<vector<shared_ptr<Ghost>>> GhostController::getAllGhosts() {
    return allGhosts;
}

void GhostController::changeMode(Mode mode) {
    auto ghosts = getAllGhosts();
    worldMode = mode;
    elapsedTime = 0;

    // set mode for all ghosts
    for (auto &ghost: *ghosts) {
        ghost->setMode(mode);
    }
}

void GhostController::reset_state() {
    changeMode(Mode::CHASE);
}
