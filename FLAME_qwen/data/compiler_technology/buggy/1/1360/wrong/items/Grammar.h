//
// Created by  on 2024/10/11.
//

#ifndef MYLEXER_ANALYSIS_GRAMMAR_H
#define MYLEXER_ANALYSIS_GRAMMAR_H
#include <string>

enum GrammarType{
    BlockItem,
    BType,
    Decl,
    // 需要输出
    CompUnit,
    ConstDecl,
    VarDecl,
    ConstDef,
    ConstInitVal,
    VarDef,
    InitVal,
    FuncDef,
    MainFuncDef,
    FuncType,
    FuncFParams,
    FuncFParam,
    Block,
    Stmt,
    ForStmt,
    Exp,
    Cond,
    LVal,
    PrimaryExp,
    Number,
    Character,
    UnaryExp,
    UnaryOp,
    FuncRParams,
    MulExp,
    AddExp,
    RelExp,
    EqExp,
    LAndExp,
    LOrExp,
    ConstExp
};
struct Grammar{
    GrammarType type;
    std::string value;
    static std::string GrammarType2String(GrammarType type);
};


#endif //MYLEXER_ANALYSIS_GRAMMAR_H
