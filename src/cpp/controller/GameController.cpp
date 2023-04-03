
#include <SDL2/SDL_events.h>
#include <SDL2/SDL.h>
#include "header/controller/GameController.h"

bool GameController::hasQuit() const {
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
    dotController = make_shared<DotController>();
    fruitController = make_shared<FruitController>();
    textViewController = make_shared<TextViewController>();


    player = make_shared<Player>(2);
    inky = make_shared<Inky>();
    blinky = make_shared<Blinky>();
    pinky = make_shared<Pinky>();
    clyde = make_shared<Clyde>();

    // TODO
    auto list_sp = make_shared<std::list<shared_ptr<GameObject>>>();
    list_sp->emplace_back(player);

    playerController = make_shared<PlayerController>(collisionController, player, dotController, fruitController);

    sdlViewController = make_shared<SDLViewController>(list_sp, textViewController, dotController, fruitController);
}
