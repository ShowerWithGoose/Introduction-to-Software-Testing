#ifndef SYMBOL_H
#define SYMBOL_H

#include <bits/stdc++.h>
using namespace std;

class Symbol{
public:
    int depth;
    string name;
    string type;
    int isFunc;
public:
    virtual ~Symbol() {}
    Symbol(int d, const string& n, const string& t, int isF) ;
    
};
class WordSymbol : public Symbol{
public:
    int con;		// 0 -> var, 1 -> const 
    int dimension;   //0 -> val, 1 -> array
    public:
    WordSymbol(int d, const string& n, const string& t, int c, int dim);
};
class FuncSymbol : public Symbol{
public:
    vector<WordSymbol*> params;
public:
    FuncSymbol(int d, const string& n, const string& t);
};

struct SymbolTable{
    int depthId;
    vector<Symbol*> symbol;
};

void print_symbol();

Symbol* contains(int curId,string name);
void CompUnitError();
void ConstDeclError(NODE curNode);
void ConstDefError(NODE curNode,string type);
void ConstInitValError(NODE curNode);
void VarDeclError(NODE curNode);
void VarDefError(NODE curNode,string type);
void InitValError(NODE curNode);
void FuncDefError(NODE curNode);
void FuncFParamError(NODE curNode, FuncSymbol* curSymbol);
void MainFuncDefError(NODE curNode);
void BlockError(NODE curNode,int checkReturn);
void StmtError(NODE curNode,int checkReturn);
void ForStmtError(NODE curNode);
int ExpError(NODE curNode);
int LValError(NODE curNode,int checkAssign);
int PrimaryExpError(NODE curNode);
int UnaryExpError(NODE curNode);
void FuncRParamsError(NODE curNode, FuncSymbol* funcsymbol,int line);
int MulExpError(NODE curNode);
int AddExpError(NODE curNode);
void ConstExpError(NODE curNode);

#endif
