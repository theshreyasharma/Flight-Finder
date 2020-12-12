#include "BFS.h"

BFS::BFS(string s, Graph ports) : start(s), airports(ports) { }

vector<string> BFS::getBestPath() {
   
   vector<string> bfs_traversal;
   vector<string> helper;

   airportQueue.push(start);
   bfs_traversal.push_back(start);

   int count = 0;
    
   while(!airportQueue.empty()) {
      string current_airport = airportQueue.front();

      if (count != 0) {
         bfs_traversal.push_back(current_airport);
      }

      airportQueue.pop();

      // Retrieve adjacent airports
      vector<string> adjacents = airports.getAdjacent(current_airport);

      for (int i = 0; i <int(adjacents.size()); i++) {
         // If node is not currently in traversal, add it to the queue and traversal
         if (std::find(bfs_traversal.begin(), bfs_traversal.end(), adjacents[i]) == bfs_traversal.end()) {
            if (std::find(helper.begin(), helper.end(), adjacents[i]) == helper.end()) {
               airportQueue.push(adjacents[i]);
               helper.push_back(adjacents[i]);
            }
         }
      }
      count++;
   }

   return bfs_traversal;
}