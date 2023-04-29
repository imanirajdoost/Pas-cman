//
// Created by iman on 29/04/23.
//

#include "header/model/Graph.h"


template <typename T>
Graph<T>::Graph() = default;

template <typename T>
void Graph<T>::addEdge(const T& u, const T& v) {
    int uIndex = getNodeIndex(u);
    int vIndex = getNodeIndex(v);

    adjacencyList[uIndex].push_back(vIndex);
    adjacencyList[vIndex].push_back(uIndex);
}

template <typename T>
const std::vector<T>& Graph<T>::getNeighbors(const T& node) const {
    int nodeIndex = nodeToIndex.at(node);
    std::vector<T> neighbors;
    for (int neighborIndex : adjacencyList[nodeIndex]) {
        neighbors.push_back(nodes[neighborIndex]);
    }
    return neighbors;
}

template <typename T>
int Graph<T>::getNodeIndex(const T& node) {
    auto it = nodeToIndex.find(node);
    if (it != nodeToIndex.end()) {
        return it->second;
    }
    int newIndex = nodes.size();
    nodes.push_back(node);
    adjacencyList.push_back(std::vector<int>());
    nodeToIndex[node] = newIndex;
    return newIndex;
}
