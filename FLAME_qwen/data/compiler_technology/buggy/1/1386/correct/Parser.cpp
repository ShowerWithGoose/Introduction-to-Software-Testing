
#include "Parser.h"
Parser::Parser(Lexer *lexer){
    this->lexer = lexer;
    ast = std::make_shared<CompUnitAST>();
}
void Parser::parseNode() {
    lexer->getToken();
    ast->createNode(lexer);
}