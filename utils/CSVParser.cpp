#include "CSVParser.h"
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>
#include <sstream>

using namespace std;

vvs readCSV(const std::string path_to_file) {
    vvs result;
    ifstream file(path_to_file);
    if(!file.is_open())
        throw runtime_error("Could not open file");
    string line;

    if(file.good()) {
        while(getline(file, line)) {
            vector<string> tmp;
            string val;
            stringstream ss(line);
            while (getline(ss, val, ','))
                tmp.push_back(val);
            result.push_back(tmp);
        }
    }

    file.close();
    return result;
}

void writeCSV(const string path_to_file, vvs data_set) {
    ofstream file(path_to_file);
    for (int i = 0; i < data_set.size(); i++) {
        for (int j = 0; j < data_set[i].size(); j++)
            file << data_set[i][j] << (j != data_set[i].size() - 1 ? "," : "");
        file << (i != data_set.size() - 1 ? "\n" : "");
    }
    file.close();
}