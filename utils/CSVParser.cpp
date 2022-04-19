#include "CSVParser.h"
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>
#include <sstream>

// using namespace std;
using std::string;
using std::vector;


vvs readCSV(const std::string path_to_file) {
    vvs result;
    std::ifstream file(path_to_file);
    if(!file.is_open())
        throw std::runtime_error("Could not open file");
    string line;

    if(file.good()) {
        while(getline(file, line)) {
            vector<string> tmp;
            string val;
            std::stringstream ss(line);
            while (std::getline(ss, val, ','))
                tmp.push_back(val);
            result.push_back(tmp);
        }
    }

    file.close();
    return result;
}

void writeCSV(const string path_to_file, vvs data_set) {
    std::ofstream file(path_to_file);
    for (int i = 0; i < data_set.size(); i++) {
        for (int j = 0; j < data_set[i].size(); j++)
            file << data_set[i][j] << (j != data_set[i].size() - 1 ? "," : "");
        file << (i != data_set.size() - 1 ? "\n" : "");
    }
    file.close();
}