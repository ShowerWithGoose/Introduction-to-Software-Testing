//
// Created by  on 2024/10/12.
//
#include "token.h"
#include <memory>
#include "Grammar.h"
#include <vector>
#include "AST/node.h"


#ifndef MYLEXER_ANALYSIS_PARSER_H
#define MYLEXER_ANALYSIS_PARSER_H


class parser {
private:
    std::vector<Token> tokens;
    int now;
    int depth;
    std::shared_ptr<Node> root;
public:
    explicit parser(std::vector<Token> tokens);
    std::shared_ptr<Node> parse();
    bool isAssign(int pt);

    std::shared_ptr<Node> handle_CompUnit(int d);
    std::shared_ptr<Node> handle_Decl(int d);
    std::shared_ptr<Node> handle_FuncDef(int d);
    std::shared_ptr<Node> handle_MainFuncDef(int d);
    std::shared_ptr<Node> handle_ConstDecl(int d);
    std::shared_ptr<Node> handle_VarDecl(int d);
    std::shared_ptr<Node> handle_BType(int d);
    std::shared_ptr<Node> handle_ConstDef(int d);
    std::shared_ptr<Node> handle_ConstInitVal(int d);
    std::shared_ptr<Node> handle_VarDef(int d);
    std::shared_ptr<Node> handle_InitVal(int d);
    std::shared_ptr<Node> handle_FuncType(int d);
    std::shared_ptr<Node> handle_FuncFParams(int d);
    std::shared_ptr<Node> handle_Block(int d);
    std::shared_ptr<Node> handle_FuncFParam(int d);
    std::shared_ptr<Node> handle_BlockItem(int d);
    std::shared_ptr<Node> handle_Stmt(int d);
    std::shared_ptr<Node> handle_FuncRParams(int d);
    std::shared_ptr<Node> handle_Exp(int d);
    std::shared_ptr<Node> handle_LVal(int d);
    std::shared_ptr<Node> handle_Cond(int d);
    std::shared_ptr<Node> handle_ForStmt(int d);
    std::shared_ptr<Node> handle_AddExp(int d);
    std::shared_ptr<Node> handle_LOrExp(int d);
    std::shared_ptr<Node> handle_PrimaryExp(int d);
    std::shared_ptr<Node> handle_Number(int d);
    std::shared_ptr<Node> handle_Character(int d);
    std::shared_ptr<Node> handle_UnaryExp(int d);
    std::shared_ptr<Node> handle_UnaryOp(int d);
    std::shared_ptr<Node> handle_MulExp(int d);
    std::shared_ptr<Node> handle_RelExp(int d);
    std::shared_ptr<Node> handle_EqExp(int d);
    std::shared_ptr<Node> handle_LAndExp(int d);
    std::shared_ptr<Node> handle_ConstExp(int d);

};


#endif //MYLEXER_ANALYSIS_PARSER_H
