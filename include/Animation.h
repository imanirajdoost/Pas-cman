#ifndef PAS_CMAN_ANIMATION_H
#define PAS_CMAN_ANIMATION_H


#include <string>
#include <SDL2/SDL_rect.h>
#include <vector>

using namespace std;

class Animation {
private:
    string name;
    vector<SDL_Rect> sprites_list;

public:
    Animation(const string& newName, const vector<SDL_Rect>& sps);
    string getName() const;
    void setName(const string& newName);

    vector<SDL_Rect> getSpritesList() const;
    inline void addSprite(const SDL_Rect& sp);
    void addSprites(const vector<SDL_Rect>& sps);
};


#endif //PAS_CMAN_ANIMATION_H
