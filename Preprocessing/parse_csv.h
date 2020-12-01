#pragma once
#include <map>
#include <unordered_set>
#include <fstream>
#include <vector>
class parse_csv {
    public:
        std::map<std::string, std::pair<double, double>> extractCSV();
};