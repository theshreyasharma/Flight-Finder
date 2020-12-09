#pragma once

#include <queue>
#include <string>
#include <vector>
#include "graph.h"
#include <unordered_map>
#include <tuple>

using std::queue;
using std::vector;
using std::string;
// using std::unordered_map;
using std::pair;

class BFS {
    public:
        BFS(string s, string e, Graph airports);
        vector<string> getBestPath();
        
    private:
    queue<string> airportQueue; 
    string start;
    string end;
    Graph airports = Graph(false);

    //Filled map;
    // unordered_map<string, vector< tuple<string, int, int> > > paths;
    
    


};
