//
// Created by  on 2024-08-22.
//

#include <iostream>
#include <algorithm>

#include "utils/utils.h"
#include "frontend/Lexer/Lexer.h"
#include "errors/Error.h"
#include "frontend/Parser/Parser.h"

void clean() {
    for (auto &p : frontend::Node::all_nodes) {
        if (!p.second) {
            delete p.first;
        }
    }
}

int main(int argc, char *argv[]) {

    std::string input_path = "testfile.txt";
    std::string output_path = "parser.txt";
//    std::string input_path = argv[1];
//    std::string output_path = argv[2];

    std::string text = readFileToString(input_path);
    std::replace(text.begin(), text.end(), '\r', ' ');

    frontend::Lexer lexer(text);
    frontend::Parser parser(&lexer, output_path);

    auto ast = parser.parse();
    error::printErrorList();

    clean();

    return 0;
}