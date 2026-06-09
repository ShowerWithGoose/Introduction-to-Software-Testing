//
// Created by  on 2024/10/11.
//

#include "Grammar.h"
#include <unordered_map>

std::string Grammar::GrammarType2String(GrammarType type) {
    static const std::unordered_map<GrammarType, std::string> typeToString ={
            {BlockItem, "BlcokItem"},
            {BType, "BType"},
            {Decl, "Decl"},
            {CompUnit, "CompUnit"},
            {ConstDecl, "ConstDecl"},
            {VarDecl, "VarDecl"},
            {ConstDef, "ConstDef"},
            {ConstInitVal, "ConstInitVal"},
            {VarDef, "VarDef"},
            {InitVal, "InitVal"},
            {FuncDef, "FuncDef"},
            {MainFuncDef, "MainFuncDef"},
            {FuncType, "FuncType"},
            {FuncFParams, "FuncFParams"},
            {FuncFParam, "FuncFParam"},
            {Block, "Block"},
            {Stmt, "Stmt"},
            {ForStmt, "ForStmt"},
            {Exp, "Exp"},
            {Cond, "Cond"},
            {LVal, "LVal"},
            {PrimaryExp, "PrimaryExp"},
            {Number, "Number"},
            {Character, "Character"},
            {UnaryExp, "UnaryExp"},
            {UnaryOp, "UnaryOp"},
            {FuncRParams, "FuncRParams"},
            {MulExp, "MulExp"},
            {AddExp, "AddExp"},
            {RelExp, "RelExp"},
            {EqExp, "EqExp"},
            {LAndExp, "LAndExp"},
            {LOrExp, "LOrExp"},
            {ConstExp, "ConstExp"}
    };
    return typeToString.at(type);
}