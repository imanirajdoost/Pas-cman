//
// Created by iman on 14/03/23.
//

#include <string>
#include "header/model/AnimationModel.h"

std::string AnimationModel::getName() const {
    return name;
}

void AnimationModel::setName(const std::string &newName) {
    name = newName;
}

std::vector<SDL_Rect> AnimationModel::getSpritesList() const {
    return sprites_list;
}


void AnimationModel::addSprites(const std::vector<SDL_Rect> &sps) {
    for (const auto &sp: sps) {
        addSprite(sp);
    }
}

AnimationModel::AnimationModel(bool shouldLoop) {
    should_loop = shouldLoop;
}

void AnimationModel::addSprite(const SDL_Rect &sp) {
    sprites_list.push_back(sp);
}

bool AnimationModel::getLoop() const {
    return should_loop;
}
