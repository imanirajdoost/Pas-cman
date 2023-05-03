#include <iostream>
#include "header/controller/TimeController.h"
#include "header/GameVars.h"

TimeController::TimeController(shared_ptr<LevelController> lController) {
    elapsed_time = 0;

    levelController = std::move(lController);

    // Initialize clock
    last = std::chrono::steady_clock::now();

    // Initialize SDL
    next_time = SDL_GetTicks() + getTimeSpeed();
}

ulong TimeController::getTimeSpeed() {
    ulong gameSpeed = constants::TICK_INTERVAL - levelController->getCurrentLevelIndex();
    if (gameSpeed < constants::MAX_GAME_SPEED) {
        return constants::MAX_GAME_SPEED;
    } else {
        return gameSpeed;
    }
}

Uint64 TimeController::getElapsedTime() const {
    return elapsed_time;
}

Uint64 TimeController::getLastFrameTime() const {
    return last_frame_time;
}

Uint64 TimeController::time_left() const {
    Uint64 now = SDL_GetTicks();
    if (next_time <= now)
        return 0;
    else
        return next_time - now;
}

void TimeController::updateFPS() {
    SDL_Delay(time_left());
    next_time += getTimeSpeed();
}

void TimeController::tick_start() {
    start = SDL_GetTicks();
}

void TimeController::tick_end() {
    auto elapsed = std::chrono::steady_clock::now() - last;
    const auto delta_time = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
    last = std::chrono::steady_clock::now();

    elapsed_time += delta_time / 1000.0;
    last_frame_time = delta_time / 1000.0;

//    Uint64 end = SDL_GetTicks();
//    elapsed_time += end - start;
//    last_frame_time = end - start;

    if (SHOW_FPS)
        std::cout << "Frame time: " << last_frame_time << "ms. Elapsed time: " << elapsed_time << "ms." << std::endl;

    updateFPS();
}
