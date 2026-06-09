#include <string>
#include "include/Type.h"
#include "include/Lexer.h"
// 这个文件负责一些全局变量的定义

const std::string sym_names[50] = {"IDENFR",
                                   "INTCON",
                                   "STRCON",
                                   "CHRCON",
                                   "MAINTK",
                                   "CONSTTK",
                                   "INTTK",
                                   "CHARTK",
                                   "BREAKTK",
                                   "CONTINUETK",
                                   "IFTK",
                                   "ELSETK",
                                   "NOT",
                                   "AND",
                                   "OR",
                                   "FORTK",
                                   "GETINTTK",
                                   "GETCHARTK",
                                   "PRINTFTK",
                                   "RETURNTK",
                                   "PLUS",
                                   "MINU",
                                   "VOIDTK",
                                   "MULT",
                                   "DIV",
                                   "MOD",
                                   "LSS",
                                   "LEQ",
                                   "GRE",
                                   "GEQ",
                                   "EQL",
                                   "NEQ",
                                   "ASSIGN",
                                   "SEMICN",
                                   "COMMA",
                                   "LPARENT",
                                   "RPARENT",
                                   "LBRACK",
                                   "RBRACK",
                                   "LBRACE",
                                   "RBRACE"};
const std::string parser_names[50] = {
    "CompUnit",
    "Decl",
    "ConstDecl",
    "BType",
    "ConstDef",
    "ConstInitVal",
    "VarDecl",
    "VarDef",
    "InitVal",
    "FuncDef",
    "MainFuncDef",
    "FuncType",
    "FuncFParams",
    "FuncFParam",
    "Block",
    "BlockItem",
    "Stmt",
    "ForStmt",
    "Exp",
    "Cond",
    "LVal",
    "PrimaryExp",
    "Number",
    "Character",
    "UnaryExp",
    "UnaryOp",
    "FuncRParams",
    "MulExp",
    "AddExp",
    "RelExp",
    "EqExp",
    "LAndExp",
    "LOrExp",
    "ConstExp"};

SYMTYPE reserver()
{
    if (token == "main")
    {
        return MAINTK;
    }
    else if (token == "const")
    {
        return CONSTTK;
    }
    else if (token == "int")
    {
        return INTTK;
    }
    else if (token == "char")
    {
        return CHARTK;
    }
    else if (token == "break")
    {
        return BREAKTK;
    }
    else if (token == "continue")
    {
        return CONTINUETK;
    }
    else if (token == "if")
    {
        return IFTK;
    }
    else if (token == "else")
    {
        return ELSETK;
    }
    else if (token == "for")
    {
        return FORTK;
    }
    else if (token == "getint")
    {
        return GETINTTK;
    }
    else if (token == "getchar")
    {
        return GETCHARTK;
    }
    else if (token == "printf")
    {
        return PRINTFTK;
    }
    else if (token == "return")
    {
        return RETURNTK;
    }
    else if (token == "void")
    {
        return VOIDTK;
    }
    return IDENFR;
}