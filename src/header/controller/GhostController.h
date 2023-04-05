//
// Created by iman on 04/04/23.
//

#ifndef PAS_CMAN_GHOSTCONTROLLER_H
#define PAS_CMAN_GHOSTCONTROLLER_H


#include <memory>
#include "CollisionController.h"
#include "header/model/MovableGameObject.h"
#include "header/model/Ghost.h"

using namespace std;

class GhostController {
public:
    GhostController(shared_ptr<Inky> iGhost,shared_ptr<Pinky> pGhost,shared_ptr<Blinky> bGhost,shared_ptr<Clyde> cGhost ,shared_ptr<CollisionController> colController);
    void tick();
    shared_ptr<vector<shared_ptr<Ghost>>> getAllGhosts();

private:
    shared_ptr<CollisionController> collisionController;
    shared_ptr<Inky> inky;
    shared_ptr<Pinky> pinky;
    shared_ptr<Clyde> clyde;
    shared_ptr<Blinky> blinky;
    shared_ptr<vector<shared_ptr<Ghost>>> allGhosts;
};


#endif //PAS_CMAN_GHOSTCONTROLLER_H
