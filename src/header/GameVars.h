#ifndef GAMEVARS_H
#define GAMEVARS_H

namespace constants {

    /** @brief Tile size in pixels. */
#define TILESIZE 32

    /** @brief Debug mode flag. */
#define DEBUG_MODE 0

    /** @brief Animation frame rate in frames per second. */
#define ANIMATION_FRAME_RATE 2

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
}

#endif
