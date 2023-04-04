//
// Created by iman on 04/04/23.
//

#ifndef PAS_CMAN_GHOSTCONTROLLER_H
#define PAS_CMAN_GHOSTCONTROLLER_H


#include <memory>
#include "CollisionController.h"
#include "../model/MovableGameObject.h"
#include "../model/Ghost.h"

class GhostController {
public:
    GhostController(std::shared_ptr<Ghost> _ghost,std::shared_ptr<CollisionController> colController);
    void tick();

private:
    std::shared_ptr<CollisionController> collisionController;
    std::shared_ptr<Ghost> ghost;
};


#endif //PAS_CMAN_GHOSTCONTROLLER_H
