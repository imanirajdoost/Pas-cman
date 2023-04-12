#include <SDL2/SDL_rect.h>
#include "header/model/eatable/DotBig.h"
#include "header/GameVars.h"

DotBig::DotBig() : Dot() {
    setPos(0, 0);
    setSize(BIG_DOT_SIZE, BIG_DOT_SIZE);

    current_sp = std::make_shared<SDL_Rect>(sp_dot_big);
    default_sp = default_sprites::dot_big_default;

    addAnimation("default", {default_sp, default_sprites::empty_black_sp}, 1, true);

    setAnimation("default");
    startAnimation();
}
