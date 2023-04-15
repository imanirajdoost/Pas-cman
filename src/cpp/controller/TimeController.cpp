//
// Created by iman on 04/04/23.
//

#include <iostream>
#include "header/controller/TimeController.h"
#include "header/GameVars.h"

TimeController::TimeController() {
    elapsed_time = 0;

    // Initialize SDL
    next_time = SDL_GetTicks64() + constants::TICK_INTERVAL;
}

Uint64 TimeController::getElapsedTime() const {
    return elapsed_time;
}

Uint64 TimeController::getLastFrameTime() const {
    return last_frame_time;
}

Uint64 TimeController::time_left() const {
    Uint64 now = SDL_GetTicks64();
    if (next_time <= now)
        return 0;
    else
        return next_time - now;
}

void TimeController::updateFPS() {
    SDL_Delay(time_left());
    next_time += constants::TICK_INTERVAL;
}

void TimeController::tick_start() {
    start = SDL_GetTicks64();
}

void TimeController::tick_end() {
    Uint64 end = SDL_GetTicks();

    if (DEBUG_MODE && SHOW_FPS)
        std::cout << "Frame time: " << end - start << "ms" << std::endl;

    elapsed_time += end - start;
    last_frame_time = end - start;

    updateFPS();
}
