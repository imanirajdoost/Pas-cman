//
// Created by iman on 04/04/23.
//

#ifndef PAS_CMAN_TIMECONTROLLER_H
#define PAS_CMAN_TIMECONTROLLER_H
#include <chrono>
using namespace std::chrono;

// Use auto keyword to avoid typing long
// type definitions to get the timepoint
// at this instant use function now()

class TimeController {
public:
    TimeController();

    void startTimer();

    void tick();

    long getElapsedTime() const;

    long getLastFrameTime() const;

private:
    long elapsed_time;
    long last_frame_time;

    time_point<high_resolution_clock> start;
    time_point<high_resolution_clock> stop;
};


#endif //PAS_CMAN_TIMECONTROLLER_H
