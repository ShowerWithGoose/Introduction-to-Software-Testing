//
// Created by  on 2024/10/2.
//
#include <fstream>
#include "Error.h"

namespace error {
    std::vector<Error *> errorList;
    void printErrorList() {
        std::ofstream file("error.txt");
        for (auto e : errorList) {
            file << e->lineNum << " " << e->category << std::endl;
        }
    }
}