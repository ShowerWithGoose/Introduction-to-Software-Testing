//
// Created by  on 2024/10/2.
//
#include <fstream>
#include <algorithm>
#include "Error.h"

namespace error {
    std::vector<Error *> errorList;
    void printErrorList() {
        std::ofstream file("error.txt");
        // 先对数组按照行号排序
        std::sort(errorList.begin(), errorList.end(), [](Error *a, Error *b) {
            return a->lineNum < b->lineNum;
        });

        for (auto e : errorList) {
            file << e->lineNum << " " << e->category << std::endl;
        }
    }
}