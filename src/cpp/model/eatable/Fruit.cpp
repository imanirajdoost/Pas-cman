#include <SDL2/SDL_rect.h>
#include <random>
#include "header/model/eatable/Fruit.h"
#include "header/GameVars.h"

Fruit::Fruit() : StaticGameObject(default_positions::global_default_pos) {
    setSize(TILESIZE, TILESIZE);

    fruit_sprites = {make_shared<SDL_Rect>(sp_fruit1), make_shared<SDL_Rect>(sp_fruit2),
                     make_shared<SDL_Rect>(sp_fruit3), make_shared<SDL_Rect>(sp_fruit4)};

    current_sp = fruit_sprites[0];
}

void Fruit::pick_sprite_randomly() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, fruit_sprites.size() - 1);

    int random_index = dis(gen);
    current_sp = fruit_sprites[random_index];
}

std::vector<shared_ptr<SDL_Rect>> Fruit::get_sprites() {
    return fruit_sprites;
}
