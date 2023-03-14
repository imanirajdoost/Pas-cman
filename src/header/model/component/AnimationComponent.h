#ifndef PAS_CMAN_ANIMATIONCOMPONENT_H
#define PAS_CMAN_ANIMATIONCOMPONENT_H

#include <string>
#include <SDL2/SDL_rect.h>
#include <vector>
#include "../AnimationModel.h"
#include "GameComponent.h"

using namespace std;

class AnimationComponent : public GameComponent {
private:
    vector<AnimationModel> animation_list;
    u_short animation_frame;

protected:
    std::shared_ptr<SDL_Rect> current_sp;
    SDL_Rect default_sp;

    void stopAnimation();

    void startAnimation();

    bool setAnimation(const std::string &animName);

    void addAnimation(const AnimationModel &anim);

    shared_ptr<SDL_Rect> getNextSprite();

    shared_ptr<AnimationModel> current_anim = nullptr;

    bool isAnimated = false;

public:

    AnimationComponent();

    explicit AnimationComponent(SDL_Rect defaultSp);

    AnimationComponent(const string &newName, const vector<SDL_Rect> &sps, bool _isAnimated);
};


#endif //PAS_CMAN_ANIMATIONCOMPONENT_H
