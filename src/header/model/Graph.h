// Graph.h
#ifndef PACMAN_GRAPH_H
#define PACMAN_GRAPH_H

#include <vector>
#include <map>

template <typename T>
class Graph {
public:
    Graph();

    void addEdge(const T& u, const T& v);

    const std::vector<T>& getNeighbors(const T& node) const;

private:
    int getNodeIndex(const T& node);

    std::vector<T> nodes;
    std::vector<std::vector<int>> adjacencyList;
    std::map<T, int> nodeToIndex;
};

#endif //PACMAN_GRAPH_H
