#ifndef PAS_CMAN_GHOSTCONTROLLER_H
#define PAS_CMAN_GHOSTCONTROLLER_H


#include <memory>
#include "CollisionController.h"
#include "header/model/MovableGameObject.h"
#include "header/model/Ghost.h"
#include "TimeController.h"
#include "AIController.h"
#include "header/model/Player.h"

using namespace std;

class GhostController: IResettable {
public:
    /**
     * @brief Constructor for GhostController
     * @param iGhost shared pointer to the Inky ghost
     * @param pGhost shared pointer to the Pinky ghost
     * @param bGhost shared pointer to the Blinky ghost
     * @param cGhost shared pointer to the Clyde ghost
     * @param colController shared pointer to the CollisionController
     */
    GhostController(shared_ptr<Inky> iGhost,shared_ptr<Pinky> pGhost,shared_ptr<Blinky> bGhost,shared_ptr<Clyde> cGhost, shared_ptr<TimeController> tController,
                    shared_ptr<CollisionController> colController, shared_ptr<AIController> ghostAIController, shared_ptr<Player> p);

    /**
     * @brief Runs each ghost's individual tick method and checks if any collisions occur
     */
    void tick();

    /**
     * @brief Changes the mode of all ghosts
     * @param mode new mode for the ghosts
     */
    void changeMode(Mode mode);

    /**
     * @brief reset controller state
     */
    void reset_state() override;

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
    shared_ptr<TimeController> timeController;
    shared_ptr<AIController> aiController;
    shared_ptr<Player> player;

    ulong elapsedTime;

    vector<TilePosition> blinkyPath;
    vector<TilePosition> inkyPath;
    vector<TilePosition> clydePath;
    vector<TilePosition> pinkyPath;

    Mode worldMode;

    /**
     * @brief Resets the ghost mode to CHASE
     */
    void resetGhostMode();

    /**
     * @brief Sets the animation of all ghosts
     * @param animation new animation for the ghosts
     */
    void setAnimation(const string &animation);

    /**
 * @brief Returns the current mode of the ghost
 * @return current mode of the ghost
 */
    Mode getGhostsMode(Ghost &ghost);

    Mode getWorldMode();
};


#endif //PAS_CMAN_GHOSTCONTROLLER_H
