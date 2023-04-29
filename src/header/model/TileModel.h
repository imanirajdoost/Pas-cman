
#ifndef PACMAN_TILEMODEL_H
#define PACMAN_TILEMODEL_H


#include <cstdio>
#include <memory>

class TileModel {
public:
    TileModel(int x, int y);

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    int getTileXPosition() const;

    int getTileYPosition() const;

    bool operator==(const TileModel& other) const {
        return x == other.x && y == other.y;
    }

    bool operator!=(const TileModel& other) const {
        return !(*this == other);
    }

    size_t operator()(const TileModel& tile) const {
        size_t row_hash = std::hash<int>()(tile.getX());
        size_t col_hash = std::hash<int>()(tile.getY());

        return row_hash ^ (col_hash << 1);
    }


private:
    int x;
    int y;
};



#endif //PACMAN_TILEMODEL_H
