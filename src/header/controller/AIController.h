
#ifndef PAS_CMAN_AICONTROLLER_H
#define PAS_CMAN_AICONTROLLER_H


class AIController {

public:
    std::vector<TilePosition> bfs(const Graph& graph, const TilePosition& start, const TilePosition& target, const std::vector<std::vector<MTYPE>>& map);

};


#endif //PAS_CMAN_AICONTROLLER_H
