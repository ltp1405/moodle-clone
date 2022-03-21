#pragma once
#include <vector>
#include <string>

typedef std::vector<std::vector<std::string>> vvs;

vvs readCSV(const std::string path_to_file);
void writeCSV(const std::string path_to_file, vvs data_set);