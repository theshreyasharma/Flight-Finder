#include "dijkstras.h"
#include <vector>
#include <queue>
#include <unordered_map>
#include <utility>
using std::priority_queue;

struct DijkstraPair {
    Vertex vertex;
    double distance;
    DijkstraPair(Vertex v, double d) {
        vertex = v;
        distance = d;
    }
};

struct Compare {
    bool operator() (DijkstraPair const& first, DijkstraPair const& second) {
    return first.distance < second.distance;
    }
};


std::vector<std::string> Dijkstras::findShortestPath(Graph data, Vertex start, Vertex end) {
    std::vector<std::string> path;

    unordered_map<Vertex, double> distances;
    vector<Vertex> visited;
    
    // priority_queue <std::pair < Vertex, double >, vector<double>, std::greater<int> > q;
    priority_queue <DijkstraPair, vector<DijkstraPair>, Compare> q;
    unordered_map <Vertex, Vertex> previous;

    q.push(DijkstraPair(start, 0));
    distances[start] = 0;

    while (q.top().vertex != end) {
        Vertex currentNode = q.top().vertex;
        q.pop();
        for (int i = 0; i < int(data.getAdjacent(currentNode).size()); i++) {
            
            if (std::find(visited.begin(), visited.end(), data.getAdjacent(currentNode)[i]) == visited.end()) {
                //update distances

                double dist = distances[currentNode] + data.getEdgeWeight(currentNode, data.getAdjacent(currentNode)[i]);
                if (distances.count(data.getAdjacent(currentNode)[i]) > 0) {
                    if (dist < distances[data.getAdjacent(currentNode)[i]]) {
                        distances[data.getAdjacent(currentNode)[i]] = dist;
                        previous[data.getAdjacent(currentNode)[i]] = currentNode;
                    }
                } else { 
                    q.push(DijkstraPair(data.getAdjacent(currentNode)[i], dist));
                    distances[data.getAdjacent(currentNode)[i]] = dist;
                    previous[data.getAdjacent(currentNode)[i]] = currentNode;
                }
                //Set previous
                
            }
        }
        visited.push_back(currentNode);
    }

    //std::cout << distances[end] << std::endl;

    Vertex cur = end;
    path.push_back(end);
    while (cur != start) {
      path.push_back(previous[cur]);
      cur = previous[cur];
    }

    // for (int i = 0; i < int(visited.size()); i++) {
    //     std::cout << visited[i] << std::endl;
    // }



    return path;
}