#ifndef PAS_CMAN_GAMEBACKGROUND_H
#define PAS_CMAN_GAMEBACKGROUND_H


#include "StaticGameObject.h"

class GameBackground : public StaticGameObject {
public:
    /**
     * @brief Constructor for GameBackground.
     * @param initPos The initial position of the GameObject.
     */
    GameBackground();
private:
    const SDL_Rect background_sp2 = {541, 4, 166, 214};
};


#endif //PAS_CMAN_GAMEBACKGROUND_H
