#include "BFS.h"

BFS::BFS(string s, Graph ports) : start(s), airports(ports) { 
    // start = s;
}

vector<string> BFS::getBestPath() {

   vector<string> bfs_traversal;
   airportQueue.push(start);
   bfs_traversal.push_back(start);

   int count = 0;
    
   while(!airportQueue.empty()) {
      string current_airport = airportQueue.front();
      if (count != 0) {
         bfs_traversal.push_back(current_airport);
      }
      airportQueue.pop();


      vector<string> adjacents = airports.getAdjacent(current_airport);
      for (int i = 0; i <int(adjacents.size()); i++) {
         if (std::find(bfs_traversal.begin(), bfs_traversal.end(), adjacents[i]) == bfs_traversal.end()) {
            airportQueue.push(adjacents[i]);
         }
      }
      count++;
   }

   return bfs_traversal;
}