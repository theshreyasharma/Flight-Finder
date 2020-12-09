#include "dijkstras.h"
#include <vector>
#include <queue>
#include <unordered_map>

using std::priority_queue;



std::vector<std::string> Dijkstras::findShortestPath(Graph data, Vertex start, Vertex end) {
    std::vector<std::string> path;


    unordered_map <Vertex, double> distances;
    vector<Vertex> visited;
    priority_queue <Vertex, double> q;
    unordered_map <Vertex, Vertex> previous;

    while (q.top().first != end) {
        Vertex currentNode = q.top().first;
        for (int i = 0; i < int(data.getAdjacent(currentNode).size()); i++) {
            if (std::find(visited.begin(), visited.end(), data.getAdjacent(currentNode)) != visited.end()) {
                //update distances
                double dist = q.top().second + data.getEdgeWeight(currentNode, data.getAdjacent(currentNode)[i]);
                distances[data.getAdjacent(currentNode)[i]] = dist;
                

                q.push(make_pair(data.getAdjacent(currentNode)[i], dist));
                //Set previous
                previous[data.getAdjacent(currentNode)[i]] = currentNode;
            }
        }
        visited.push_back(currentNode);
    }

    Vertex cur = end;
    while (cur != start) {
      path.push_back(previous[cur]);
      cur = previous[cur];
    }



    return path;
}