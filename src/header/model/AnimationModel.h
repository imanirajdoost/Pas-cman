//
// Created by iman on 14/03/23.
//

#ifndef PAS_CMAN_ANIMATIONMODEL_H
#define PAS_CMAN_ANIMATIONMODEL_H


#include <SDL2/SDL_rect.h>
#include <string>
#include <vector>

using namespace std;

class AnimationModel {
private:
    string name;

public:
    vector<SDL_Rect> getSpritesList() const;

    inline void addSprite(const SDL_Rect &sp);

    void addSprites(const vector<SDL_Rect> &sps);

    string getName() const;

    void setName(const string &newName);

    vector<SDL_Rect> sprites_list;
};


#endif //PAS_CMAN_ANIMATIONMODEL_H
