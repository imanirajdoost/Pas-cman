#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "AnimationController.h"
#include "SDLController.h"
#include "PlayerController.h"

class GameController : public AnimationController, public SDLController, public PlayerController {
public:
    bool exit = false;

    void tick() override;

    void startGame();

private:
    bool hasQuit();

    PlayerController playerController;
};

#endif // GAMECONTROLLER_H
