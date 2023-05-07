
#ifndef PAS_CMAN_AICONTROLLER_H
#define PAS_CMAN_AICONTROLLER_H

#include <vector>
#include <memory>
#include "header/model/TilePosition.h"
#include "header/model/Graph.h"
#include "header/model/Map.h"

using namespace std;

class AIController {

public:
    AIController();
    vector<TilePosition> bfs(const Graph& graph, const TilePosition& start, const TilePosition& target, const vector<vector<MTYPE>>& map);

private:
    shared_ptr<Graph> graph;

    void tick();
};


#endif //PAS_CMAN_AICONTROLLER_H
