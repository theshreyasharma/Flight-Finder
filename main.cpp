#include "graph.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include "landmarkpath.h"
#include "dijkstras.h"
#include "BFS.h"



int main() {
    std::unordered_map<std::string, std::pair<double, double>> flights_data;
    std::ifstream myFile("Preprocessing/openflightsformatted.csv");

    std::string line;
    std::string name;
    while (getline(myFile, line,'\n')) {
        std::vector<string> split;
        std::stringstream s_stream(line); 
        while(s_stream.good()) {
            std::string substr;
            getline(s_stream, substr, ',');
            split.push_back(substr);
        }
        flights_data.insert({split.at(0), std::make_pair(std::stod(split.at(1)), std::stod(split.at(2)))});
    }
    //  for (const auto& iter : flights_data) {
    //     std::cout << iter.first << ": " << iter.second.first << ", "<< iter.second.second << "\n";
    // }


    //BFS

    Graph g = Graph(false, flights_data, 2);

    BFS b = BFS("Chicago O'Hare International Airport",  g);

    std::vector<Vertex> bfsTraversal = b.getBestPath();

    std::ofstream myfileBFS;
    myfileBFS.open ("bfs.txt");
    myfileBFS << "BFS Traversal\n";


    std::ostream_iterator<std::string> output_iterator(myfileBFS, "\n");
    std::copy(bfsTraversal.begin(), bfsTraversal.end(), output_iterator);
    
    myfileBFS.close();

    //Dijkstra's algorithm
    


    // //Landmark Path Algorithm
    // Graph landmarkpath = Graph(false, flights_data, 2);
    // std::ofstream myfile;
    // myfile.open ("/output/landmarkpath.txt");
    // myfile << "Landmark Path Algorithm from Chicago to Delhi going through New York.\n";

    // LandmarkPath landmark;
    // std::vector<std::string> out = landmark.findShortestPath(landmarkpath, 
    //                                                         "Chicago O'Hare International Airport", 
    //                                                         "La Guardia Airport",
    //                                                          "Safdarjung Airport");

    // std::ostream_iterator<std::string> output_iterator(myfile, "\n");
    // std::copy(out.begin(), out.end(), output_iterator);
    
    // myfile.close();

    return 0;
}