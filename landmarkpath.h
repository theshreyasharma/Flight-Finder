#pragma once
#include <vector>
#include "graph.h"
#include "edge.h"
#include "random.h"
/**
 * Contains the Landmark Path Algorithm that finds the shortest path between point A
 * and point C given a landmark that must be visited (point landmark)
 * 
 * A ------> landmark ---------> C
 */
class LandmarkPath {
    private:

    public:
        std::vector<std::string> findShortestPath(Graph data, Vertex A, Vertex landmark, Vertex C);
};