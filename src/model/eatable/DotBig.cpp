#include <SDL2/SDL_rect.h>
#include "../../../include/model/eatable/DotBig.h"
#include "../../../include/GameVars.h"

SDL_Rect sp_dot_big = { 9,79, 7,7 };

DotBig::DotBig() {
    setPos(0, 0);
    setSize(SMALL_DOT_SIZE, SMALL_DOT_SIZE);

    current_sp = make_shared<SDL_Rect>(sp_dot_big);
}
