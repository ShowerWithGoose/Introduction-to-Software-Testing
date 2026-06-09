#pragma once

#ifndef BIANYI_GRAITEM_H
#define BIANYI_GRAITEM_H

#include <map>
#include <string>

enum GraItem {
    CompUnit, Decl, ConstDecl, BType, ConstDef,
    ConstInitVal, VarDecl, VarDef, InitVal, FuncDef,
    MainFuncDef, FuncType, FuncFParams, FuncFParam,
    Block, BlockItem, Stmt, ForStmt, Exp, Cond,
    LVal, PrimaryExp, Number, Character, UnaryExp,
    UnaryOp, FuncRParams, MulExp, AddExp, RelExp,
    EqExp, LAndExp, LOrExp, ConstExp, Unknown
};
const std::map<GraItem, std::string> GraItem_Str = {
        {CompUnit, "<CompUnit>"},
        {Decl, "<Decl>"},
        {ConstDecl, "<ConstDecl>"},
        {BType, "<BType>"},
        {ConstDef, "<ConstDef>"},
        {ConstInitVal, "<ConstInitVal>"},
        {VarDecl, "<VarDecl>"},
        {VarDef, "<VarDef>"},
        {InitVal, "<InitVal>"},
        {FuncDef, "<FuncDef>"},
        {MainFuncDef, "<MainFuncDef>"},
        {FuncType, "<FuncType>"},
        {FuncFParams, "<FuncFParams>"},
        {FuncFParam, "<FuncFParam>"},
        {Block, "<Block>"},
        {BlockItem, "<BlockItem>"},
        {Stmt, "<Stmt>"},
        {ForStmt, "<ForStmt>"},
        {Exp, "<Exp>"},
        {Cond, "<Cond>"},
        {LVal, "<LVal>"},
        {PrimaryExp, "<PrimaryExp>"},
        {Number, "<Number>"},
        {Character, "<Character>"},
        {UnaryExp, "<UnaryExp>"},
        {UnaryOp, "<UnaryOp>"},
        {FuncRParams, "<FuncRParams>"},
        {MulExp, "<MulExp>"},
        {AddExp, "<AddExp>"},
        {RelExp, "<RelExp>"},
        {EqExp, "<EqExp>"},
        {LAndExp, "<LAndExp>"},
        {LOrExp, "<LOrExp>"},
        {ConstExp, "<ConstExp>"},
        {Unknown, "<None>"}
};
#endif