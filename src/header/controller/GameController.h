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

class GameController {
public:
    GameController();

    bool exit = false;

    void update();

    void startGame();

private:
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

    shared_ptr<Player> player;
    shared_ptr<Blinky> blinky;
    shared_ptr<Pinky> pinky;
    shared_ptr<Inky> inky;
    shared_ptr<Clyde> clyde;
};

#endif // GAMECONTROLLER_H
