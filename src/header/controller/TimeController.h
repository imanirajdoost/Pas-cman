#ifndef PAS_CMAN_TIMECONTROLLER_H
#define PAS_CMAN_TIMECONTROLLER_H

#include <chrono>
#include <SDL.h>
#include <memory>
#include "LevelController.h"

using namespace std;

/**
 * A class that manages time-related operations and tracking of elapsed and last frame time.
 */
class TimeController {
public:
    TimeController(shared_ptr<LevelController> lController);

    /**
     * Starts the timer.
     */
    void tick_start();

    /**
     * captures the frame time and elapsed time.
     */
    void tick_end();

    /**
     * Gets the elapsed time in milliseconds.
     * @return The elapsed time in milliseconds.
     */
    Uint64 getElapsedTime() const;

    /**
     * Gets the last frame time in milliseconds.
     * @return The last frame time in milliseconds.
     */
    Uint64 getLastFrameTime() const;

    /**
     * Updates the FPS to have a consistent speed in game
     */
    void updateFPS();

private:
    ulong elapsed_time; // Elapsed time in milliseconds
    ulong last_frame_time; // Last frame time in milliseconds

    Uint64 start;
    Uint64 next_time;

    chrono::time_point<chrono::steady_clock> last;

    shared_ptr<LevelController> levelController;

    /**
     * Calculates the time left until the next frame.
     * @return The time left in milliseconds.
     */
    Uint64 time_left() const;

    ulong getTimeSpeed();
};

#endif //PAS_CMAN_TIMECONTROLLER_H
