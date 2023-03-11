#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "AnimationController.h"
#include "SDLViewController.h"
#include "PlayerController.h"

class GameController : public AnimationController, public SDLViewController, public PlayerController {
public:
    bool exit = false;

    void tick() override;

    void startGame();

private:
    bool hasQuit();

    PlayerController playerController;
};

#endif // GAMECONTROLLER_H
