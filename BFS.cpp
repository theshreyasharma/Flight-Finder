
#include "BFS.h"


BFS::BFS(string s, Graph ports) : airports(ports)
 { 
    start = s;

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
   //   //get path 

   //          //Find shortest path
   //      int min = get<1>(paths[end][i]);
   //      int minIndex = 0;
   //      for (int i = 0; i < paths[end].size(); i++) {
   //          if (std::get<1>(paths[end][i]) < min) {
   //              minIndex = i;
   //              min = std::get<1>(paths[end][i]);
   //          }
   //      }
        
      //   //actually trace back
      //   vector<string> final_path;

      //   final_path.push_back(get<0>(path[end][minIndex]));

      //   for (int i = 0; i < min - 1; i++) {
      //       final_path.push_back(get<0>(path[final_path.size() - 1][minIndex]));
      //   } 

      //   std::reverse(final_path.begin(), final_path.end());


     return bfs_traversal;

 }