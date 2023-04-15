#ifndef GAMEVARS_H
#define GAMEVARS_H

#include <SDL.h>

namespace constants {

    /** @brief Update interval of the game.
     * Decrease this value to make the game faster */
    const Uint64 TICK_INTERVAL = 20;

    /** @brief Tile size in pixels. */
#define TILESIZE 32

    /** @brief Debug mode flag. */
#define DEBUG_MODE 0

    /** @brief Show FPS flag. */
#define SHOW_FPS 1

    /** @brief Animation frame rate in frames per second. */
#define ANIMATION_DEFAULT_SPEED 4

    /** @brief Small dot size in pixels. */
#define SMALL_DOT_SIZE 10

    /** @brief Score awarded for eating a small dot. */
#define SMALL_DOT_SCORE 10

    /** @brief Big dot size in pixels. */
#define BIG_DOT_SIZE 20

    /** @brief Score awarded for eating a big dot. */
#define BIG_DOT_SCORE 50

    /** @brief Score awarded for eating a fruit. */
#define FRUIT_SCORE 100

    /** @brief Minimum time before a fruit can spawn. */
#define MIN_TIME_TO_SPAWN_FRUIT 10000

    /** @brief Time between fruit spawns. */
#define FRUIT_SPAWN_TIME 15000

    /** @brief Time fruit is available for. */
#define FRUIT_AVAILABE_TIME 5000
}

namespace default_positions {
    const SDL_Rect player_default_pos{10 * TILESIZE, 20 * TILESIZE};

    const SDL_Rect blinky_default_pos{TILESIZE, TILESIZE};
    const SDL_Rect inky_default_pos{2 * TILESIZE, TILESIZE};
    const SDL_Rect pinky_default_pos{3 * TILESIZE, TILESIZE};
    const SDL_Rect clyde_default_pos{4 * TILESIZE, TILESIZE};

    const SDL_Rect global_default_pos{-100, -100};
}

namespace default_variables {
    const int player_default_health = 2;

    const int reset_level_time = 1000;
}

namespace default_sprites {

    /** @brief Default sprite for the player. */
    const SDL_Rect player_sp_default{4, 90, 14, 14};

    /** @brief Default sprite for Blinky. */
    const SDL_Rect blinky_sp_default = {4, 124, 14, 14};

    /** @brief Default sprite for Pinky. */
    const SDL_Rect pinky_sp_default = {4, 142, 14, 14};

    /** @brief Default sprite for Inky. */
    const SDL_Rect inky_sp_default = {4, 160, 14, 14};

    /** @brief Default sprite for Clyde. */
    const SDL_Rect clyde_sp_default = {4, 178, 14, 14};

    /** @brief Default sprite for Dot Big. */
    const SDL_Rect dot_big_default = {9, 79, 7, 7};

    /** @brief empty black sprite. */
    const SDL_Rect empty_black_sp = {184, 103, 16, 16};
}

#endif
