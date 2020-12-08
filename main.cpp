#include "graph.h"
#include <iostream>
#include <sstream>
int main() {
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
     for (const auto& iter : flights_data) {
        std::cout << iter.first << ": " << iter.second.first << ", "<< iter.second.second << "\n";
    }
    return 0;
}