#include "Error.h"
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

bool compareErrorItems(const errorItem &a, const errorItem &b) {
    return a.lineNum < b.lineNum;
}

void Error::sortError() {
    std::ifstream inputFile("error.txt");
    std::vector<errorItem> errorList;
    errorItem temp;

    // 从文件中读取错误项
    while (inputFile >> temp.lineNum) {
        std::getline(inputFile, temp.errorType);
        errorList.push_back(temp);
    }
    inputFile.close();

    // 对错误项进行稳定排序
    std::stable_sort(errorList.begin(), errorList.end(), compareErrorItems);

    // 将排序后的错误项写回文件
    std::ofstream outputFile("error.txt");
    for (const auto &item : errorList) {
        outputFile << item.lineNum << item.errorType << std::endl;
    }
    outputFile.close();
}