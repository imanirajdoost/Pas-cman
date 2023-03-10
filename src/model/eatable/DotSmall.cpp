

#include <SDL_rect.h>
#include "../../../include/model/eatable/DotSmall.h"
#include "../../../include/GameVars.h"

SDL_Rect sp_dot_small = {4, 81, 2, 2};

DotSmall::DotSmall() {
    setPos(0, 0);
    setSize(SMALL_DOT_SIZE, SMALL_DOT_SIZE);

    current_sp = make_shared<SDL_Rect>(sp_dot_small);
}
