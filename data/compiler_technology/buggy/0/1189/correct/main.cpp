#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "frontend/Lexer.h"

std::string readFileToString(const std::string &filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

int main() {
    try {
        const std::string filePath = "testfile.txt";
        const std::string fileContent = readFileToString(filePath);
        Lexer lexer(fileContent);
        lexer.lexicalAnalysis();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
