// CommentRemover.cpp
#include "CommentRemover.h"
#include <fstream>
#include <iostream>

void removeComments(const std::string &inputFileName, const std::string &outputFileName) {
    std::ifstream inputFile(inputFileName);
    if (!inputFile) {
        std::cerr << "无法打开文件 " << inputFileName << std::endl;
        return;
    }

    std::ofstream outputFile(outputFileName);
    if (!outputFile) {
        std::cerr << "无法创建文件 " << outputFileName << std::endl;
        return;
    }

    std::string line;
    bool insideBlockComment = false; // 标记是否在多行注释中

    while (std::getline(inputFile, line)) {
        std::string processedLine;
        size_t i = 0;

        while (i < line.size()) {
            if (insideBlockComment) {
                size_t endBlockPos = line.find("*/", i);
                if (endBlockPos != std::string::npos) {
                    insideBlockComment = false;
                    i = endBlockPos + 2;
                } else {
                    break;
                }
            } else if (line[i] == '/' && i + 1 < line.size() && line[i + 1] == '/') {
                break;
            } else if (line[i] == '/' && i + 1 < line.size() && line[i + 1] == '*') {
                insideBlockComment = true;
                i += 2;
            } else {
                processedLine += line[i];
                i++;
            }
        }

        if (!insideBlockComment) {
            if (!processedLine.empty()) {
                outputFile << processedLine;
            }
            outputFile << std::endl;
        } else {
            outputFile << std::endl;
        }
    }

    inputFile.close();
    outputFile.close();
}
//
// Created by  on 24-10-11.
//
