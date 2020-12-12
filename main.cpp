#include "graph.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include "landmarkpath.h"
#include "dijkstras.h"
#include "BFS.h"

int main() {

    // Creating flight data map from preprocessed CSV
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


    //BFS
    Graph BFS_graph = Graph(false, flights_data, 2, false);

    BFS b = BFS("Goroka Airport",  BFS_graph);

    std::vector<Vertex> bfsTraversal = b.getBestPath();

    std::ofstream myfileBFS;
    myfileBFS.open ("output/bfs.txt");
    myfileBFS << "BFS Traversal\n";


    std::ostream_iterator<std::string> output_iterator_BFS(myfileBFS, "\n");
    std::copy(bfsTraversal.begin(), bfsTraversal.end(), output_iterator_BFS);
    
    myfileBFS.close();

    // Dijkstra's algorithm
    Graph Dijkstra_Graph = Graph(true, flights_data, 2, true);
    Dijkstras d = Dijkstras();
    vector<std::string> path = d.findShortestPath(Dijkstra_Graph, "Dallas Fort Worth International Airport", "Truth Or Consequences Municipal Airport");

    std::ofstream myFileDijkstra;
    myFileDijkstra.open ("output/dijkstras.txt");
    myFileDijkstra << "Dijkstra's\n";

    std::ostream_iterator<std::string> output_iterator_Dijkstra(myFileDijkstra, "\n");
    std::copy(bfsTraversal.begin(), bfsTraversal.end(), output_iterator_Dijkstra);
    
    myFileDijkstra.close();

    // Landmark Path Algorithm
    Graph landmarkpath = Graph(false, flights_data, 2, true);
    std::ofstream myfile;
    myfile.open ("output/landmarkpath.txt");
    myfile << "Landmark Path Algorithm from Chicago to Cuers-Pierrefeu, France going through New York.\n";

    LandmarkPath landmark;
    std::vector<std::string> out = landmark.findShortestPath(landmarkpath, 
                                                            "Chicago O'Hare International Airport", 
                                                            "La Guardia Airport",
                                                            "Cuers-Pierrefeu Airport");

    std::ostream_iterator<std::string> output_iterator_Landmark(myfile, "\n");
    std::copy(out.begin(), out.end(), output_iterator_Landmark);
    
    myfile.close();

    return 0;
}