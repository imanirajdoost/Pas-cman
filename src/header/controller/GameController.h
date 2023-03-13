#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "AnimationController.h"
#include "../view/SDLViewController.h"
#include "PlayerController.h"

class GameController {
public:
    GameController();

    bool exit = false;

    void update();

    void startGame();

private:
    bool hasQuit();

    PlayerController playerController;
    SDLViewController sdlViewController;
    AnimationController animationController;

    Player player = Player(2);
};

#endif // GAMECONTROLLER_H
