#include "landmarkpath.h"

std::vector<std::string> LandmarkPath::findShortestPath(Graph data, Vertex A, Vertex landmark, Vertex C) {
    // Perform Djikstra's Algorithm from vertex A to landmark
    Dijkstras shortest_path_al;
    path = shortest_path_al.findShortestPath(data, A, landmark);
    
    // Perform Djikstra's Algorithm from landmark to vertex C
    Dijkstras shortest_path_lc;
    std::vector<std::string> landmark_to_c = shortest_path_lc.findShortestPath(data, landmark, C);
    path.insert(path.end(), landmark_to_c.begin(), landmark_to_c.end());
    
    return path;
}