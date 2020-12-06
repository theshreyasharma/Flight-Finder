#pragma once

#include <queue>
#include <string>
#include <vector>
#include "graph1.h"
#include <unordered_map>
#include <tuple>

using std::queue;
using std::vector;
using std::string;
using std::unordered_map;
using std::pair;

class BFS {
    public:
        BFS(string s, string e, int maxLegDistance, Graph airports);
        vector<string> getBestPath();
        
    private:
    queue<string> airportQueue; 
    string start;
    string end;
    int maxDistance;
    Graph airports;

    //Filled map;
    unordered_map<string, vector< tuple<string, int, int> > > paths;
    
    


};
