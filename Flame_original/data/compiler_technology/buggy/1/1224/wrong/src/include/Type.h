#ifndef _TYPE_H_
#define _TYPE_H_

enum SYMTYPE
{
    IDENFR = 0,
    INTCON = 1,
    STRCON = 2,
    CHRCON = 3,
    MAINTK = 4,
    CONSTTK = 5,
    INTTK = 6,
    CHARTK = 7,
    BREAKTK = 8,
    CONTINUETK = 9,
    IFTK = 10,
    ELSETK = 11,
    NOT = 12,
    AND = 13,
    OR = 14,
    FORTK = 15,
    GETINTTK = 16,
    GETCHARTK = 17,
    PRINTFTK = 18,
    RETURNTK = 19,
    PLUS = 20,
    MINU = 21,
    VOIDTK = 22,
    MULT = 23,
    DIV = 24,
    MOD = 25,
    LSS = 26,
    LEQ = 27,
    GRE = 28,
    GEQ = 29,
    EQL = 30,
    NEQ = 31,
    ASSIGN = 32,
    SEMICN = 33,
    COMMA = 34,
    LPARENT = 35,
    RPARENT = 36,
    LBRACK = 37,
    RBRACK = 38,
    LBRACE = 39,
    RBRACE = 40,
    NOTOKEN = 41
};

typedef struct TOKENS
{
    SYMTYPE sym;
    std::string token;
    int line;
} TOKENS;
SYMTYPE reserver();

enum PARSER_TYPE
{
    _CompUnit = 0,
    _Decl = 1,
    _ConstDecl = 2,
    _BType = 3,
    _ConstDef = 4,
    _ConstInitVal = 5,
    _VarDecl = 6,
    _VarDef = 7,
    _InitVal = 8,
    _FuncDef = 9,
    _MainFuncDef = 10,
    _FuncType = 11,
    _FuncFParams = 12,
    _FuncFParam = 13,
    _Block = 14,
    _BlockItem = 15,
    _Stmt = 16,
    _ForStmt = 17,
    _Exp = 18,
    _Cond = 19,
    _LVal = 20,
    _PrimaryExp = 21,
    _Number = 22,
    _Character = 23,
    _UnaryExp = 24,
    _UnaryOp = 25,
    _FuncRParams = 26,
    _MulExp = 27,
    _AddExp = 28,
    _RelExp = 29,
    _EqExp = 30,
    _LAndExp = 31,
    _LOrExp = 32,
    _ConstExp = 33,
    _ENDPARSE = 34,
    _NULL = 35
};

// type.cpp
extern const std::string parser_names[50]; // 声明 parser_names
extern const std::string sym_names[50];    // 声明 sym_names
#endif
