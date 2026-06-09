//
// Created by  on 2024-10-12.
//

#ifndef COMPILER_MAIN_H
#define COMPILER_MAIN_H

#define MAX_TOKEN_LENGTH 100
#define MAX_LINE_LENGTH 200
struct Exp;
struct Stmt;
struct Block;

// 节点基类
typedef struct Node {
    int lineno; // 行号
} Node;
// 数值节点
typedef struct Number {
    Node node; // 基类
    int value; // 数值
} Number;

// 字符节点
typedef struct Character {
    Node node; // 基类
    char value; // 字符
} Character;

// 左值节点
typedef struct LVal {
    Node node; // 基类
    char ident[100]; // 标识符
    int isarray;
    struct Exp * exp; // 索引（可选）
} LVal;
// 二元表达式节点
typedef struct BinaryExp {
    Node node; // 基类
    enum {
        MUL,
        ADD,
        REL,
        EQ,
        LAND,
        LOR
    }type;
    union {
        struct Exp *lhs; // 左操作数
        struct Exp *rhs; // 右操作数
        char op[3]; //操作符
    } data; // 存储具体表达式的数据
} BinaryExp;
//基本表达式节点
typedef struct PrimaryExp {
    Node node;
    enum {
        PARENTHESIS, // '(' Exp ')'
        LVAL, // 左值表达式 LVal
        NUMBER, // 数值 Number
        CHAR // 字符 Character
    } kind; // 表示基本表达式的类型
    union {
        struct Exp *exp; // 括号中的表达式
        LVal *lval; // 左值表达式
        Number number;// 数值常量
        Character character; // 字符常量
    } data;
}PrimaryExp;
//一元表达式节点
typedef struct UnaryExp {
    Node node;
    enum {
        PRIMARY,  // PrimaryExp
        FUNC_CALL, // Ident '(' [FuncRParams] ')'
        OP // UnaryOp UnaryExp
    } kind; // 表示一元表达式的类型
    union {
        struct Exp *primary; // 基本表达式
        struct {
            char ident[100]; // 函数名
            struct Exp **func_params; // 函数参数列表
            int param_count; // 参数数量
        } func_call;

        struct {
            char op; // 单目运算符 '+' | '−' | '!'
            struct Exp *unary_exp; // 递归的一元表达式
        } unary_op;
    } data;
} UnaryExp;

// 表达式节点
typedef struct Exp {
    Node node; // 基类
    enum{
        BINARY,
        UNARY,
        PRI
    }type;
    union {
       BinaryExp binaryExp;
       UnaryExp unaryExp;
        PrimaryExp primaryExp;
    } data; // 存储具体表达式的数据
} Exp;


// 赋值语句节点
typedef struct AssignStmt {
    Node node; // 基类
    LVal *lval; // 左值
    Exp *exp; // 表达式
} AssignStmt;

// 条件语句节点
typedef struct IfStmt {
    Node node; // 基类
    Exp *condition; // 条件（LOrExp）
    struct Stmt *then_stmt; // 语句
    int have_else;
    struct Stmt *else_stmt; // 可选的else语句
} IfStmt;

// 循环控制语句
typedef struct for_stmt{
    Node node;
    LVal *lVal;
    Exp *exp;
}For_stmt;
// 循环控制语句节点
typedef struct ForStmt {
    Node node; // 基类
    int have_forStmt1;
    int have_cond;
    int have_forStmt2;
    For_stmt *forStmt1; // 循环控制变量
    Exp *cond; // 循环条件（LOrExp）
    For_stmt *forStmt2; // 更新表达式
    struct Stmt *stmt;// 循环体
} ForStmt;

// 返回语句节点
typedef struct ReturnStmt {
    Node node; // 基类
    int have_exp;
    Exp *exp; // 可选的表达式
} ReturnStmt;

// printf语句节点
typedef struct PrintfStmt {
    Node node; // 基类
    char string_const[256]; // 字符串常量
    Exp **args; // 参数列表（可变数量）
    int arg_count; // 参数数量
} PrintfStmt;

//get语句节点
typedef struct GetStmt{
    Node node;
    LVal *lVal;
    enum{
        GETINT,
        GETCHAR
    }type;
}GetStmt;

// 常量初值节点
typedef struct InitVal {
    Node node; // 基类
    Exp ** exps;
    int exp_num;
    int isstring; //是否是字符串
    char string[100];
} InitVal;
// 常量定义节点
typedef struct ConstDef {
    Node node; // 基类
    char ident[100]; // 标识符
    int isarray; // 是否是数组
    Exp * exp;
    InitVal *init_val; // 初始化值
} ConstDef;
// 常量声明节点
typedef struct ConstDecl {
    Node node; // 基类
    char btype[20]; // 类型
    ConstDef **const_defs; // 常量定义数组
    int const_count; // 常量定义数量
} ConstDecl;
// 变量定义节点
typedef struct VarDef {
    Node node; // 基类
    char ident[100]; // 标识符
    int isarray; // 是否是数组
    Exp * exp;
    int have_init; //是否已经初始化
    InitVal *init_val; // 初始化值
} VarDef;
// 变量声明节点
typedef struct VarDecl {
    Node node; // 基类
    char btype[20];  // 类型
    VarDef **var_defs;
    int var_count;
} VarDecl;

// 语句的联合体
typedef struct Stmt {
    Node node; // 基类
    enum {
        ASSIGN,
        EXP,
        BLOCK,
        IF,
        FOR,
        BREAK,
        CONTINUE,
        RETURN,
        PRINT,
        GET
    } type; // 语句类型
    union {
        AssignStmt *assign_stmt;
        Exp *exp;
        struct Block *block;
        IfStmt *if_stmt;
        ForStmt *for_stmt;
        ReturnStmt *return_stmt;
        PrintfStmt *printf_stmt;
        GetStmt *getStmt;
    } data; // 存储具体语句的数据
} Stmt;

typedef struct Decl {
    Node node; // 基类
    enum {
        CONSTDECL,
        VARDECL
    } type; // 语句类型
    union {
        ConstDecl const_decl;
        VarDecl var_decl;
    } data; // 存储具体语句的数据
} Decl;

typedef struct BlockItem{
    Node node;
    enum{
        DECL,
        STMT
    }type;
    union{
        Decl *decl;
        Stmt *stmt;
    }data;
}BlockItem;

// 函数参数节点
typedef struct FuncFParam {
    Node node;
    char btype[20]; // 参数类型
    char ident[100]; // 参数名
    int isarray;
} FuncFParam;

//语句块节点
typedef struct Block{
    Node node;
    struct BlockItem **blockItems;
    int blockitem_num;
}Block;
// 函数定义节点
typedef struct FuncDef {
    Node node;
    char ftype[20]; // 函数类型
    char ident[100]; // 函数名
    struct FuncFParam **params; // 函数参数
    int param_num;//参数个数
    struct Block *block; // 函数体
} FuncDef;



// 主函数定义节点
typedef struct MainFuncDef {
    Node node;
    struct Block *block; // 函数体
} MainFuncDef;



// 语法树根节点
typedef struct CompUnit {
    Node node; // 基类
    struct MainFuncDef *mainFuncDef;
    struct Decl **decls;
    int decl_count;
    struct FuncDef ** funcs;
    int func_count;
} CompUnit;

//typedef enum {
//    INTTK, MAINTK, IDENFR, PRINTFTK, RETURNTK, GETINTTK, STRCON,
//    LPARENT, RPARENT, LBRACE, RBRACE, SEMICN, COMMA, ASSIGN,
//    // 增加其他符号和关键字
//    ERROR
//} TokenType;


// 语法分析函数声明
CompUnit * parseProgram();
ConstDef *parseConstDef(int isstring);
VarDef *parseVarDef(int isstring);
InitVal *parseInitVal(int isstring,int isconst);
Decl *parseVarDecl();
Decl * parseConstDecl();

Exp * parseExp(int isconst);
Exp *parsePrimaryExp();
Exp *parseAddExp();
Exp * parseMulExp();
Exp * parseUnaryExp();
Exp *parseRelExp();
Exp *parseEqExp();
Exp *parseLAndExp();
Exp *parseLOrExp();

FuncDef *parseFuncDef();
FuncFParam *parseFuncParam();
MainFuncDef *parseMainFuncDef();
Block *parseBlock();

LVal *parseLVal();

Stmt *parseStmt();
IfStmt *parseIfStmt();
ForStmt *parseForStmt();
ReturnStmt *parseReturnStmt();
PrintfStmt *parsePrintfStmt();
For_stmt *parsegetForStmt();
#endif //COMPILER_MAIN_H
