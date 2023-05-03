/**
@file GameController.h
Main game controller that initializes and manages all other controllers and objects.
*/

#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "AnimationController.h"
#include "PlayerController.h"
#include "header/view/SDLViewController.h"
#include "DotController.h"
#include "FruitController.h"
#include "header/model/Ghost.h"
#include "GhostController.h"
#include "TimeController.h"
#include "PauseController.h"
#include "header/model/GameBackground.h"
#include "LevelController.h"

class GameController {
public:
    /**
Main game controller that initializes and manages all other controllers and objects.
*/
    GameController();

    bool exit = false;

    /**
     * @brief The function called by the game loop that handles the logic of the game.
     */
    void update();

    /**
Starts the game and begins the game loop.
*/
    void startGame();

    /**
     * Resets the game to its initial state.
     */
    std::function<void(bool)> resetGame();

private:
    /**
* Checks if the user has quit the game.
* @return true if the user has quit, false otherwise.
*/
    bool hasQuit() const;

    shared_ptr<CollisionController> collisionController;
    shared_ptr<PlayerController> playerController;
    shared_ptr<GhostController> ghostController;
    shared_ptr<SDLViewController> sdlViewController;
    shared_ptr<AnimationController> animationController;
    shared_ptr<DotController> dotController;
    shared_ptr<FruitController> fruitController;
    shared_ptr<TextViewController> textViewController;
    shared_ptr<ScoreController> scoreController;
    shared_ptr<TimeController> timeController;
    shared_ptr<PauseController> pauseController;
    shared_ptr<DataController> dataController;
    shared_ptr<LevelController> levelController;

    shared_ptr<Player> player;
    shared_ptr<Blinky> blinky;
    shared_ptr<Pinky> pinky;
    shared_ptr<Inky> inky;
    shared_ptr<Clyde> clyde;
    shared_ptr<GameBackground> gameBackground;

    function<void(bool)> gameOver();
};

#endif // GAMECONTROLLER_H
