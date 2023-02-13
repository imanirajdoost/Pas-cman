#ifndef DOTSMALL_H
#define DOTSMALL_H

#include "Dot.h"

extern SDL_Rect sp_dot_big;
static int smallDotHeight = 10;

class DotSmall : public Dot {
public:
    DotSmall(int x, int y);
    static int getRectHeight();
    void getEaten(const Dot& dot) override;
};

#endif