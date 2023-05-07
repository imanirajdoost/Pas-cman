
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

    vector<TilePosition> getPath(const TilePosition &from, const TilePosition &to);


private:
    vector<TilePosition> bfs(const Graph& graph, const TilePosition& start, const TilePosition& target, const vector<vector<MTYPE>>& map);

    shared_ptr<Graph> graph;

};


#endif //PAS_CMAN_AICONTROLLER_H
