#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fstream>

#include "makeDir.h"


void makeDir() {
    struct stat info;
    if (stat("data", &info) != 0)
        system("mkdir data");
    if (stat("data/Member.csv", &info) != 0)
        createMemberCSV();
}

void createMemberCSV() {
    std::ofstream fout("data/Member.csv");
    fout << "username,password\nadmin,demo123";
    fout.close();
}