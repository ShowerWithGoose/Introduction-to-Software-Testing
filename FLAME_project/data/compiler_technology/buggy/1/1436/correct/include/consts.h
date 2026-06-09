#ifndef __CONSTS_H
#define __CONSTS_H
#include <string>
enum TokenEnum
{
    EOFTK,
    SPACETK,
    ENTERTK,
    SINGLECMT,
    MULTCMT,
    IDENFR,
    INTCON,
    STRCON,
    CHRCON,
    MAINTK,
    CONSTTK,
    INTTK,
    CHARTK,
    BREAKTK,
    CONTINUETK,
    IFTK,
    ELSETK,
    NOT,
    AND,
    OR,
    FORTK,
    GETINTTK,
    GETCHARTK,
    PRINTFTK,
    RETURNTK,
    PLUS,
    MINU,
    VOIDTK,
    MULT,
    DIV,
    MOD,
    LSS,
    LEQ,
    GRE,
    GEQ,
    EQL,
    NEQ,
    ASSIGN,
    SEMICN,
    COMMA,
    LPARENT,
    RPARENT,
    LBRACK,
    RBRACK,
    LBRACE,
    RBRACE,
    COUNT,
    OUTRANGE,
};

const std::string TokenStrings[TokenEnum::COUNT] = {
    "EOFTK",   "SPACETK",  "ENTERTK",   "SINGLECMT", "MULTCMT",    "IDENFR", "INTCON", "STRCON", "CHRCON", "MAINTK",
    "CONSTTK", "INTTK",    "CHARTK",    "BREAKTK",   "CONTINUETK", "IFTK",   "ELSETK", "NOT",    "AND",    "OR",
    "FORTK",   "GETINTTK", "GETCHARTK", "PRINTFTK",  "RETURNTK",   "PLUS",   "MINU",   "VOIDTK", "MULT",   "DIV",
    "MOD",     "LSS",      "LEQ",       "GRE",       "GEQ",        "EQL",    "NEQ",    "ASSIGN", "SEMICN", "COMMA",
    "LPARENT", "RPARENT",  "LBRACK",    "RBRACK",    "LBRACE",     "RBRACE"};
enum ComponentEnum
{
    TokenConst,
    Ident,
    IntConst,
    CharConst,
    StringConst,

    CompUnit,
    MainFuncDef,
    Decl,
    ConstDecl,
    BType,
    ConstDef,
    ConstInitVal,
    VarDecl,
    VarDef,
    InitVal,
    FuncDef,
    FuncType,
    FuncFParams,
    FuncFParam,
    Block,
    BlockItem,
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
    ConstExp,
    C_COUNT
};

//Components
enum CompUnitEnum
{
    COMP_UNIT_ONE,
};

enum MainFuncDefEnum
{
    MAIN_FUNC_DEF_ONE,
};

enum DeclEnum
{
    DECL_CONST,
    DECL_VAR,
};

enum ConstDeclEnum
{
    CONST_DECL_ONE,
};

enum BTypeEnum
{
    BTYPE_INTF,
    BTYPE_CHARF,
};

enum ConstDefEnum
{
    CONST_DEF_ONE,
};

enum ConstInitValEnum
{
    CONST_INIT_EXP,
    CONST_INIT_EXPS,
    CONST_INIT_STR,
};

enum VarDeclEnum
{
    VAR_DECL_ONE,
};

enum VarDefEnum
{
    VAR_DEF_ONE,
};

enum InitValEnum
{
    INIT_VAL_EXP,
    INIT_VAL_EXPS,
    INIT_VAL_STR,
};

enum FuncDefEnum
{
    FUNC_DEF_ONE,
};

enum FuncTypeEnum
{
    FUNC_TYPE_VOIDF,
    FUNC_TYPE_INTF,
    FUNC_TYPE_CHARF,
};

enum FuncFParamsEnum
{
    FUNC_F_PARAMS_ONE,
};

enum FuncFParamEnum
{
    FUNC_F_PARAM_ONE,
};

enum BlockEnum
{
    BLOCK_ONE,
};

enum BlockItemEnum
{
    BLOCK_ITEM_DECL,
    BLOCK_ITEM_STMT,
};

enum StmtEnum
{
    STMT_LVAL_EXP,
    STMT_BLOCK,
    STMT_IFF,
    STMT_FORF,
    STMT_BREAKF,
    STMT_CONTINUEF,
    STMT_RETURNF,
    STMT_GETINT,
    STMT_GETCHAR,
    STMT_PRINTFF,
    STMT_EXP,
};

enum ForStmtEnum
{
    FOR_STMT_ONE,
};

enum ExpEnum
{
    EXP_ONE,
};

enum CondEnum
{
    COND_ONE,
};

enum LValEnum
{
    LVAL_ONE,
};

enum PrimaryExpEnum
{
    PRIMARY_EXP_EXP,
    PRIMARY_EXP_LVAL,
    PRIMARY_EXP_NUM,
    PRIMARY_EXP_CHARF,
};

enum NumberEnum
{
    NUMBER_ONE,
};

enum CharacterEnum
{
    CHARACTER_ONE,
};

enum UnaryExpEnum
{
    UNARY_EXP_IDENT,
    UNARY_EXP_PRI_EXP,
    UNARY_EXP_OP_EXP,
};

enum UnaryOpEnum
{
    UNARY_OP_ADD,
    UNARY_OP_SUB,
    UNARY_OP_NOT,
};

enum FuncRParamsEnum
{
    FUNC_R_PARAMS_ONE,
};

enum MulExpEnum
{
    MUL_EXP_ONE
};

enum AddExpEnum
{
    ADD_EXP_ONE
};

enum RelExpEnum
{
    REL_EXP_ONR
};

enum EqExpEnum
{
    EQ_EXP_ONE
};

enum LAndExpEnum
{
    LAND_ONE,
};

enum LOrExpEnum
{
    LOR_ONE,
};

enum ConstExpEnum
{
    CONST_EXP_ONE,
};
const std::string ComponentStrings[] = {
    "TokenConst", "Ident",       "IntConst",   "CharConst",    "StringConst", "CompUnit", "MainFuncDef", "Decl",
    "ConstDecl",  "BType",       "ConstDef",   "ConstInitVal", "VarDecl",     "VarDef",   "InitVal",     "FuncDef",
    "FuncType",   "FuncFParams", "FuncFParam", "Block",        "BlockItem",   "Stmt",     "ForStmt",     "Exp",
    "Cond",       "LVal",        "PrimaryExp", "Number",       "Character",   "UnaryExp", "UnaryOp",     "FuncRParams",
    "MulExp",     "AddExp",      "RelExp",     "EqExp",        "LAndExp",     "LOrExp",   "ConstExp"};
#endif
