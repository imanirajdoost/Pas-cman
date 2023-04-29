//
// Created by iman on 29/04/23.
//

#include "header/model/TileModel.h"
#include "header/GameVars.h"

TileModel::TileModel(int x, int y): x(x), y(y) {

}

int TileModel::getTileXPosition() const {
    return x * TILESIZE;
}

int TileModel::getTileYPosition() const {
    return y * TILESIZE;
}
