#include <SDL.h>
#include <iostream>
#include "src/header/controller/GameController.h"

int main(int argc, char **argv) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "Echec de l'initialisation de la SDL " << SDL_GetError() << std::endl;
        return 1;
    }

    GameController gameController;
    gameController.startGame();

    return 0;
}
