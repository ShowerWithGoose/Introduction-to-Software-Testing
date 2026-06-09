#ifndef COMPILER_PARSER_H
#define COMPILER_PARSER_H

#include<string>
#include<utility>
#include<vector>

#define pair std::pair
#define string std::string
#define vector std::vector

struct CompUnit;
struct ConstDecl;
struct ConstDef;
struct ConstInitVal;
struct VarDecl;
struct VarDef;
struct InitVal;
struct FuncDef;
struct FuncFParams;
struct FuncFParam;
struct Block;
struct BlockItem;
struct Stmt;
struct ForStmt;
struct Exp;
struct Cond;
struct LVal;
struct PrimaryExp;
struct UnaryExp;
struct FuncRParams;
struct MulExp;
struct AddExp;
struct RelExp;
struct EqExp;
struct LAndExp;


enum{
    TYPE_VOID,TYPE_INT,TYPE_CHAR
};
enum{
    INITVAL_EXP,INITVAL_MULTI_EXP,INITVAL_STRINGCONST
};
enum{
    ADDOP_ADD,ADDOP_SUB,ADDOP_NOT
};
enum{
    MULOP_MUL,MULOP_DIV,MULOP_MOD
};
enum{
    RELOP_LSS,RELOP_GRE,RELOP_LEQ,RELOP_GEQ
};
enum{
    EQOP_EQL,EQOP_NEQ
};

struct ConstInitVal{
    int type;
    union{
        Exp *constExp;
        vector<Exp> *constExps;
    };
};

struct ConstDef{
    int line;
    string ident;
    Exp *constExp;
    ConstInitVal constInitVal;
};

struct ConstDecl{
    int bType;
    vector<ConstDef>constDefs;
};

struct InitVal{
    int type;
    union{
        Exp *exp;
        vector<Exp> *exps;
    };
};

struct VarDef{
    int line;
    string ident;
    Exp *constExp;
    InitVal *initVal;
};

struct VarDecl{
    int bType;
    vector<VarDef>varDefs;
};

struct FuncFParam{
    int line;
    int bType;
    string ident;
    bool isArray;
};

struct FuncFParams{
    vector<FuncFParam>funcFParams;
};

enum{
    ITEM_CONST_DECL,ITEM_VAR_DECL,ITEM_STMT
};
struct BlockItem{
    int type;
    union{
        ConstDecl *constDecl;
        VarDecl *varDecl;
        Stmt *stmt;
    };
};

struct Block{
    vector<BlockItem>blockItems;
};

struct FuncDef{
    int bLine,gLine;
    int bType;
    string ident;
    FuncFParams *funcFParams;
    Block block;
};

struct CompUnit{
    vector<BlockItem>decls;
    vector<FuncDef>funcDefs;
    FuncDef mainFuncDef;
};

enum{
    EXP_NORMAL,EXP_CONST,EXP_STRINGCONST
};
struct Exp{
    int type;
    union{
        AddExp *addExp;
        string *stringConst;
    };
};

struct LVal{
    int line;
    string ident;
    Exp *exp;
};

enum{
    PEXP_EXP,PEXP_LVAL,PEXP_INT,PEXP_CHAR
};
struct PrimaryExp{
    int type;
    union{
        Exp *exp;
        LVal *lVal;
        int num;
        char ch;
    };
};

enum{
    UNEXP_PEXP,UNEXP_FUNC
};
struct UnaryExp{
    int type;
    vector<int>unaryOps;
    union{
        PrimaryExp *primaryExp;
        struct{
            int line;
            string *ident;
            FuncRParams *funcRParams;
        };
    };
};

struct FuncRParams{
    vector<Exp>exps;
};

struct MulExp{
    vector<pair<int,UnaryExp> >unaryExps;
};

struct AddExp{
    vector<pair<int,MulExp> >mulExps;
};

struct RelExp{
    vector<pair<int,AddExp> >addExps;
};

struct EqExp{
    vector<pair<int,RelExp> >relExps;
};

struct LAndExp{
    vector<EqExp>eqExps;
};

struct Cond{
    vector<LAndExp>lAndExps;
};

enum{
    STMT_LVAL_EXP,STMT_EXP,STMT_BLOCK,
    STMT_IF,STMT_FOR,STMT_BREAK,STMT_CONTINUE,STMT_RETURN
};
struct Stmt{
    int line,type;
    union{
        struct{
            LVal *lVal;
            Exp *exp;
        }t_lVal_exp;
        Exp *exp;
        Block *block;
        struct{
            Cond *cond;
            Stmt *stmt1;
            Stmt *stmt2;
        }t_if;
        struct{
            ForStmt *forStmt1;
            Cond *cond;
            ForStmt *forStmt2;
            Stmt *stmt;
        }t_for;
    };
};

struct ForStmt{
    int line;
    LVal lVal;
    Exp exp;
};

extern CompUnit root;

bool printRoot(const char *fn);
void parseWords();

#undef pair
#undef string
#undef vector

#endif
