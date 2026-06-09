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
    if (!errors.empty()) {
        std::ofstream err("error.txt");
        if (!err.is_open()) {
            std::cerr << "Error opening output file" << std::endl;
            return -1;
        }

        for (Error error : errors) {
            err << error.toString() << std::endl;
        }
        err.close();
        return 1;
    }

    std::ofstream output("lexer.txt");
    if (!output.is_open()) {
        std::cerr << "Error opening output file" << std::endl;
        return -1;
    }
    for (const Token& token : tokens) {
        output << token.toString() << std::endl;
    }
    output.close();
    #endif

    return 0;
}
