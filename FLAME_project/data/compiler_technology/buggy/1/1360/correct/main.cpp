#include <iostream>
#include <fstream>
#include <vector>
#include "analysis/lexer.h"  // 确保包含 lexer.h 头文件
#include "analysis/parser.h"
#include "error/errorList.h"

int main() {
    std::ifstream inputFile("testfile.txt");
    if (!inputFile) {
        std::cerr << "Error opening file testfile.txt" << std::endl;
        return 1;
    }

    std::string code((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
    inputFile.close();

    Lexer lexer(code);
    std::vector<Token> tokens = lexer.tokenize();

    std::ofstream outputFile1;
    std::ofstream outputFile2;

    outputFile1.open("lexer.txt");
    for (const Token &token: tokens) {
        token.print(outputFile1);
    }
    //print to output.txt

    outputFile1.close();


    parser parser(tokens);
    std::shared_ptr<Node> root = parser.parse();
    if (errorList::getInstance().haveError()) {
        outputFile2.open("error.txt");
        errorList::getInstance().print(outputFile2);

        outputFile2.close();
        return 1;
    }
        outputFile2.open("parser.txt");
        root->postOrderTraversal(outputFile2);
        outputFile2.close();

    return 0;
}