#ifndef GAMEVARS_H
#define GAMEVARS_H

#include <SDL.h>

namespace constants {

    /** @brief Update interval of the game.
     * Decrease this value to make the game faster */
    const Uint64 TICK_INTERVAL = 20;

    /** @brief Maximum game speed (calculated from TICK_INTERVAL and LevelController.levelIndex) */
    const int MAX_GAME_SPEED = 10;

    /** @brief Tile size in pixels. */
#define TILESIZE 32

    /** @brief Debug mode flag. */
#define DEBUG_MODE 0

    /** @brief Show FPS flag. */
#define SHOW_FPS 0

    /** @brief Animation frame rate in frames per second. */
#define ANIMATION_DEFAULT_SPEED 30

    /** @brief Small dot size in pixels. */
#define SMALL_DOT_SIZE 8

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

namespace default_animation_speed {
    /** @brief Animation speed for the ghosts. */
#define GHOST_ANIMATION_SPEED 10

    /** @brief Animation speed for the player. */
#define PLAYER_ANIMATION_SPEED 10

    /** @brief Animation speed for the player death. */
#define PLAYER_DEATH_ANIMATION_SPEED 5

    /** @brief Animation speed for the big dot. */
#define BIG_DOT_ANIMATION_SPEED 5
}


namespace default_positions {
    /** @brief Default position for the player. */
    const SDL_Rect player_default_pos{10 * TILESIZE, 20 * TILESIZE};

    /** @brief Default position for Blinky. */
    const SDL_Rect blinky_default_pos{TILESIZE, TILESIZE};

    /** @brief Default position for Inky. */
    const SDL_Rect inky_default_pos{2 * TILESIZE, TILESIZE};

    /** @brief Default position for Pinky. */
    const SDL_Rect pinky_default_pos{3 * TILESIZE, TILESIZE};

    /** @brief Default position for Clyde. */
    const SDL_Rect clyde_default_pos{4 * TILESIZE, TILESIZE};

    /** @brief Default position for the background sprite. */
    const SDL_Rect background_default_pos = {0, 0, 672, 864};

    /** @brief Default position for the global objects out of the view of the scene. */
    const SDL_Rect global_default_pos{-100, -100};
}

namespace default_variables {
    /** @brief Default health for the player. */
    const int player_default_health = 2;

    /** @brief Default time to reset level. */
    const int reset_level_time = 2000;

    /** @brief Default time to reset ghost to chase mode. */
    const int reset_ghost_time = 10000;

    /** @brief Default time to blink white while in Frightened mode. */
    const int time_to_blink_white = 3000;
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

    /** @brief Default sprite for the background. */
    const SDL_Rect background_sp_default = {370, 4, 166, 214};
}

#endif
