#include "cs225/catch/catch.hpp"
#include "BFS.h"
#include "graph.h"
#include "dijkstras.h"




// TEST_CASE("TESTGRAPH", "[valgrind][weight=1]")
// {
//     std::unordered_map<std::string, std::pair<double, double>> flights_data;
//     std::ifstream myFile("preprocessing/openflightsformatted.csv");

//     std::string line;
//     std::string name;
//     while (getline(myFile, line,'\n')) {
//         std::vector<string> split;
//         std::stringstream s_stream(line); 
//         while(s_stream.good()) {
//             std::string substr;
//             getline(s_stream, substr, ',');
//             split.push_back(substr);
//         }
//         flights_data.insert({split.at(0), std::make_pair(std::stod(split.at(1)), std::stod(split.at(2)))});
//     }

//     Graph g = Graph(false, flights_data, 2);
//     std::vector<Vertex> vertices = g.getVertices();

//     for (unsigned i = 0; i < vertices.size(); i++) {
//         std::cout << vertices[i] << std::endl;
//     }
// }


// TEST_CASE("TESTBFS", "[valgrind][weight=1]")
// {
//     Graph g = Graph(false);
    
//     g.insertVertex("a");
//     g.insertVertex("b");
//     g.insertVertex("c");
//     g.insertVertex("d");
//     g.insertVertex("e");

//     g.insertEdge("a", "b");
//     g.insertEdge("b", "d");
//     g.insertEdge("b", "c");
//     g.insertEdge("d", "e");

//     //std::cout << g.getAdjacent("a")[0] << std::endl;

//     BFS b = BFS("a", g);

//     std::vector<Vertex> vertices = b.getBestPath();
    
//     for (unsigned i = 0; i < vertices.size(); i++) {
//         std::cout << vertices[i] << std::endl;
//     }

// }

// TEST_CASE("TESTBFS-Airport", "[valgrind][weight=1]")
// {
//     std::unordered_map<std::string, std::pair<double, double>> flights_data;
//     std::ifstream myFile("Preprocessing/openflightsformatted.csv");

//     std::string line;
//     std::string name;
//     while (getline(myFile, line,'\n')) {
//         std::vector<string> split;
//         std::stringstream s_stream(line); 
//         while(s_stream.good()) {
//             std::string substr;
//             getline(s_stream, substr, ',');
//             split.push_back(substr);
//         }
//         flights_data.insert({split.at(0), std::make_pair(std::stod(split.at(1)), std::stod(split.at(2)))});
//     }
//     //std::cout << flights_data.size() << std::endl;
//     Graph g = Graph(false, flights_data, 2);

//     BFS b = BFS("Chicago O'Hare International Airport",  g);

//     std::vector<Vertex> vertices = b.getBestPath();
//     std::cout << vertices.size() << std::endl;
    
//     // for (unsigned i = 0; i < vertices.size(); i++) {
//     //     std::cout << vertices[i] << std::endl;
//     // }

// }



TEST_CASE("TESTBFS", "[valgrind][weight=1]")
{
    Graph g = Graph(true);
    
    g.insertVertex("siebel");
    g.insertVertex("rantoul");
    g.insertVertex("bloomington");
    g.insertVertex("kankakee");
    g.insertVertex("pontiac");
    g.insertVertex("chicago");
    g.insertVertex("joliet");
    g.insertVertex("cloudgate");

    g.insertEdge("siebel", "rantoul");
    g.setEdgeWeight("siebel", "rantoul", 21);

    g.insertEdge("siebel", "bloomington");
    g.setEdgeWeight("siebel", "bloomington", 50);

    g.insertEdge("rantoul", "kankakee");
    g.setEdgeWeight("rantoul", "kankakee", 57);

    g.insertEdge("bloomington", "pontiac");
    g.setEdgeWeight("bloomington", "pontiac", 42);

    g.insertEdge("kankakee", "pontiac");
    g.setEdgeWeight("kankakee", "pontiac", 53);

    g.insertEdge("kankakee", "chicago");
    g.setEdgeWeight("kankakee", "chicago", 63);
    
    g.insertEdge("pontiac", "joliet");
    g.setEdgeWeight("pontiac", "joliet", 57);

    g.insertEdge("pontiac", "chicago");
    g.setEdgeWeight("pontiac", "chicago", 40);

    g.insertEdge("joliet", "chicago");
    g.setEdgeWeight("joliet", "chicago", 51);

    g.insertEdge("chicago", "cloudgate");
    g.setEdgeWeight("chicago", "cloudgate", 1);
    


    Dijkstras d = Dijkstras();

    std::vector<Vertex> vertices = d.findShortestPath(g, "siebel", "cloudgate");
    
    // for (unsigned i = 0; i < vertices.size(); i++) {
    //     std::cout << vertices[i] << std::endl;
    // }

}