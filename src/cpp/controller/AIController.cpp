

#include "header/controller/AIController.h"
#include "header/model/Map.h"

//Graph<TileModel> AIController::generate_path_graph() {
//
//    auto &map = Map::map;
//    // create a graph of all the available paths (MTYPE = EMPTY) from the map
//    // each node is a tuple of (x, y) coordinates
//    // the graph is undirected, so each edge is represented twice
//    // the graph is unweighted, so each edge has a weight of 1
//
//    Graph<TileModel> graph;
//
//    int numRows = map.size();
//    int numCols = map[0].size();
//
//    for (int i = 0; i < numRows; ++i) {
//        for (int j = 0; j < numCols; ++j) {
//            TileModel current = TileModel(i, j);
//
//            if (map[i][j] != MTYPE::EMPTY) {
//                continue;
//            }
//
//            if (i > 0) {
//                TileModel up = TileModel(i - 1, j);
//                if (map[i - 1][j] == MTYPE::EMPTY) {
//                    graph.addEdge(current, up);
//                }
//            }
//            if (i < numRows - 1) {
//                TileModel down = TileModel(i + 1, j);
//                if (map[i + 1][j] == MTYPE::EMPTY) {
//                    graph.addEdge(current, down);
//                }
//            }
//            if (j > 0) {
//                TileModel left = TileModel(i, j - 1);
//                if (map[i][j - 1] == MTYPE::EMPTY) {
//                    graph.addEdge(current, left);
//                }
//            }
//            if (j < numCols - 1) {
//                TileModel right = TileModel(i, j + 1);
//                if (map[i][j + 1] == MTYPE::EMPTY) {
//                    graph.addEdge(current, right);
//                }
//            }
//        }
//    }
//    return graph;
//}


//AIController::AIController() {
//    pathGraph = generate_path_graph();
//}
AIController::AIController() {

}
