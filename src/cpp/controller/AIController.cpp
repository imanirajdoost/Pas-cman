

#include "header/controller/AIController.h"
#include <algorithm>
#include <iostream>

void AIController::tick()
{

}

std::vector<TilePosition> AIController::bfs(const Graph& graph, const TilePosition& start, const TilePosition& target, const std::vector<std::vector<MTYPE>>& map) {
    int startId = start.indexX * map[0].size() + start.indexY;
    int targetId = target.indexX * map[0].size() + target.indexY;

    std::cout << "Start id : " << startId << std::endl;
    std::cout << "Target id : " << targetId << std::endl;

    std::queue<TilePosition> queue;
    std::unordered_map<int, TilePosition> prev;
    std::unordered_map<int, bool> visited;

    queue.push(start);
    visited[startId] = true;

    while (!queue.empty()) {
        TilePosition current = queue.front();
        queue.pop();

        int currentId = current.indexX * map[0].size() + current.indexY;
        std::cout << "Current id : " << currentId << std::endl;

        if (currentId == targetId) {
            std::vector<TilePosition> path;
            while (currentId != startId) {
                path.push_back(current);
                current = prev.at(currentId);
                currentId = current.indexX * map[0].size() + current.indexY;
            }
            std::reverse(path.begin(), path.end());
            return path;
        }

        for (const TilePosition& neighbor : graph.adjList.at(currentId)) {
            int neighborId = neighbor.indexX * map[0].size() + neighbor.indexY;

            if (!visited[neighborId]) {
                queue.push(neighbor);
                visited[neighborId] = true;
                prev[neighborId] = current;
            }
        }
    }

    return {};  // No path found.
}

AIController::AIController() {
    graph = make_shared<Graph>(Map::map);

    TilePosition startPos(1, 1);
    TilePosition targetPos(20, 10);
    auto path = bfs(*graph, startPos, targetPos, Map::map);

    std::cout << "Path size : " << path.size() << std::endl;

    for (const TilePosition& tile : path) {
        std::cout << tile.indexX << " " << tile.indexY << std::endl;
    }
}
