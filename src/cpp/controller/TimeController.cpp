//
// Created by iman on 04/04/23.
//

#include "header/controller/TimeController.h"

TimeController::TimeController() {
    elapsed_time = 0;
}

void TimeController::tick() {
    // After function call
    stop = high_resolution_clock::now();


//Predefined units are nanoseconds, microseconds, milliseconds,
// seconds, minutes, hours. Use duration_cast() function.
// The duration variable is the 'Frame time'
    auto duration = duration_cast<milliseconds>(stop - start);

    last_frame_time = duration.count();
    elapsed_time += duration.count();

//    std::cout << "Elapsed time: " << elapsed_time << "ms" << std::endl;
//    std::cout << "frame time: " << duration.count() << "ms" << std::endl;

    start = stop;
}

long TimeController::getElapsedTime() const {
    return elapsed_time;
}

void TimeController::startTimer() {
    start = high_resolution_clock::now();
}

long TimeController::getLastFrameTime() const {
    return last_frame_time;
}
