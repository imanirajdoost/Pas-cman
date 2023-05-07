
#include <SDL2/SDL_events.h>
#include <SDL2/SDL.h>
#include "header/controller/GameController.h"
#include "header/GameVars.h"
#include "header/controller/AIController.h"

bool GameController::hasQuit() const {
    return exit;
}

void GameController::startGame() {

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

std::function<void(bool)> GameController::resetGame() {
    return [this](bool respawnDots) {
        animationController->stopAllAnimations();
        animationController->resetAllAnimations();
        ghostController->reset_state();

        player->reset_state();

        inky->reset_state();
        blinky->reset_state();
        pinky->reset_state();
        clyde->reset_state();

        scoreController->updateHighscore();

        if (respawnDots) {
            dotController->reset_state();
            gameBackground->stopAnimation();
            gameBackground->setDefaultSprite();
            textViewController->removeFromUI("you_won");
            textViewController->setLevelOnUI(levelController->getCurrentLevelIndex() + 1);
        }
    };
}

std::function<void(bool)> GameController::gameOver() {
    return [this](bool won) {
        pauseController->pause();
        scoreController->updateHighscore();

        animationController->stopAnimation(inky->getAnimatorComponent());
        animationController->stopAnimation(blinky->getAnimatorComponent());
        animationController->stopAnimation(pinky->getAnimatorComponent());
        animationController->stopAnimation(clyde->getAnimatorComponent());

        if (won) {
            cout << "You won !" << endl;
            animationController->stopAnimation(player->getAnimatorComponent());
            animationController->startAnimation(gameBackground->getAnimatorComponent());
            textViewController->writeOnUI("you_won", "congratulations!", 6 * TILESIZE, 10 * TILESIZE);
            levelController->goToNextLevel();
            pauseController->pauseFor(3000, resetGame(), true);
        } else {
            textViewController->writeOnUI("game_over", "gameover", 8 * TILESIZE, 10 * TILESIZE);

            // TODO: do a full reset to restart the game
//            pauseController->pauseFor(default_variables::reset_level_time + 1000, resetGame(), true);
        }
    };
}


GameController::GameController() : exit(false) {
    // Initialize game objects
    player = make_shared<Player>(default_variables::player_default_health, default_positions::player_default_pos);
    inky = make_shared<Inky>();
    blinky = make_shared<Blinky>();
    pinky = make_shared<Pinky>();
    clyde = make_shared<Clyde>();
    gameBackground = make_shared<GameBackground>();

    auto list_anim = make_shared<std::vector<shared_ptr<AnimationComponent>>>();
    list_anim->emplace_back(player->getAnimatorComponent());
    list_anim->emplace_back(inky->getAnimatorComponent());
    list_anim->emplace_back(blinky->getAnimatorComponent());
    list_anim->emplace_back(pinky->getAnimatorComponent());
    list_anim->emplace_back(clyde->getAnimatorComponent());
    list_anim->emplace_back(gameBackground->getAnimatorComponent());

    // Create a list of all game objects to pass for the view
    auto list_sp = make_shared<std::list<shared_ptr<GameObject>>>();
    list_sp->emplace_back(gameBackground);
    list_sp->emplace_back(player);
    list_sp->emplace_back(inky);
    list_sp->emplace_back(blinky);
    list_sp->emplace_back(pinky);
    list_sp->emplace_back(clyde);

    // initialize controllers
    levelController = make_shared<LevelController>();
    timeController = make_shared<TimeController>(levelController);
    pauseController = make_shared<PauseController>(timeController);
    collisionController = make_shared<CollisionController>();
    aiController = make_shared<AIController>();
    animationController = make_shared<AnimationController>(list_anim);
    dataController = make_shared<DataController>();
    textViewController = make_shared<TextViewController>(dataController);
    scoreController = make_shared<ScoreController>(textViewController, dataController);
    ghostController = make_shared<GhostController>(inky, pinky, blinky, clyde, timeController, collisionController, aiController, player);
    dotController = make_shared<DotController>(gameOver(), ghostController);
    fruitController = make_shared<FruitController>(timeController, textViewController);
    playerController = make_shared<PlayerController>(collisionController, player, dotController, fruitController,
                                                     scoreController, textViewController, ghostController,
                                                     pauseController, resetGame(), gameOver());

    sdlViewController = make_shared<SDLViewController>(list_sp, textViewController, dotController, fruitController);

    AIController aiController;
}
