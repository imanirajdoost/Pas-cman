#include <SDL2/SDL_rect.h>
#include "header/model/eatable/DotBig.h"
#include "header/GameVars.h"

DotBig::DotBig() : Dot() {
    setPos(0, 0);
    setSize(BIG_DOT_SIZE, BIG_DOT_SIZE);

    current_sp = std::make_shared<SDL_Rect>(sp_dot_big);
}
