// #pragma once

// #include "BFS.h"


// BFS::BFS(string s, string e, Graph airports)
//  { 
//     start = s;
//     end = e;
//     airports = airports;

//  }


//  vector<string> BFS::getBestPath() {
//     vector<string> bfs_traversal;
//     airportQueue.push(start);
    
//      while(!airportQueue.empty()) {

//          string current_airport = airportQueue.front();
//          bfs_traversal.push_back(current_airport);
//          airportQueue.pop();

//          vector<string> adjacents = airports.getVertices();
//          for (int i = 0; i <int(adjacents.size()); i++) {
//             airportQueue.push(adjacents[i]);
//          }
//      }

//     //  //get path 

//     //         //Find shortest path
//     //     int min = get<1>(paths[end][i]);
//     //     int minIndex = 0;
//     //     for (int i = 0; i < paths[end].size(); i++) {
//     //         if (std::get<1>(paths[end][i]) < min) {
//     //             minIndex = i;
//     //             min = std::get<1>(paths[end][i]);
//     //         }
//     //     }
        
//     //     //actually trace back
//     //     vector<string> final_path;

//     //     final_path.push_back(get<0>(path[end][minIndex]));

//     //     for (int i = 0; i < min - 1; i++) {
//     //         final_path.push_back(get<0>(path[final_path.size() - 1][minIndex]));
//     //     } 

//     //     std::reverse(final_path.begin(), final_path.end());


//      return bfs_traversal;

//  }