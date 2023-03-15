
#include "header/model/GameObject.h"

GameObject::GameObject() : AnimationComponent(), TransformComponent() {

}

GameObject::GameObject(SDL_Rect defaultSp) : AnimationComponent(defaultSp), TransformComponent() {

}

GameObject::GameObject(const string &newName, const vector<SDL_Rect> &sps, bool _isAnimated) : AnimationComponent(
        newName, sps, _isAnimated), TransformComponent() {

}
