//
// Created by  on 2024/10/5.
//

#ifndef SYS_COMPILER_NODE_H
#define SYS_COMPILER_NODE_H

#include <vector>
#include "../Lexer/Token.h"

extern bool banOutput;

#define PARSER_DEBUG

// parser测试的print （打印node）
#ifdef PARSER_DEBUG
#define PARSER_PRINT(content) \
    do {                      \
        if (!content.empty() && !(banOutput && (content == "<ConstInitVal>" || content == "<InitVal>")))                      \
            parserFile << (content) << std::endl; \
    } while(0)
#else
#define PARSER_PRINT(node) \
    do { \
        \
    } while(0)
#endif

namespace frontend {

    class CompUnit;

    class Decl;

    class ConstDecl;

    class BType;

    class ConstDef;

    class ConstInitVal;

    class VarDecl;

    class VarDef;

    class InitVal;

    class FuncDef;

    class MainFuncDef;

    class FuncType;

    class FuncFParams;

    class FuncFParam;

    class Block;

    class BlockItem;

    class Stmt;

    class ForStmt;

    class Exp;

    class Cond;

    class LVal;

    class PrimaryExp;

    class Number;

    class Character;

    class UnaryExp;

    class UnaryOp;

    class FuncRParams;

    class MulExp;

    class AddExp;

    class RelExp;

    class EqExp;

    class LAndExp;

    class LOrExp;

    class ConstExp;


    class Node {
    public:
        enum class NodeType {
            CompUnit, Decl, ConstDecl, BType, ConstDef, ConstInitVal, VarDecl,
            VarDef, InitVal, FuncDef, MainFuncDef, FuncType, FuncFParams, FuncFParam,
            Block, BlockItem, Stmt, ForStmt, Exp, Cond, LVal, PrimaryExp, Number,
            Character, UnaryExp, UnaryOp, FuncRParams, MulExp, AddExp, RelExp,
            EqExp, LAndExp, LOrExp, ConstExp,
        };

    public:
        static std::unordered_map<Node *, bool> all_nodes;

        explicit Node(NodeType type);

        ~Node() { all_nodes[this] = true; }

    protected:
        std::vector<Node *> childNode;
        NodeType type;
    };


    class CompUnit : public Node {
    public:
        explicit CompUnit(const std::vector<Decl *> &decls, const std::vector<FuncDef *> &funcDefs,
                          MainFuncDef *mainFuncDef);

    private:
        std::vector<Decl *> decls;
        std::vector<FuncDef *> funcDefs;
        MainFuncDef *mainFuncDef;
    };


    class Decl : public Node {
    public:
        explicit Decl(ConstDecl *constDecl);

        explicit Decl(VarDecl *varDecl);

    private:
        ConstDecl *constDecl = nullptr;
        VarDecl *varDecl = nullptr;
    };


    class ConstDecl : public Node {
    public:
        explicit ConstDecl(BType *bType, const std::vector<ConstDef *> &constDefs);

    private:
        BType *bType;
        std::vector<ConstDef *> constDefs;
    };


    class BType : public Node {
    public:
        explicit BType(Token *token);

    private:
        Token *token;
    };


    class ConstDef : public Node {
    public:
        explicit ConstDef(Token *identToken, const std::vector<ConstExp *> &constExps, ConstInitVal *constInitVal);

    private:
        Token *identToken;
        std::vector<ConstExp *> constExps;
        ConstInitVal *constInitVal = nullptr;
        BType *btype = nullptr;
        // 记录数组的维数
        std::vector<int> dims;
    };


    class ConstInitVal : public Node {
    public:
        explicit ConstInitVal(ConstExp *constExp);

        explicit ConstInitVal(const std::vector<ConstInitVal *> &constInitVals);

        explicit ConstInitVal(Token *strConst);

    private:
        ConstExp *constExp = nullptr;
        std::vector<ConstInitVal *> constInitVals;
        Token *strConst = nullptr;
        std::vector<int> dims;
    };


    class VarDecl : public Node {
    public:
        explicit VarDecl(BType *bType, const std::vector<VarDef *> &varDefs);

    private:
        BType *bType = nullptr;
        std::vector<VarDef *> varDefs;
    };


    class VarDef : public Node {
    public:
        explicit VarDef(Token *identToken, const std::vector<ConstExp *> &constExps);

        explicit VarDef(Token *identToken, const std::vector<ConstExp *> &constExps, InitVal *initVal);

    private:
        Token *identToken;
        std::vector<ConstExp *> constExps;
        InitVal *initVal = nullptr;
        BType *btype = nullptr;
        std::vector<int> dims;
    };


    class InitVal : public Node {
    public:
        explicit InitVal(Exp *exp);

        explicit InitVal(const std::vector<InitVal *> &initVals);

        explicit InitVal(Token *strConst);

    private:
        Exp *exp = nullptr;
        std::vector<InitVal *> initVals;
        Token *strConst = nullptr;
        std::vector<int> dims;
    };


    class FuncDef : public Node {
    public:
        explicit FuncDef(FuncType *funcType, Token *identToken, FuncFParams *funcFParams, Block *block);

    private:
        FuncType *funcType = nullptr;
        Token *identToken;
        FuncFParams *funcFParams = nullptr;
        Block *block = nullptr;
    };


    class MainFuncDef : public Node {
    public:
        explicit MainFuncDef(Block *block);

    private:
        Block *block = nullptr;
    };


    class FuncType : public Node {
    public:
        explicit FuncType(Token *token);

    private:
        Token *token;
    };


    class FuncFParams : public Node {
    public:
        explicit FuncFParams(const std::vector<FuncFParam *> &funcFParamList);

    private:
        std::vector<FuncFParam *> funcFParamList;
    };


    class FuncFParam : public Node {
    public:
        explicit FuncFParam(BType *bType, Token *identToken, Token *lbrack, Token *rblack,
                            const std::vector<ConstExp *> &constExps);

    private:
        BType *bType = nullptr;
        Token *identToken;
        std::vector<ConstExp *> constExps;
        Token *lbrack;  // 判断是否是数组传参
        Token *rblack;
    };


    class Block : public Node {
    public:
        explicit Block(const std::vector<BlockItem *> &blockItems);

    private:
        std::vector<BlockItem *> blockItems;
    };


    class BlockItem : public Node {
    public:
        explicit BlockItem(Decl *decl);

        explicit BlockItem(Stmt *stmt);

    private:
        Decl *decl = nullptr;
        Stmt *stmt = nullptr;
    };


    class Stmt : public Node {
    public:
        enum class StmtType {
            // 对于 getint 和 getchar 直接当作函数调用
            // 由于 printf 多参数，所以单独处理
            ExpStmt, AssignStmt, BlockStmt, ConditionStmt,
            ForStmt, ReturnStmt, ControlStmt, PrintfStmt, GetintStmt,
            GetcharStmt, None,
        };
    public:
        // getint | getchar
        explicit Stmt(StmtType type, LVal *lVal);

        // LVal '=' Exp ';' | return Exp ';'
        explicit Stmt(LVal *lVal, Exp *exp);

        // [Exp] ';'
        explicit Stmt(Exp *exp);

        // Block
        explicit Stmt(Block *block);

        // 'if' '( Cond ')' Stmt [ 'else' Stmt ]
        explicit Stmt(Cond *cond, Stmt *stmt1, Stmt *stmt2);

        // 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
        explicit Stmt(ForStmt *init, Cond *cond, ForStmt *iter, Stmt *stmt);

        // continue break
        explicit Stmt(StmtType type, Token *conBreakTK);

        // return
        explicit Stmt(StmtType type, Exp *exp);

        // printf
        explicit Stmt(Token *formatStr, const std::vector<Exp *> &formatParams);


    private:
        StmtType stmtType;
        Exp *exp = nullptr;
        LVal *lVal = nullptr;
        Block *block = nullptr;
        Cond *cond = nullptr;
        Stmt *stmt1 = nullptr;
        Stmt *stmt2 = nullptr;
        Stmt *stmt = nullptr;
        ForStmt *init = nullptr;
        ForStmt *iter = nullptr;
        Token *conBreakTK = nullptr;  // continue | break
        Token *formatStr = nullptr;  // 格式化字符串
        std::vector<Exp *> formatParams;  // 格式化字符串参数
    };


    class ForStmt : public Node {
    public:
        explicit ForStmt(LVal *lVal, Exp *exp);

    private:
        LVal *lVal = nullptr;
        Exp *exp = nullptr;
    };


    class Exp : public Node {
    public:
        explicit Exp(AddExp *addExp);

    private:
        AddExp *addExp = nullptr;
    };


    class Cond : public Node {
    public:
        explicit Cond(LOrExp *lOrExp);

    private:
        LOrExp *lOrExp = nullptr;
    };


    class LVal : public Node {
    public:
        explicit LVal(Token *identToken, const std::vector<Exp *> &exps);

    private:
        Token *identToken;
        std::vector<Exp *> exps;
    };


    class PrimaryExp : public Node {
    public:
        explicit PrimaryExp(Exp *exp);

        explicit PrimaryExp(LVal *lVal);

        explicit PrimaryExp(Number *number);

        explicit PrimaryExp(Character *character);

    private:
        Exp *exp = nullptr;
        LVal *lVal = nullptr;
        Number *number = nullptr;
        Character *character = nullptr;
    };


    class Number : public Node {
    public:
        explicit Number(Token *token);

    private:
        Token *token;
    };


    class Character : public Node {
    public:
        explicit Character(Token *token);

    private:
        Token *token;
    };


    class UnaryExp : public Node {
    public:
        explicit UnaryExp(PrimaryExp *primaryExp);

        explicit UnaryExp(Token *identToken, FuncRParams *funcRParams);

        explicit UnaryExp(UnaryOp *unaryOp, UnaryExp *unaryExp);

    private:
        PrimaryExp *primaryExp = nullptr;
        Token *identToken = nullptr;
        FuncRParams *funcRParams = nullptr;
        UnaryOp *unaryOp = nullptr;
        UnaryExp *unaryExp = nullptr;
    };


    class UnaryOp : public Node {
    public:
        explicit UnaryOp(Token *token);

    private:
        Token *token = nullptr;
    };


    class FuncRParams : public Node {
    public:
        explicit FuncRParams(const std::vector<Exp *> &exps);

    private:
        std::vector<Exp *> exps;
    };

    class MulExp : public Node {
    public:
        explicit MulExp(UnaryExp *unaryExp);

        explicit MulExp(MulExp *mulExp, Token *op, UnaryExp *unaryExp);

    private:
        UnaryExp *unaryExp = nullptr;
        MulExp *mulExp = nullptr;
        Token *op = nullptr;
    };


    class AddExp : public Node {
    public:
        explicit AddExp(MulExp *mulExp, Token *op, AddExp *addExp);

        explicit AddExp(MulExp *mulExp);

    private:
        MulExp *mulExp = nullptr;
        AddExp *addExp = nullptr;
        Token *op = nullptr;
    };


    class RelExp : public Node {
    public:
        explicit RelExp(AddExp *addExp);

        explicit RelExp(RelExp *relExp, Token *op, AddExp *addExp);

    private:
        AddExp *addExp = nullptr;
        RelExp *relExp = nullptr;
        Token *op = nullptr;
    };


    class EqExp : public Node {
    public:
        explicit EqExp(RelExp *relExp);

        explicit EqExp(EqExp *eqExp, Token *op, RelExp *relExp);

    private:
        RelExp *relExp = nullptr;
        EqExp *eqExp = nullptr;
        Token *op = nullptr;
    };


    class LAndExp : public Node {
    public:
        explicit LAndExp(EqExp *eqExp);

        explicit LAndExp(LAndExp *lAndExp, Token *op, EqExp *eqExp);

    private:
        EqExp *eqExp = nullptr;
        LAndExp *lAndExp = nullptr;
        Token *op = nullptr;
    };


    class LOrExp : public Node {
    public:
        explicit LOrExp(LAndExp *lAndExp);

        explicit LOrExp(LOrExp *lOrExp, Token *op, LAndExp *lAndExp);

    private:
        LAndExp *lAndExp = nullptr;
        LOrExp *lOrExp = nullptr;
        Token *op = nullptr;
    };


    class ConstExp : public Node {
    public:
        explicit ConstExp(AddExp *addExp);

    private:
        AddExp *addExp = nullptr;
    };
} // frontend

#endif //SYS_COMPILER_NODE_H
