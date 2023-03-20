#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "AnimationController.h"
#include "PlayerController.h"
#include "header/view/SDLViewController.h"
#include "DotController.h"

class GameController {
public:
    GameController();

    bool exit = false;

    void update();

    void startGame();

private:
    bool hasQuit();

    shared_ptr<CollisionController> collisionController;
    shared_ptr<PlayerController> playerController;
    shared_ptr<SDLViewController> sdlViewController;
    shared_ptr<AnimationController> animationController;
    shared_ptr<DotController> dotController;

    shared_ptr<Player> player;
};

#endif // GAMECONTROLLER_H
