#ifndef GAMEVARS_H
#define GAMEVARS_H

namespace constants {
#define TILESIZE 32
#define DEBUG_MODE 1

#define ANIMATION_FRAME_RATE 2

#define SMALL_DOT_SIZE 10
#define SMALL_DOT_SCORE 10

#define BIG_DOT_SIZE 20
#define BIG_DOT_SCORE 50

#define FRUIT_SCORE 100
#define MIN_TIME_TO_SPAWN_FRUIT 10000
#define FRUIT_SPAWN_TIME 15000
#define FRUIT_AVAILABE_TIME 5000
}

namespace default_sprites {
    const SDL_Rect player_sp_default{4, 90, 14, 14};;
    const SDL_Rect blinky_sp_default = {4, 124, 14, 14};
    const SDL_Rect pinky_sp_default = {4, 142, 14, 14};
    const SDL_Rect inky_sp_default = {4, 160, 14, 14};
    const SDL_Rect clyde_sp_default = {4, 178, 14, 14};
}
#endif