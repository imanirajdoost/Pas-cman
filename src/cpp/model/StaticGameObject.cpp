#include "header/model/StaticGameObject.h"

StaticGameObject::StaticGameObject(SDL_Rect initPos) : GameObject(initPos) {

}

StaticGameObject::StaticGameObject(SDL_Rect defaultSp, SDL_Rect initPos) : GameObject(defaultSp, initPos) {

}
