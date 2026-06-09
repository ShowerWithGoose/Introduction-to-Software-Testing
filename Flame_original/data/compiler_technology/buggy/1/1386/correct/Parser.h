

#ifndef COMPILER_PARSER_H
#define COMPILER_PARSER_H

#include "tools.h"
#include "AST.h"
class Parser{
public:
    Parser(Lexer* lexer1);
    void parseNode();
private:
    Lexer* lexer;
    std::shared_ptr<ASTNode> ast;
};

#endif //COMPILER_PARSER_H
