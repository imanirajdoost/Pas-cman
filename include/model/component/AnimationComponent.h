#ifndef PAS_CMAN_ANIMATIONCOMPONENT_H
#define PAS_CMAN_ANIMATIONCOMPONENT_H

#include <string>

using namespace std;

class AnimationComponent : public SpriteComponent {
private:
    string name;
    vector<SDL_Rect> sprites_list;
    vector<AnimationComponent> animation_list;
    u_short animation_frame;

protected:

    string getName() const;

    void setName(const string &newName);

    vector<SDL_Rect> getSpritesList() const;

    inline void addSprite(const SDL_Rect &sp);

    void addSprites(const vector<SDL_Rect> &sps);

    void stopAnimation();

    void startAnimation();

    bool setAnimation(const std::string &animName);

    void addAnimation(const AnimationComponent &anim);

    shared_ptr<AnimationComponent> current_anim = nullptr;
    bool isAnimated = false;

public:
    AnimationComponent(const string &newName, const vector<SDL_Rect> &sps);

    AnimationComponent();
};


#endif //PAS_CMAN_ANIMATIONCOMPONENT_H
