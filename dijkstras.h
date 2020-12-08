#pragma once
#include <vector>
#include "graph.h"
#include "edge.h"
#include "random.h"
/**
 * Contains Dijkstra's Algorithm that finds the shortest path between point A
 * and point B
 */
class Dijkstras {
    private:

    public:
        std::vector<std::string> findShortestPath(Graph data, Vertex A, Vertex landmark, Vertex C);
};