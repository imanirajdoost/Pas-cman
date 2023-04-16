#include <SDL2/SDL_rect.h>
#include "header/model/eatable/Fruit.h"
#include "header/GameVars.h"

Fruit::Fruit() : StaticGameObject(default_positions::global_default_pos) {
    setSize(TILESIZE, TILESIZE);

    fruit_sprites = {std::make_shared<SDL_Rect>(sp_fruit1), std::make_shared<SDL_Rect>(sp_fruit2),
                     std::make_shared<SDL_Rect>(sp_fruit3), std::make_shared<SDL_Rect>(sp_fruit4)};

    current_sp = fruit_sprites[0];
}

void Fruit::pick_sprite_randomly() {
    int random_index = rand() % fruit_sprites.size();
    current_sp = fruit_sprites[random_index];
}

std::vector<shared_ptr<SDL_Rect>> Fruit::get_sprites() {
    return fruit_sprites;
}
