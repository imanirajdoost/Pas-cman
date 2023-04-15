#include <SDL2/SDL_rect.h>
#include "header/model/eatable/Fruit.h"
#include "header/GameVars.h"

Fruit::Fruit() : StaticGameObject(default_positions::global_default_pos) {
    setSize(TILESIZE, TILESIZE);

    current_sp = std::make_shared<SDL_Rect>(sp_fruit);
}
