//
// Created by  on 2024/10/6.
//

#ifndef SYS_COMPILER_PARSER_H
#define SYS_COMPILER_PARSER_H



#include "../Lexer/Lexer.h"
#include "Node.h"
#include "../../utils/utils.h"


namespace frontend {

    class Parser {
    public:
        explicit Parser(Lexer *lexer, const std::string& parser_path = "");

        Node *parse();

    private:
        CompUnit *parseCompUnit();

        Decl *parseDecl();

        ConstDecl *parseConstDecl();

        BType *parseBType();

        ConstDef *parseConstDef();

        ConstInitVal *parseConstInitVal();

        VarDecl *parseVarDecl();

        VarDef *parseVarDef();

        InitVal *parseInitVal();

        FuncDef *parseFuncDef();

        MainFuncDef *parseMainFuncDef();

        FuncType *parseFuncType();

        FuncFParams *parseFuncFParams();

        FuncFParam *parseFuncFParam();

        Block *parseBlock();

        BlockItem *parseBlockItem();

        Stmt *parseStmt();

        ForStmt *parseForStmt();

        Exp *parseExp();

        Cond *parseCond();

        LVal *parseLVal();

        PrimaryExp *parsePrimaryExp();

        Number *parseNumber();

        Character *parseCharacter();

        UnaryExp *parseUnaryExp();

        UnaryOp *parseUnaryOp();

        FuncRParams *parseFuncRParams();

        MulExp *parseMulExp();

        AddExp *parseAddExp();

        RelExp *parseRelExp();

        EqExp *parseEqExp();

        LAndExp *parseLAndExp();

        LOrExp *parseLOrExp();

        ConstExp *parseConstExp();

    private:
        Stmt::StmtType getStmtType();

    private:
        Lexer *lexer;
    };

} // frontend

#endif //SYS_COMPILER_PARSER_H
