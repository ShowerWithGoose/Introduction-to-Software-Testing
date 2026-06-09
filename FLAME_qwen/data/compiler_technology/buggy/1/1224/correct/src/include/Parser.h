#ifndef _PARSER_H_
#define _PARSER_H_
#include "Type.h"
#include <string>
typedef struct Node
{
    PARSER_TYPE type;
    int index;
    int child;
    int fellow;
} Node, *Nodep;

void AddChildNode(Nodep, PARSER_TYPE, int);
void ChangeFellow(Nodep, int, PARSER_TYPE);
void AddNull(Nodep);

void TreeToString();

void PrintNode(Nodep);
void NodeToString(Nodep);
void BuildTree();

void CompUnit(Nodep father);
void Decl(Nodep father);
void ConstDecl(Nodep father);
void BType(Nodep father);
void ConstDef(Nodep father);
void ConstInitVal(Nodep father);
void VarDecl(Nodep father);
void VarDef(Nodep father);
void InitVal(Nodep father);
void FuncDef(Nodep father);
void MainFuncDef(Nodep father);
void FuncType(Nodep father);
void FuncFParams(Nodep father);
void FuncFParam(Nodep father);
void Block(Nodep father);
void BlockItem(Nodep father);
void Stmt(Nodep father);
void ForStmt(Nodep father);
void Exp(Nodep father);
void Cond(Nodep father);
void LVal(Nodep father);
void PrimaryExp(Nodep father);
void Number(Nodep father);
void Character(Nodep father);
void UnaryExp(Nodep father);
void UnaryOp(Nodep father);
void FuncRParams(Nodep father);
void MulExp(Nodep father);
void AddExp(Nodep father);
void RelExp(Nodep father);
void EqExp(Nodep father);
void LAndExp(Nodep father);
void LOrExp(Nodep father);
void ConstExp(Nodep father);
void ENDPARSE(Nodep father);

#endif