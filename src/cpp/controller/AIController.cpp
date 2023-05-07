

#include "header/controller/AIController.h"

std::vector<TilePosition> AIController::bfs(const Graph& graph, const TilePosition& start, const TilePosition& target, const std::vector<std::vector<MTYPE>>& map) {
    int startId = start.indexX * map[0].size() + start.indexY;
    int targetId = target.indexX * map[0].size() + target.indexY;

    std::queue<TilePosition> queue;
    std::unordered_map<int, TilePosition> prev;
    std::unordered_map<int, bool> visited;

    queue.push(start);
    visited[startId] = true;

    while (!queue.empty()) {
        TilePosition current = queue.front();
        queue.pop();

        int currentId = current.indexX * map[0].size() + current.indexY;

        if (currentId == targetId) {
            std::vector<TilePosition> path;
            while (currentId != startId) {
                path.push_back(current);
                current = prev[currentId];
                currentId = current.indexX * map[0].size() + current.indexY;
            }
            std::reverse(path.begin(), path.end());
            return path;
        }

        for (const TilePosition& neighbor : graph.adjList[currentId]) {
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
