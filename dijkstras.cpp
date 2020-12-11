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
    return first.distance > second.distance;
    }
};


std::vector<std::string> Dijkstras::findShortestPath(Graph data, Vertex start, Vertex end) {
    std::vector<std::string> path;
    bool noPath = false;

    unordered_map<Vertex, double> distances;
    vector<Vertex> visited;
    
    // priority_queue <std::pair < Vertex, double >, vector<double>, std::greater<int> > q;
    priority_queue <DijkstraPair, vector<DijkstraPair>, Compare> q;
    unordered_map <Vertex, Vertex> previous;

    q.push(DijkstraPair(start, 0));
    distances[start] = 0;

    while (q.top().vertex != end) {
        std::cout << "CURRENT BEFORE CHECKING: " << q.top().vertex << std::endl;
        if (distances[q.top().vertex] != q.top().distance) {
            q.pop();
            if (q.top().vertex == end) {
                break;
            }
        }
        
        Vertex currentNode = q.top().vertex;

        std::cout << "CURRENT After CHECKING: " << currentNode << std::endl;

        q.pop();
        for (int i = 0; i < int(data.getAdjacent(currentNode).size()); i++) {
            
            if (std::find(visited.begin(), visited.end(), data.getAdjacent(currentNode)[i]) == visited.end()) {
                //update distances

                double dist = distances[currentNode] + data.getEdgeWeight(currentNode, data.getAdjacent(currentNode)[i]);
                if (distances.count(data.getAdjacent(currentNode)[i]) > 0) {
                    if (dist < distances[data.getAdjacent(currentNode)[i]]) {
                        q.push(DijkstraPair(data.getAdjacent(currentNode)[i], dist));
                        distances[data.getAdjacent(currentNode)[i]] = dist;
                        previous[data.getAdjacent(currentNode)[i]] = currentNode;
                    }
                } else { 
                    
                    std::cout << "CURRENT PUSH: " << currentNode << dist << std::endl;

                    q.push(DijkstraPair(data.getAdjacent(currentNode)[i], dist));
                    distances[data.getAdjacent(currentNode)[i]] = dist;
                    previous[data.getAdjacent(currentNode)[i]] = currentNode;
                }
                //Set previous
                
            }
        }
        visited.push_back(currentNode);
        if (q.size() == 0) {
            std::cout << "NO PATH" << std::endl;
            noPath = true;
            break;

        }
    }

    //std::cout << distances[end] << std::endl;

    Vertex cur = end;
    path.push_back(end);
    if (!noPath) {
        while (cur != start) {
        path.push_back(previous[cur]);
        cur = previous[cur];
        }
    } else {
        std::vector<std::string> empty;
        return empty;
    }

    // for (int i = 0; i < int(visited.size()); i++) {
    //     std::cout << visited[i] << std::endl;
    // }

    
    std::reverse(path.begin(), path.end());

    return path;
}