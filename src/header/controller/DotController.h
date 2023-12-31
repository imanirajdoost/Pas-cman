/**
@file DotController.h
@brief This file contains the declaration of the DotController class.
*/

#ifndef PAS_CMAN_DOTCONTROLLER_H
#define PAS_CMAN_DOTCONTROLLER_H

#include <vector>
#include <memory>
#include "header/model/component/EatableComponent.h"
#include "header/model/eatable/DotSmall.h"
#include "header/model/eatable/DotBig.h"
#include "PauseController.h"
#include "header/view/TextViewController.h"
#include "ScoreController.h"
#include "GhostController.h"

using namespace std;

/**
@class DotController
@brief Manages the creation, deletion and tracking of Dots in the game
*/
class DotController: IResettable {
public:

    /**
@brief Constructor for the DotController class
@param pController The PauseController instance
@param tController The TextViewController instance
*/
    explicit DotController(function<void(bool)> gOverFunction, shared_ptr<GhostController> gController);

    /**
@brief Spawns a DotSmall object at the given position
@param x The x-coordinate of the position
@param y The y-coordinate of the position
@return A shared_ptr to the spawned DotSmall object
*/
    shared_ptr<DotSmall> spawnDotSmall(int x, int y);

    /**
@brief Spawns all the Dot objects in the game map
@return A vector of shared_ptr to the spawned Dot objects
*/
    vector<shared_ptr<Dot>> spawnDotObjects();

    /**
@brief Spawns a DotBig object at the given position
@param x The x-coordinate of the position
@param y The y-coordinate of the position
@return A shared_ptr to the spawned DotBig object
*/
    shared_ptr<DotBig> spawnDotBig(int x, int y);

    /**
@brief Deletes the given Dot object from the dots vector
@param dot The Dot object to be deleted
*/
    void deleteDot(const Dot &dot);

    /**
@brief Checks if a Big Dot exists at the given position
@param i The x-coordinate of the position
@param j The y-coordinate of the position
@return True if a Big Dot exists, False otherwise
*/
    bool isBigDot(int i, int j);

    /**
     * @brief Resets the state of the DotController
     */
    void reset_state() override;


    /**
@brief A vector to store all the Dot instances
*/
    vector<shared_ptr<Dot>> dots;

private:

    /**
     * @brief The GhostController instance
     */
    shared_ptr<GhostController> ghostController;

    /**
     * @brief The function to be called when the game is over
     */
    function<void(bool)> gameOverFunction;

    /**
 * @brief An index to keep track of the Dots
 */
    short dotIndex = 0;

    /**
 * @brief The positions of the Big Dots in the game map
 */
    const vector<vector<int>> bigDotPositions = {
            {3,  1},
            {3,  19},
            {20, 1},
            {20, 19}
    };
};


#endif //PAS_CMAN_DOTCONTROLLER_H
