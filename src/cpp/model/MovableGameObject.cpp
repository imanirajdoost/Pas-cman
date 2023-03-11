#include "../../header/model/MovableGameObject.h"

void MovableGameObject::draw(SDLViewController viewController) {
    auto v = getDrawRect();
    viewController.draw_sprite(getNextSprite(), );
}

void MovableGameObject::draw(const SDLViewController &viewController) {
    GameObject::draw(viewController);
}
