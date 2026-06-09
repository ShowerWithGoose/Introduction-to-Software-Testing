//
// Created by  on 2024-08-22.
//

#include <iostream>
#include <algorithm>

#include "utils/utils.h"
#include "frontend/Lexer/Lexer.h"
#include "errors/Error.h"

int main(int argc, char *argv[]) {

    std::string input_path = "testfile.txt";
    std::string output_path = "lexer.txt";
//    std::string input_path = argv[1];
//    std::string output_path = argv[2];

    std::string text = readFileToString(input_path);
    std::replace(text.begin(), text.end(), '\r', ' ');

    frontend::Lexer lexer(text);
    lexer.printTokenList(output_path);
    error::printErrorList();
    return 0;
}