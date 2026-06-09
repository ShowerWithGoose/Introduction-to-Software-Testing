#include <memory>
#include <utility>
#include <vector>
#include "Token.h"

#ifndef PARSER_H
#define PARSER_H

struct TreeNode {
    std::string value;  // 节点的值
    std::string type;
    bool isend; //标识是非是终结符
    std::vector<std::shared_ptr<TreeNode>> children;  // 子节点列表
    TreeNode* parent;
    bool banned;

    // 构造函数
    TreeNode(std::string type, bool v) : type(std::move(type)), isend(v), parent(nullptr), banned(false) {}
    TreeNode(std::string value, std::string type, bool v) : value(std::move(value)), type(std::move(type)), isend(v), parent(nullptr), banned(false) {}
    // 添加子节点的函数
    void addChild(std::shared_ptr<TreeNode> child) {
        child->parent = this;  // 设置子节点的父节点为当前节点
        children.push_back(child);
    }
    bool isLastChild() const {
        if (!parent) return false;  // 如果没有父节点，则不是任何节点的子节点
        if (parent->children.empty()) return false;
        return parent->children.back().get() == this;
    }
};

/*
enum ParserType
{
    CompUnit, Decl, ConstDecl, BType, Constdef, ConstInitVal,
    VarDecl, Vardef, InitVal, FuncDef, MainFuncDef, FuncType,
    FuncFParams, FuncFParam, Block, BlockItem, Stmt, ForStmt,
    Exp, Cond, LVal, PrimaryExp, Number, Character, UnaryOp,
    FuncRParams, MulExp, AddExp, RelExp, EqExp, LAndExp, LOrExp,
    ConstExp
};
*/
extern int parsingTime;

void traverseLeaves(const std::shared_ptr<TreeNode>& node, std::ofstream& output);

bool ConstExp(int i, const std::shared_ptr<TreeNode>& node);
bool LOrExp(int i, const std::shared_ptr<TreeNode>& node);
bool LAndExp(int i, const std::shared_ptr<TreeNode>& node);
bool EqExp(int i, const std::shared_ptr<TreeNode>& node);
bool RelExp(int i, const std::shared_ptr<TreeNode>& node);
bool AddExp(int i, const std::shared_ptr<TreeNode>& node);
bool MulExp(int i, const std::shared_ptr<TreeNode>& node);
bool FuncRParams(int i, const std::shared_ptr<TreeNode>& node);
bool UnaryOp(int i, const std::shared_ptr<TreeNode>& node);
bool UnaryExp(int i, const std::shared_ptr<TreeNode>& node);
bool Character(int i, const std::shared_ptr<TreeNode>& node);
bool Number(int i, const std::shared_ptr<TreeNode>& node);
bool PrimaryExp(int i, const std::shared_ptr<TreeNode>& node);
bool LVal(int i, const std::shared_ptr<TreeNode>& node);
bool Cond(int i, const std::shared_ptr<TreeNode>& node);
bool Exp(int i, const std::shared_ptr<TreeNode>& node);
bool ForStmt(int i, const std::shared_ptr<TreeNode>& node);
bool Stmt(int i, const std::shared_ptr<TreeNode>& node);
bool BlockItem(int i, const std::shared_ptr<TreeNode>& node);
bool Block(int i, const std::shared_ptr<TreeNode>& node);
bool FuncFParam(int i, const std::shared_ptr<TreeNode>& node);
bool FuncFParams(int i, const std::shared_ptr<TreeNode>& node);
bool FuncType(int i, const std::shared_ptr<TreeNode>& node);
bool MainFuncDef(int i, const std::shared_ptr<TreeNode>& node);
bool FuncDef(int i, const std::shared_ptr<TreeNode>& node);
bool InitVal(int i, const std::shared_ptr<TreeNode>& node);
bool VarDef(int i, const std::shared_ptr<TreeNode>& node);
bool VarDecl(int i, const std::shared_ptr<TreeNode>& node);
bool ConstInitVal(int i, const std::shared_ptr<TreeNode> &node);
bool ConstDef(int i, const std::shared_ptr<TreeNode> &node);
bool BType(int i, std::shared_ptr<TreeNode> &node);
bool ConstDecl(int i, std::shared_ptr<TreeNode> &node);
bool Decl(int i, std::shared_ptr<TreeNode> &node);
bool CompUnit(int i, std::shared_ptr<TreeNode> &node);
std::shared_ptr<TreeNode> parsing();

#endif //PARSER_H
