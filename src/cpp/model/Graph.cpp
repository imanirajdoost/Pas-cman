
#include <iostream>
#include "header/model/Graph.h"


Graph::Graph(const std::vector<std::vector<MTYPE>>& map) {
    for (int i = 0; i < map.size(); ++i) {
        for (int j = 0; j < map[i].size(); ++j) {
            if (map[i][j] != MTYPE::WALL) {
                TilePosition current(i, j);
                int currentId = i * map[0].size() + j;

                for (int dx = -1; dx <= 1; ++dx) {
                    for (int dy = -1; dy <= 1; ++dy) {
                        if ((dx == 0) ^ (dy == 0)) {
                            int x = i + dx;
                            int y = j + dy;

                            if (x >= 0 && x < map.size() && y >= 0 && y < map[x].size() && map[x][y] != MTYPE::WALL) {
                                adjList[currentId].push_back(TilePosition(x, y));
                                std::cout << "Added edge from " << currentId << " to " << x * map[0].size() + y << "X: " << x << " Y: " << y << std::endl;
                            }
                        }
                    }
                }
            }
        }
    }
}
