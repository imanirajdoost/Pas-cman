#ifndef PAS_CMAN_GHOSTCONTROLLER_H
#define PAS_CMAN_GHOSTCONTROLLER_H


#include <memory>
#include "CollisionController.h"
#include "header/model/MovableGameObject.h"
#include "header/model/Ghost.h"

using namespace std;

class GhostController {
public:
    /**
     * @brief Constructor for GhostController
     * @param iGhost shared pointer to the Inky ghost
     * @param pGhost shared pointer to the Pinky ghost
     * @param bGhost shared pointer to the Blinky ghost
     * @param cGhost shared pointer to the Clyde ghost
     * @param colController shared pointer to the CollisionController
     */
    GhostController(shared_ptr<Inky> iGhost,shared_ptr<Pinky> pGhost,shared_ptr<Blinky> bGhost,shared_ptr<Clyde> cGhost ,shared_ptr<CollisionController> colController);

    /**
     * @brief Runs each ghost's individual tick method and checks if any collisions occur
     */
    void tick();

    /**
     * @brief Returns all ghosts as a shared pointer to a vector of shared pointers to Ghost objects
     * @return shared pointer to a vector of shared pointers to Ghost objects
     */
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
