#ifndef GAMEVARS_H
#define GAMEVARS_H

namespace constants {

#define TILESIZE 32
#define SMALL_DOT_SIZE 10
#define BIG_DOT_SIZE 20
#define SMALL_DOT_SCORE 10
#define BIG_DOT_SCORE 50
#define FRUIT_SCORE 100
#define ANIMATION_FRAME_RATE 2
#define DEBUG_MODE 1

}

namespace default_sprites {
const SDL_Rect player_sp_default{21, 90, 13, 14};
    const SDL_Rect blinky_sp_default = {4, 124, 14, 14};
    const SDL_Rect pinky_sp_default = {4, 142, 14, 14};
    const SDL_Rect inky_sp_default = {4, 160, 14, 14};
    const SDL_Rect clyde_sp_default = {4, 178, 14, 14};
}
#endif