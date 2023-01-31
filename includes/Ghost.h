#ifndef GHOST_H
#define GHOST_H

class Ghost {
    private:
    int _x;
    int _y;

    public:
    Ghost(int x, int y);
    int getX();
    int getY();
};

#endif