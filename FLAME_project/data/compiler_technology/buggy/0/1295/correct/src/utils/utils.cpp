//
// Created by  on 2024/10/2.
//

#include <string>
#include <fstream>
#include <iostream>
#include <vector>


bool isDigit(char s) {
    return s >= '0' && s <= '9';
}

bool isIdentifierChar(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') || ch == '_';
}

std::string readFileToString(const std::string& filename) {
    std::ifstream file(filename, std::ios::in | std::ios::binary | std::ios::ate);
    if (!file) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return "";
    }

    std::streamsize size = file.tellg();
    std::vector<char> buffer(size);

    file.seekg(0, std::ios::beg);
    file.read(buffer.data(), size);

    if (!file) {
        std::cerr << "Error reading file: " << filename << std::endl;
        return "";
    }

    return std::string(buffer.begin(), buffer.end());
}
