//
// Created by iman on 18/02/23.
//

#include "../include/Animation.h"

std::string Animation::getName() const {
    return name;
}

void Animation::setName(const std::string& newName) {
    name = newName;
}

std::vector<SDL_Rect> Animation::getSpritesList() const {
    return sprites_list;
}

inline void Animation::addSprite(const SDL_Rect& sp) {
    sprites_list.push_back(sp);
}

void Animation::addSprites(const std::vector<SDL_Rect>& sps) {
    for (const auto& sp: sps) {
        addSprite(sp);
    }
}

Animation::Animation(const string &newName, const vector<SDL_Rect> &sps) {
    setName(newName);
    addSprites(sps);
}
