#include "dijkstras.h"
#include <vector>
#include <queue>
#include <unordered_map>
#include <utility>

using std::priority_queue;

// Allows priority queue to order by distance
struct DijkstraPair {
    Vertex vertex;
    double distance;
    DijkstraPair(Vertex v, double d) {
        vertex = v;
        distance = d;
    }
};

// Overloaded compare operator for priority queue
struct Compare {
    bool operator() (DijkstraPair const& first, DijkstraPair const& second) {
        return first.distance > second.distance;
    }
};


std::vector<std::string> Dijkstras::findShortestPath(Graph data, Vertex start, Vertex end) {
    std::vector<std::string> path;
    bool noPath = false;

    unordered_map<Vertex, double> distances;
    vector<Vertex> visited;
    priority_queue <DijkstraPair, vector<DijkstraPair>, Compare> q;
    unordered_map <Vertex, Vertex> previous;

    q.push(DijkstraPair(start, 0));
    distances[start] = 0;

    // While top is not the destination
    while (q.top().vertex != end) {
    
        if (distances[q.top().vertex] != q.top().distance) {
            q.pop();
            if (q.top().vertex == end) {
                break;
            }
        }
        
        // Get current node from priority queue
        Vertex currentNode = q.top().vertex;
        q.pop();

        // Loop through current nodes neighbors
        for (int i = 0; i < int(data.getAdjacent(currentNode).size()); i++) {
            // Check if neighbor is not in visited
            if (std::find(visited.begin(), visited.end(), data.getAdjacent(currentNode)[i]) == visited.end()) {

                double dist = distances[currentNode] + data.getEdgeWeight(currentNode, data.getAdjacent(currentNode)[i]);

                // If distances should be updated, update distances and update previous map
                if (distances.count(data.getAdjacent(currentNode)[i]) > 0) {
                    if (dist < distances[data.getAdjacent(currentNode)[i]]) {
                        q.push(DijkstraPair(data.getAdjacent(currentNode)[i], dist));
                        distances[data.getAdjacent(currentNode)[i]] = dist;
                        previous[data.getAdjacent(currentNode)[i]] = currentNode;
                    }
                } else { 
                    q.push(DijkstraPair(data.getAdjacent(currentNode)[i], dist));
                    distances[data.getAdjacent(currentNode)[i]] = dist;
                    previous[data.getAdjacent(currentNode)[i]] = currentNode;
                }
                
            }
        }
        // Add current node to visited
        visited.push_back(currentNode);

        // Check if queue is empty
        if (q.size() == 0) {
            noPath = true;
            break;
        }
    }

    // If no path is found, return empty vector
    if (noPath) return path;

    // Add queue to path vector
    Vertex cur = end;
    path.push_back(end);

    while (cur != start) {
        path.push_back(previous[cur]);
        cur = previous[cur];
    }
    
    std::reverse(path.begin(), path.end());

    return path;
}