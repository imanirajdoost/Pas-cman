
#include <SDL2/SDL_events.h>
#include <SDL2/SDL.h>
#include "header/controller/GameController.h"

bool GameController::hasQuit() {
    return exit;
}

void GameController::startGame() {
    while (!hasQuit()) {
        SDL_Event event;
        while (!hasQuit() && SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    exit = true;
                    break;
                default:
                    break;
            }
        }

        // Gestion du clavier
        int nbk;
        const Uint8 *keys = SDL_GetKeyboardState(&nbk);
        MoveDirection nextPlayerMove;
        if (keys[SDL_SCANCODE_ESCAPE]) {
            exit = true;
        }
        if (keys[SDL_SCANCODE_LEFT]) {
            nextPlayerMove = MoveDirection::LEFT;
            playerController->setMoveIntent(nextPlayerMove);
        } else if (keys[SDL_SCANCODE_RIGHT]) {
            nextPlayerMove = MoveDirection::RIGHT;
            playerController->setMoveIntent(nextPlayerMove);
        } else if (keys[SDL_SCANCODE_UP]) {
            nextPlayerMove = MoveDirection::UP;
            playerController->setMoveIntent(nextPlayerMove);
        } else if (keys[SDL_SCANCODE_DOWN]) {
            nextPlayerMove = MoveDirection::DOWN;
            playerController->setMoveIntent(nextPlayerMove);
        }

        update();
    }
    SDL_Quit();
}

void GameController::update() {
    animationController->tick();
    sdlViewController->tick();
    playerController->tick();
}

GameController::GameController() {
    collisionController = make_shared<CollisionController>();
    animationController = make_shared<AnimationController>();
    sdlViewController = make_shared<SDLViewController>();
    dotController = make_shared<DotController>();

    player = make_shared<Player>(2);

    playerController = make_shared<PlayerController>(collisionController, player, dotController);
}
