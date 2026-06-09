//
// Created by  on 2024/9/20.
//
#include <iostream>
#include <fstream>

#include  "include/configure.h"
#include  "include/lexer.h"

int main() {
    //open src file
    std::ifstream input("testfile.txt");

    if (!input.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return -1;
    }

    //lexical analysis
    std::vector<Token> tokens;
    std::vector<Error> errors;

    Lexer lexer = Lexer(tokens, input, errors);

    while (!input.eof()) {
        lexer.nextToken();
    }
    input.close();

    #ifdef LEXER_
    std::ofstream output("lexer.txt");
    if (!output.is_open()) {
        std::cerr << "Error opening output file" << std::endl;
        return -1;
    }

    if (!errors.empty()) {
        for (Error error : errors) {
            output << error.toString() << std::endl;
        }
        return 0;//TODO try try
    }
    for (const Token& token : tokens) {
        output << token.toString() << std::endl;
    }
    output.close();
    #endif

    return 0;
}
