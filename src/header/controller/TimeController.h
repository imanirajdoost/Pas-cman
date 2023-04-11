#ifndef PAS_CMAN_TIMECONTROLLER_H
#define PAS_CMAN_TIMECONTROLLER_H

#include <chrono>
using namespace std::chrono;

/**
 * A class that manages time-related operations and tracking of elapsed and last frame time.
 */
class TimeController {
public:
    TimeController();

    /**
     * Starts the timer.
     */
    void startTimer();

    /**
     * Calculates elapsed time and last frame time.
     */
    void tick();

    /**
     * Gets the elapsed time in milliseconds.
     * @return The elapsed time in milliseconds.
     */
    long getElapsedTime() const;

    /**
     * Gets the last frame time in milliseconds.
     * @return The last frame time in milliseconds.
     */
    long getLastFrameTime() const;

private:
    long elapsed_time; // Elapsed time in milliseconds
    long last_frame_time; // Last frame time in milliseconds

    time_point<high_resolution_clock> start;
    time_point<high_resolution_clock> stop;
};

#endif //PAS_CMAN_TIMECONTROLLER_H
