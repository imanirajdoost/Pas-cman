#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SDL.h>
#include "model/component/AnimationComponent.h"
#include "model/component/SpriteComponent.h"
#include "model/component/ColliderComponent.h"
#include <memory>

using namespace std;

class GameObject : public SpriteComponent, public ColliderComponent {
public:
    explicit GameObject();
//    void draw(SDL_Surface* plancheSprites, SDL_Surface* win_surf);
//    void destroyObject(GameObject& obj);
};

#endif