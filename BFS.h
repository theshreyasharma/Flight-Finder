#pragma once

#include "graph.h"
#include <queue>
#include <string>
#include <vector>
#include <unordered_map>
#include <tuple>

using std::queue;
using std::vector;
using std::string;
using std::pair;

class BFS {

  public:
    BFS(string s, Graph airports);
    vector<string> getBestPath();
        
  private:
    queue<string> airportQueue; 
    string start;
    string end;
    Graph airports;

};
