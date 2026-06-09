#ifndef PARSER_H
#define PARSER_H

struct NODE
{
    TOKEN endToken;
    int isEnd;
    vector<int> son;
};

//output
void print_tree(int now);

// 编译单元
void CompUnit(int father);

// 声明
void Decl(int father);

// 常量声明
void ConstDecl(int father);

// 基本类型
void BType(int father);

// 常量定义
void ConstDef(int father);

// 常量初值
void ConstInitVal(int father);

// 变量声明
void VarDecl(int father);

// 变量定义
void VarDef(int father);

// 变量初值
void InitVal(int father);

// 函数定义
void FuncDef(int father);

// 主函数定义
void MainFuncDef(int father);

// 函数类型
void FuncType(int father);

// 函数形参表
void FuncFParams(int father);

// 函数形参
void FuncFParam(int father);

// 语句块
void Block(int father);

// 语句块项
void BlockItem(int father);

// 语句
void Stmt(int father);

// 语句 ForStmt
void ForStmt(int father);

// 表达式 Exp
void Exp(int father);

// 条件表达式 Cond
void Cond(int father);

// 左值表达式 LVal
void LVal(int father);

// 基本表达式 PrimaryExp(int father);
void PrimaryExp(int father);

// 数值 Number
void Number(int father);

// 字符 Character
void Character(int father);

// 一元表达式 UnaryExp
void UnaryExp(int father);

// 单目运算符 UnaryOp
void UnaryOp(int father);

// 函数实参表 FuncRParams
void FuncRParams(int father);

// 乘除模表达式 MulExp
void MulExp(int father);

// 加减表达式 AddExp
void AddExp(int father);

// 关系表达式 RelExp
void RelExp(int father);

// 相等性表达式 EqExp
void EqExp(int father);

// 逻辑与表达式 LAndExp
void LAndExp(int father);

// 逻辑或表达式 LOrExp
void LOrExp(int father);

// 常量表达式 ConstExp
void ConstExp(int father);

#endif // PARSER_H