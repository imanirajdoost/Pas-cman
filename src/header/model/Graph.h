//
// Created by iman on 07/05/23.
//

#ifndef PAS_CMAN_GRAPH_H
#define PAS_CMAN_GRAPH_H


#include <vector>
#include <queue>
#include <unordered_map>
#include "Map.h"
#include "TilePosition.h"

class Graph {
public:
    std::unordered_map<int, std::vector<TilePosition>> adjList;

    Graph(const std::vector<std::vector<MTYPE>>& map);
};


#endif //PAS_CMAN_GRAPH_H
