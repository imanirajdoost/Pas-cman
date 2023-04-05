//
// Created by iman on 10/03/23.
//

#ifndef PAS_CMAN_PLAYERCONTROLLER_H
#define PAS_CMAN_PLAYERCONTROLLER_H

#include "header/model/Player.h"
#include "DotController.h"
#include "FruitController.h"
#include "ScoreController.h"
#include "header/view/SDLViewController.h"
#include "GhostController.h"
#include "PauseController.h"

class PlayerController {
public:
    PlayerController(shared_ptr<CollisionController> colController, shared_ptr<Player> p,
                     shared_ptr<DotController> dController, shared_ptr<FruitController> fController, shared_ptr<ScoreController> sController,
                     shared_ptr<TextViewController> tController, shared_ptr<GhostController> gController, shared_ptr<PauseController> pController);

    void setMoveIntent(MoveDirection direction);

    void tick();

private:
    shared_ptr<CollisionController> collisionController;
    shared_ptr<DotController> dotController;
    shared_ptr<FruitController> fruitController;
    shared_ptr<ScoreController> scoreController;
    shared_ptr<TextViewController> textViewController;
    shared_ptr<GhostController> ghostController;
    shared_ptr<PauseController> pauseController;
    shared_ptr<Player> player;
};


#endif //PAS_CMAN_PLAYERCONTROLLER_H
