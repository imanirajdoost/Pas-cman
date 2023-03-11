#ifndef DOTSMALL_H
#define DOTSMALL_H

#include "Dot.h"

class DotSmall : public Dot {
public:
    DotSmall();
//    void getEaten(const EatableComponent& dot) override;
private:
    const SDL_Rect sp_dot_small = {4, 81, 2, 2};
};

#endif