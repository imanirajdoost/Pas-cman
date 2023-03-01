#ifndef DOTSMALL_H
#define DOTSMALL_H

#include "Eatable.h"

extern SDL_Rect sp_dot_big;
static int smallDotHeight = 10;

class DotSmall : public Eatable {
public:
    DotSmall(int x, int y);
    static int getRectHeight();
    void getEaten(const Eatable& dot) override;
};

#endif