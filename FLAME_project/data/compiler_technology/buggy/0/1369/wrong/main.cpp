#include <iostream>
#include <fstream>
#include "include/Lexer.h"
#include "include/LexType.h"
int main() {
    Lexer& lexer = Lexer::getInstance();
    lexer.loadSource("testfile.txt");
    while(true) {
        Token token = lexer.next();
        if (token.getType() == LexType::ERROR) {
            lexer.setCorrectNessToFalse();
        }
        if (token.getType() == LexType::NULLVAL) {
            continue;
        }
        if (token.getType() == LexType::END) {
            break;
        }
        lexer.addToken(token);
    }
    vector<Token> tokens = lexer.getTokens();
    if (lexer.getCorrectNess() == true) {
        ofstream outFile("lexer.txt");
        for (size_t i = 0; i < tokens.size(); i++) {
            if (i == tokens.size() - 1) {
                outFile << lexTypeToString(tokens[i].getType()) << " " << tokens[i].getValue();
            } else {
                outFile << lexTypeToString(tokens[i].getType()) << " " << tokens[i].getValue() << endl;
            }
        }
        outFile.close();
    } else {
        ofstream outFile("error.txt");
        for (size_t i = 0; i < tokens.size(); i++) {
            if (tokens[i].getType() == LexType::ERROR) {
                outFile << tokens[i].getLineNum() << " " << tokens[i].getErrorType() << endl;
            }
        }
        outFile.close();
    }
    return 0;
}
