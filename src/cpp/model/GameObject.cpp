
#include "header/model/GameObject.h"

GameObject::GameObject(SDL_Rect initPos) : AnimationComponent(), TransformComponent(initPos), _init_pos(initPos) {

}

GameObject::GameObject(SDL_Rect defaultSp, SDL_Rect initPos) : AnimationComponent(defaultSp),
                                                               TransformComponent(initPos), _init_pos(initPos) {

}

GameObject::GameObject(const string &newName, const vector<SDL_Rect> &sps, bool _isAnimated, SDL_Rect initPos)
        : AnimationComponent(
        newName, sps, _isAnimated), TransformComponent(initPos), _init_pos(initPos) {

}

void GameObject::reset_state() {
    setPos(_init_pos.x, _init_pos.y);
}
