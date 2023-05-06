/**
@file PauseController.h
@brief This class handles pausing and resuming of the game.
*/

#ifndef PAS_CMAN_PAUSECONTROLLER_H
#define PAS_CMAN_PAUSECONTROLLER_H


#include <memory>
#include "TimeController.h"
#include <functional>

using namespace std;

class PauseController {
public:
    /**
 * @brief Constructor for PauseController class.
 *
 * @param tController A shared pointer to the TimeController object.
 */
    explicit PauseController(shared_ptr<TimeController> tController);

/**
 * @brief Pauses the game.
 *
 * This function pauses the game by setting the 'isPaused' flag to true.
 * It also stores the current time in 'pauseTime'.
 */
    void pause();

/**
 * @brief Resumes the game.
 *
 * This function resumes the game by setting the 'isPaused' flag to false
 * and adding the time elapsed during the pause to 'pauseTime'.
 */
    void resume();

/**
 * @brief Pauses the game for a specific amount of time.
 *
 * This function pauses the game for a specific amount of time by calling
 * the 'pause' function and then setting a timer using the TimeController
 * object.
 *
 * @param milliSec The amount of time to pause the game for in milliseconds.
 */
    void pauseFor(long milliSec, function<void(bool)> callback = nullptr, bool cbackBool = false);

/**
 * @brief Updates the pause state.
 *
 * This function updates the pause state of the game. If the game is currently
 * paused, it adds the elapsed time since the last frame to 'pauseTime'.
 * Otherwise, it does nothing.
 */
    void tick();

/**
 * @brief Returns the current pause state.
 *
 * @return True if the game is paused, false otherwise.
 */
    bool hasPaused() const;

private:
    bool isPaused; /** < A flag indicating if the game is paused or not. */

    long long pauseTime; /**< The time when the game was paused. */

    shared_ptr<TimeController> timeController; /**< A shared pointer to the TimeController object. */

    function<void(bool)> resumeCallback; /**< A callback function to be called when the game is paused. */

    bool callBackBool; /**< A boolean value to be passed to the callback function. */
};


#endif //PAS_CMAN_PAUSECONTROLLER_H
