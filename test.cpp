#include "cs225/catch/catch.hpp"
#include "BFS.h"
#include "graph.h"

TEST_CASE("TESTGRAPH", "[valgrind][weight=1]")
{
    std::unordered_map<std::string, std::pair<double, double>> flights_data;
    std::ifstream myFile("preprocessing/openflightsformatted.csv");

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

    Graph g = Graph(false, flights_data, 2);
    std::vector<Vertex> vertices = g.getVertices();

    for (int i = 0; i < vertices.size(); i++) {
        std::cout << vertices[i] << std::endl;
    }
}


// TEST_CASE("TESTBFS", "[valgrind][weight=1]")
// {
//     Graph g = Graph(false);
//     string a1 = "a1";
//     string a2 = "a2";
//     string a3 = "a3";
//     string a4 = "a4";
//     string a5 = "a5";


// }