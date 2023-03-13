#include <SDL_rect.h>
#include "../../../header/model/eatable/DotSmall.h"
#include "../../../header/GameVars.h"


DotSmall::DotSmall() : Dot() {
    setPos(0, 0);
    setSize(SMALL_DOT_SIZE, SMALL_DOT_SIZE);

    current_sp = std::make_shared<SDL_Rect>(sp_dot_small);
}
