
#include <SDL2/SDL_events.h>
#include <SDL2/SDL.h>
#include "header/controller/GameController.h"
#include "header/GameVars.h"

bool GameController::hasQuit() const {
    return exit;
}

void GameController::startGame() {
    // start the timer to get the elapsed time of each execution
//    timeController->startTimer();

    // Repeat until we have not quit the game (Simulation of frame update)
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
    timeController->tick_start();
    // Update all controllers
    pauseController->tick();
    if (!pauseController->hasPaused()) {
        playerController->tick();
        ghostController->tick();
        fruitController->tick();
    }
    animationController->tick();
    sdlViewController->tick();

    // Time controller must be in the end of all ticks to capture correctly the updated time
    // Calculate the time to wait to have the correct frame rate
    timeController->tick_end();
}

std::function<void()> GameController::resetGame() {
    return [this]() {
        player->reset_state();

        inky->reset_state();
        blinky->reset_state();
        pinky->reset_state();
        clyde->reset_state();

        // fruitController->reset_state();
        // ghostController->reset_state();
        // playerController->reset_state();
    };
}

GameController::GameController() : exit(false) {
    // Initialize game objects
    player = make_shared<Player>(default_variables::player_default_health, default_positions::player_default_pos);
    inky = make_shared<Inky>();
    blinky = make_shared<Blinky>();
    pinky = make_shared<Pinky>();
    clyde = make_shared<Clyde>();

    // Create a list of all game objects to pass for the view
    auto list_sp = make_shared<std::list<shared_ptr<GameObject>>>();
    list_sp->emplace_back(player);
    list_sp->emplace_back(inky);
    list_sp->emplace_back(blinky);
    list_sp->emplace_back(pinky);
    list_sp->emplace_back(clyde);

    // initialize controllers
    timeController = make_shared<TimeController>();
    pauseController = make_shared<PauseController>(timeController);
    collisionController = make_shared<CollisionController>();
    animationController = make_shared<AnimationController>();
    dataController = make_shared<DataController>();
    textViewController = make_shared<TextViewController>(dataController);
    scoreController = make_shared<ScoreController>(textViewController, dataController);
    dotController = make_shared<DotController>(pauseController, textViewController, scoreController);
    fruitController = make_shared<FruitController>(timeController);
    ghostController = make_shared<GhostController>(inky, pinky, blinky, clyde, collisionController);
    playerController = make_shared<PlayerController>(collisionController, player, dotController, fruitController,
                                                     scoreController, textViewController, ghostController,
                                                     pauseController, resetGame());

    sdlViewController = make_shared<SDLViewController>(list_sp, textViewController, dotController, fruitController,
                                                       pauseController);
}
