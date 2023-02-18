#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SDL.h>
#include "Animation.h"
#include <memory>

using namespace std;

class GameObject {
public:
    GameObject();
    void draw(SDL_Surface* plancheSprites, SDL_Surface* win_surf);
    SDL_Rect getRect() const;
    void destroyObject(GameObject& obj);

    // Handle animation
    void stopAnimation();
    void startAnimation();
    bool setAnimation(const std::string& animName);
    void addAnimation(const Animation& anim);

protected:
    shared_ptr<SDL_Rect> current_sp = nullptr;
    SDL_Rect rect;

    SDL_Rect default_sp;
    shared_ptr<Animation> current_anim = nullptr;

//    SDL_Rect _r_sprite;
//    SDL_Rect _l_sprite;
//    SDL_Rect _d_sprite;
//    SDL_Rect _u_sprite;

    bool isAnimated = false;

private:
    vector<Animation> animation_list;
    u_short animation_frame;
};

#endif