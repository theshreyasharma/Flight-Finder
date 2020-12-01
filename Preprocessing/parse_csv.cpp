#include "parse_csv.h"

std::map<std::string, std::pair<double, double>> parse_csv::extractCSV() {
    std::map<std::string, std::pair<double, double>> data;
    std::ifstream myFile("openflights.csv");

    std::string str;
    std::vector<std::string> line; 
    while (myFile.good()) {
        std::string name;
        std::getline(myFile, name, ',');
        std::pair<std::string, std::string>(line.at(6), line.at(7));
        //data.insert(line.at(1), std::make_pair(line.at(6), line.at(7)));
    }
    return data;
}