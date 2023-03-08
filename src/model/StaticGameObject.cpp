#include "model/StaticGameObject.h"

void StaticGameObject::setPos(int x, int y) {
    rect.x = x;
    rect.y = y;
}

StaticGameObject::StaticGameObject(SDL_Rect defaultSprite) : GameObject(defaultSprite) {

}
