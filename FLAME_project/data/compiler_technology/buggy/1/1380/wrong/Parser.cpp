#include <bits/stdc++.h>
#include "utils.h"
#include "type.h"
#include "parser.h"

using namespace std;

void write(string fileName, string content)
{
    // 打开文件以写入
    ofstream outfile(fileName, std::ios::app);

    // 检查文件是否成功打开

    // 将字符数组写入文件
    outfile << content;
    // 关闭文件
    outfile.close();
}

NODE node[100000];
int node_cnt;

void print_tree(int now)
{
    for (int i = 0; i < node[now].son.size(); i++){
        print_tree(node[now].son[i]);
        if (node[now].isEnd)
            write("parser.txt", node[now].endToken.sym + " " + node[now].endToken.ori + "\n");
        else
            write("parser.txt", node[now].endToken.sym + "\n");
    }
}

extern map<string, string> idenp;
extern TOKEN token_ans[100086];
extern char *now;
int token_cnt = 1;
void next_token() { token_cnt++; }

// 编译单元 CompUnit → {Decl} {FuncDef} MainFuncDef
void CompUnit(int father)
{
    ++node_cnt;
    node[node_cnt].endToken.sym = "<CompUnit>";
    int rt = node_cnt;
    node[father].son.push_back(rt);

    while (token_ans[token_cnt + 1].sym != "MAINTK")
    {
        if (token_ans[token_cnt].sym == "CONSTTK")
            Decl(rt);
        else
        {
            if (token_ans[token_cnt + 2].sym == "LPARENT")
                FuncDef(rt);
            else
                Decl(rt);
        }
    }

    MainFuncDef(rt);
}

// 声明 Decl → ConstDecl | VarDecl
void Decl(int father)
{
    /*++node_cnt;
    node[node_cnt].endToken.sym="<Decl>";
    int rt=node_cnt;
    node[father].son.push_back(rt);*/
    int rt = father;

    if (token_ans[token_cnt].sym == "CONSTTK")
    {
        ConstDecl(rt);
    }
    else
    {
        VarDecl(rt);
    }
}

// 常量声明 ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';' // i
void ConstDecl(int father)
{
    ++node_cnt;
    node[node_cnt].endToken.sym = "<ConstDecl>";
    int rt = node_cnt;
    node[father].son.push_back(rt);

    node[++node_cnt] = {token_ans[token_cnt], 1};
    node[rt].son.push_back(node_cnt);
    next_token();

    BType(rt);

    ConstDef(rt);

    while(token_ans[token_cnt].sym == "COMMA"){
        node[++node_cnt] = {token_ans[token_cnt], 1};
        node[rt].son.push_back(node_cnt);
        next_token();

        ConstDef(rt);
    }
    if (token_ans[token_cnt].sym != "SEMICN"){
        error(token_ans[token_cnt-1].line, "i");
        //cout<<"consterror"<<endl;
        node[++node_cnt] .endToken.sym = "SEMICN";   //补齐
        node[rt].son.push_back(node_cnt);
    }
    else{
        node[++node_cnt] = {token_ans[token_cnt], 1};
        node[rt].son.push_back(node_cnt);
        next_token();
    }
}

// 基本类型 BType → 'int' | 'char'
void BType(int father)
{
    /*++node_cnt;
    node[node_cnt].endToken.sym="<BType>";
    int rt=node_cnt;
    node[father].son.push_back(rt);*/
    int rt = father;
    // int | char
    node[++node_cnt] = {token_ans[token_cnt], 1};
    node[rt].son.push_back(node_cnt);
    next_token();
}
// 常量定义 ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal // k
void ConstDef(int father)
{
    ++node_cnt;
    node[node_cnt].endToken.sym = "<ConstDef>";
    int rt = node_cnt;
    node[father].son.push_back(rt);

    // Ident
    node[++node_cnt] = {token_ans[token_cnt], 1};
    node[rt].son.push_back(node_cnt);
    next_token();
    //'['
    if (token_ans[token_cnt].sym == "LBRACK")
    {
        node[++node_cnt] = {token_ans[token_cnt], 1};
        node[rt].son.push_back(node_cnt);
        next_token();

        ConstExp(rt);

        //']'
        if (token_ans[token_cnt].sym != "RBRACK")
        {
            error(token_ans[token_cnt-1].line, "k");
            node[++node_cnt] .endToken.sym = "RBRACK";   //补齐
            node[rt].son.push_back(node_cnt);
        }else{
            node[++node_cnt] = {token_ans[token_cnt], 1};
            node[rt].son.push_back(node_cnt);
            next_token();
        }
    }
    //=
    node[++node_cnt] = {token_ans[token_cnt], 1};
    node[rt].son.push_back(node_cnt);
    next_token();

    ConstInitVal(rt);
}

// 常量初值 ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
void ConstInitVal(int father)
{
    ++node_cnt;
    node[node_cnt].endToken.sym = "<ConstInitVal>";
    int rt = node_cnt;
    node[father].son.push_back(rt);

    if (token_ans[token_cnt].sym == "STRCON")
    {
        node[++node_cnt] = {token_ans[token_cnt], 1};
        node[rt].son.push_back(node_cnt);
        next_token();
    }
    else if (token_ans[token_cnt].sym == "LBRACE")
    {
        node[++node_cnt] = {token_ans[token_cnt], 1};
        node[rt].son.push_back(node_cnt);
        next_token();

        if (token_ans[token_cnt].sym != "RBRACE")
        {
            ConstExp(rt);
            while (token_ans[token_cnt].sym == "COMMA")
            {
                node[++node_cnt] = {token_ans[token_cnt], 1};
                node[rt].son.push_back(node_cnt);
                next_token();
                ConstExp(rt);
            }
        }
        node[++node_cnt] = {token_ans[token_cnt], 1};
        node[rt].son.push_back(node_cnt);
        next_token();
    }
    else
    {
        ConstExp(rt);
    }
}
// 变量声明 VarDecl → BType VarDef { ',' VarDef } ';' // i
void VarDecl(int father)
{
    ++node_cnt;
    node[node_cnt].endToken.sym = "<VarDecl>";
    int rt = node_cnt;
    node[father].son.push_back(rt);

    BType(rt); // 假设已定义 BType 解析程序

    VarDef(rt);
    while (token_ans[token_cnt].sym == "COMMA")
    {
        node[++node_cnt] = {token_ans[token_cnt], 1};
        node[rt].son.push_back(node_cnt);
        next_token();
        VarDef(rt);
    }

    if (token_ans[token_cnt].sym != "SEMICN")
    {
        error(token_ans[token_cnt-1].line, "i");
        //cout<<"varerror"<<endl;
        node[++node_cnt] .endToken.sym = "SEMICN";   //补齐
        node[rt].son.push_back(node_cnt);
    }else{
        node[++node_cnt] = {token_ans[token_cnt], 1};
        node[rt].son.push_back(node_cnt);
        next_token();
    }
}
// 变量定义 VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal // k
void VarDef(int father)
{
    ++node_cnt;
    node[node_cnt].endToken.sym = "<VarDef>";
    int rt = node_cnt;
    node[father].son.push_back(rt);

    //Ident
    node[++node_cnt] = {token_ans[token_cnt], 1};
    node[rt].son.push_back(node_cnt);
    next_token();

    if (token_ans[token_cnt].sym == "LBRACK")
    {
        node[++node_cnt] = {token_ans[token_cnt], 1};
        node[rt].son.push_back(node_cnt);
        next_token();

        ConstExp(rt);

        if (token_ans[token_cnt].sym != "RBRACK")
        {
            error(token_ans[token_cnt-1].line, "k");
            node[++node_cnt] .endToken.sym = "RBRACK";   //补齐
            node[rt].son.push_back(node_cnt);
        }else{
            node[++node_cnt] = {token_ans[token_cnt], 1};
            node[rt].son.push_back(node_cnt);
            next_token();
        }
    }

    if (token_ans[token_cnt].sym == "ASSIGN")
    {
        node[++node_cnt] = {token_ans[token_cnt], 1};
        node[rt].son.push_back(node_cnt);
        next_token();
        InitVal(rt);
    }
}

// 变量初值 InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
void InitVal(int father)
{
    ++node_cnt;
    node[node_cnt].endToken.sym = "<InitVal>";
    int rt = node_cnt;
    node[father].son.push_back(rt);
    if (token_ans[token_cnt].sym == "STRCON")
    {
        node[++node_cnt] = {token_ans[token_cnt], 1};
        node[rt].son.push_back(node_cnt);
        next_token();
    }
    else if (token_ans[token_cnt].sym == "LBRACE")
    {
        node[++node_cnt] = {token_ans[token_cnt], 1};
        node[rt].son.push_back(node_cnt);
        next_token();

        if (token_ans[token_cnt].sym != "RBRACE")
        {
            Exp(rt);
            while (token_ans[token_cnt].sym == "COMMA")
            {
                node[++node_cnt] = {token_ans[token_cnt], 1};
                node[rt].son.push_back(node_cnt);
                next_token();
                Exp(rt);
            }
        }

        //RBrace
        node[++node_cnt] = {token_ans[token_cnt], 1};
        node[rt].son.push_back(node_cnt);
        next_token();
    }
    else
    {
        Exp(rt);
    }
}

// 函数定义 FuncDef → FuncType Ident '(' [FuncFParams] ')' Block // j
void FuncDef(int father)
{
    ++node_cnt;
    node[node_cnt].endToken.sym = "<FuncDef>";
    int rt = node_cnt;
    node[father].son.push_back(rt);

    FuncType(rt); // 假设已定义 FuncType 解析程序

    //Ident
    node[++node_cnt] = {token_ans[token_cnt], 1};
    node[rt].son.push_back(node_cnt);
    next_token();

    //(
    node[++node_cnt] = {token_ans[token_cnt], 1};
    node[rt].son.push_back(node_cnt);
    next_token();

    if (token_ans[token_cnt].sym != "RPARENT")
    {
        if (token_ans[token_cnt].sym == "INTTK" || token_ans[token_cnt].sym == "CHARTK")
            FuncFParams(rt);
    }

    if (token_ans[token_cnt].sym != "RPARENT")
    {
        error(token_ans[token_cnt-1].line, "j");
        node[++node_cnt] .endToken.sym = "RPARENT";   //补齐
        node[rt].son.push_back(node_cnt);
    }else{
        node[++node_cnt] = {token_ans[token_cnt], 1};
        node[rt].son.push_back(node_cnt);
        next_token();
    }

    Block(rt); // 假设已定义 Block 解析程序
}
//主函数定义 MainFuncDef → 'int' 'main' '(' ')' Block // j
void MainFuncDef(int father)
{
    ++node_cnt;
    node[node_cnt].endToken.sym = "<MainFuncDef>";
    int rt = node_cnt;
    node[father].son.push_back(rt);

    //int
    node[++node_cnt] = {token_ans[token_cnt], 1};
    node[rt].son.push_back(node_cnt);
    next_token();

    //main
    node[++node_cnt] = {token_ans[token_cnt], 1};
    node[rt].son.push_back(node_cnt);
    next_token();

    //(
    node[++node_cnt] = {token_ans[token_cnt], 1};
    node[rt].son.push_back(node_cnt);
    next_token();

    if (token_ans[token_cnt].sym != "RPARENT")
    {
        error(token_ans[token_cnt-1].line, "j");
        node[++node_cnt] .endToken.sym = "RPARENT";   //补齐
        node[rt].son.push_back(node_cnt);
    }else{
        node[++node_cnt] = {token_ans[token_cnt], 1};
        node[rt].son.push_back(node_cnt);
        next_token();
    }
    Block(rt);
}

// 函数类型 FuncType → 'void' | 'int' | 'char'
void FuncType(int father)
{
    ++node_cnt;
    node[node_cnt].endToken.sym = "<FuncType>";
    int rt = node_cnt;
    node[father].son.push_back(rt);
    //'void' | 'int' | 'char'
    node[++node_cnt] = {token_ans[token_cnt], 1};
    node[rt].son.push_back(node_cnt);
    next_token();
}

// 函数形参表 FuncFParams → FuncFParam { ',' FuncFParam }
void FuncFParams(int father)
{
    ++node_cnt;
    node[node_cnt].endToken.sym = "<FuncFParams>";
    int rt = node_cnt;
    node[father].son.push_back(rt);

    FuncFParam(rt); // 解析第一个形参

    while (token_ans[token_cnt].sym == "COMMA")
    {
        node[++node_cnt] = {token_ans[token_cnt], 1};
        node[rt].son.push_back(node_cnt);
        next_token();

        FuncFParam(rt); // 解析后续形参
    }
}

// 函数形参 FuncFParam → BType Ident ['[' ']'] // k
void FuncFParam(int father)
{
    ++node_cnt;
    node[node_cnt].endToken.sym = "<FuncFParam>";
    int rt = node_cnt;
    node[father].son.push_back(rt);

    BType(rt); // 假设已定义 BType 解析程序

    //Ident
    node[++node_cnt] = {token_ans[token_cnt], 1};
    node[rt].son.push_back(node_cnt);
    next_token();

    // 检查是否有数组形参
    if (token_ans[token_cnt].sym == "LBRACK")
    {
        node[++node_cnt] = {token_ans[token_cnt], 1};
        node[rt].son.push_back(node_cnt);
        next_token();

        if (token_ans[token_cnt].sym != "RBRACK")
        {
            error(token_ans[token_cnt-1].line, "k");
            node[++node_cnt] .endToken.sym = "RBRACK";   //补齐
            node[rt].son.push_back(node_cnt);
        }else{
            node[++node_cnt] = {token_ans[token_cnt], 1};
            node[rt].son.push_back(node_cnt);
            next_token();
        }
    }
}
//语句块 Block → '{' { BlockItem } '}' 
void Block(int father)
{
    ++node_cnt;
    node[node_cnt].endToken.sym = "<Block>";
    int rt = node_cnt;
    node[father].son.push_back(rt);

    //{
    node[++node_cnt] = {token_ans[token_cnt], 1};
    node[rt].son.push_back(node_cnt);
    next_token();

    BlockItem(rt);

    //}
    node[++node_cnt] = {token_ans[token_cnt], 1};
    node[rt].son.push_back(node_cnt);
    next_token();

}

void BlockItem(int father)
{
    /*++node_cnt;
    node[node_cnt].endToken.sym="<BlockItem>";
    int rt=node_cnt;
    node[father].son.push_back(rt);*/
    int rt = father;
    //printf("BlockItem\n");
    while(token_ans[token_cnt].sym != "RBRACE"){
        if (token_ans[token_cnt].sym == "CONSTTK" || token_ans[token_cnt].sym == "INTTK" || token_ans[token_cnt].sym == "CHARTK")
        {
            //printf("Decl\n");
            Decl(rt);
        }
        else
        {
            //printf("Stmt\n");
            Stmt(rt);
        }
    }
}

void Stmt(int father)
{
    ++node_cnt;
    node[node_cnt].endToken.sym = "<Stmt>";
    int rt = node_cnt;
    node[father].son.push_back(rt);

    if (token_ans[token_cnt].sym == "BREAKTK")
    { // break ';'
        node[++node_cnt] = {token_ans[token_cnt], 1};
        node[rt].son.push_back(node_cnt);
        next_token();

        if (token_ans[token_cnt].sym != "SEMICN")
        {
            error(token_ans[token_cnt-1].line, "i");
            node[++node_cnt] .endToken.sym = "SEMICN";   //补齐
            node[rt].son.push_back(node_cnt);
        }else{
            node[++node_cnt] = {token_ans[token_cnt], 1};
            node[rt].son.push_back(node_cnt);
            next_token();
        }
    }
    else if (token_ans[token_cnt].sym == "CONTINUETK")
    { // continue ';'
        node[++node_cnt] = {token_ans[token_cnt], 1};
        node[rt].son.push_back(node_cnt);
        next_token();

        if (token_ans[token_cnt].sym != "SEMICN")
        {
            error(token_ans[token_cnt-1].line, "i");
            node[++node_cnt] .endToken.sym = "SEMICN";   //补齐
            node[rt].son.push_back(node_cnt);
        }else{
            node[++node_cnt] = {token_ans[token_cnt], 1};
            node[rt].son.push_back(node_cnt);
            next_token();
        }
    }
    else if (token_ans[token_cnt].sym == "RETURNTK")
    { // return [Exp] ';'
        node[++node_cnt] = {token_ans[token_cnt], 1};
        node[rt].son.push_back(node_cnt);
        next_token();

        if (token_ans[token_cnt].sym != "SEMICN")
        {
            //printf("RETURNTK:");
            //cout<<token_ans[token_cnt].sym<<" "<<token_ans[token_cnt].ori<<endl;
            Exp(rt); // 解析可能的返回值
        }

        if (token_ans[token_cnt].sym != "SEMICN")
        {
            error(token_ans[token_cnt-1].line, "i");
            node[++node_cnt] .endToken.sym = "SEMICN";   //补齐
            node[rt].son.push_back(node_cnt);
        }else{
            node[++node_cnt] = {token_ans[token_cnt], 1};
            node[rt].son.push_back(node_cnt);
            next_token();
        }
    }
    else if (token_ans[token_cnt].sym == "IFTK")
    { // if '(' Cond ')' Stmt [ 'else' Stmt ]
        node[++node_cnt] = {token_ans[token_cnt], 1};
        node[rt].son.push_back(node_cnt);
        next_token();

        //(
        node[++node_cnt] = {token_ans[token_cnt], 1};
        node[rt].son.push_back(node_cnt);
        next_token();

        Cond(rt); // 解析条件

        if (token_ans[token_cnt].sym != "RPARENT")
        {
            error(token_ans[token_cnt-1].line, "j");
            node[++node_cnt] .endToken.sym = "RPARENT";   //补齐
            node[rt].son.push_back(node_cnt);
        }else{
            node[++node_cnt] = {token_ans[token_cnt], 1};
            node[rt].son.push_back(node_cnt);
            next_token();
        }

        Stmt(rt); // 解析if后面的语句

        if (token_ans[token_cnt].sym == "ELSETK")
        { // else optional
            node[++node_cnt] = {token_ans[token_cnt], 1};
            node[rt].son.push_back(node_cnt);
            next_token();

            Stmt(rt); // 解析else后面的语句
        }
    }
    else if (token_ans[token_cnt].sym == "FORTK")
    { // for '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
        node[++node_cnt] = {token_ans[token_cnt], 1};
        node[rt].son.push_back(node_cnt);
        next_token();

        //(
        node[++node_cnt] = {token_ans[token_cnt], 1};
        node[rt].son.push_back(node_cnt);
        next_token();

        if (token_ans[token_cnt].sym != "SEMICN")ForStmt(rt); // 解析for语句部分

        //;
        node[++node_cnt] = {token_ans[token_cnt], 1};
        node[rt].son.push_back(node_cnt);
        next_token();

        if (token_ans[token_cnt].sym != "SEMICN")Cond(rt); // 解析条件表达式

        //;
        node[++node_cnt] = {token_ans[token_cnt], 1};
        node[rt].son.push_back(node_cnt);
        next_token();

        if (token_ans[token_cnt].sym != "RPARENT")ForStmt(rt); // 解析for结束部分

        //)
        node[++node_cnt] = {token_ans[token_cnt], 1};
        node[rt].son.push_back(node_cnt);
        next_token();

        Stmt(rt); // 解析for循环体
    }
    else if (token_ans[token_cnt].sym == "PRINTFTK")  //'printf''('StringConst {','Exp}')'';' // i j
    {              
        node[++node_cnt] = {token_ans[token_cnt], 1};
        node[rt].son.push_back(node_cnt);
        next_token();

        //(
        node[++node_cnt] = {token_ans[token_cnt], 1};
        node[rt].son.push_back(node_cnt);
        next_token();

        //STRCON
        node[++node_cnt] = {token_ans[token_cnt], 1};
        node[rt].son.push_back(node_cnt);
        next_token();

        while (token_ans[token_cnt].sym == "COMMA") {
            node[++node_cnt] = {token_ans[token_cnt], 1};
            node[rt].son.push_back(node_cnt);
            next_token(); // Consume ','

            Exp(rt); // 解析表达式
        }
        //')'
        if (token_ans[token_cnt].sym != "RPARENT"){
            error(token_ans[token_cnt-1].line, "j");
            node[++node_cnt] .endToken.sym = "RPARENT";   //补齐
            node[rt].son.push_back(node_cnt);
        }
        else{
            node[++node_cnt] = {token_ans[token_cnt], 1};
            node[rt].son.push_back(node_cnt);
            next_token();
        }
        //';'
        if (token_ans[token_cnt].sym != "SEMICN"){
            error(token_ans[token_cnt-1].line, "i");
            node[++node_cnt] .endToken.sym = "SEMICN";   //补齐
            node[rt].son.push_back(node_cnt);
        }
        else{
            node[++node_cnt] = {token_ans[token_cnt], 1};
            node[rt].son.push_back(node_cnt);
            next_token();
        }
    }else if (token_ans[token_cnt].sym == "LBRACE")
    {              // Block
        Block(rt); // 解析语句块
    }
    else
    {
        bool isLVal = false;
        for (int token_pre = token_cnt; token_ans[token_pre].sym != "SEMICN" && token_ans[token_pre].line == token_ans[token_cnt].line; token_pre++)
        {
            if (token_ans[token_pre].sym == "ASSIGN")
            { // 在这句话中找到等号
                isLVal = true;
                break;
            }
        }
        // LVal '=' Exp ';'
        //cout<<"isLVal "<<isLVal<<endl;
        if (isLVal){
            LVal(rt);

            //=
            node[++node_cnt] = {token_ans[token_cnt], 1};
            node[rt].son.push_back(node_cnt);
            next_token();

            if (token_ans[token_cnt].sym == "GETINTTK" || token_ans[token_cnt].sym == "GETCHARTK"){
                node[++node_cnt] = {token_ans[token_cnt], 1};
                node[rt].son.push_back(node_cnt);
                next_token();

                //(
                node[++node_cnt] = {token_ans[token_cnt], 1};
                node[rt].son.push_back(node_cnt);
                next_token();

                if (token_ans[token_cnt].sym != "RPARENT"){
                    error(token_ans[token_cnt-1].line, "j");
                    node[++node_cnt] .endToken.sym = "RPARENT";   //补齐
                    node[rt].son.push_back(node_cnt);
                }
                else{
                    node[++node_cnt] = {token_ans[token_cnt], 1};
                    node[rt].son.push_back(node_cnt);
                    next_token();
                }                           
            }
            else{
                Exp(rt);
            }
        }else{
            if (token_ans[token_cnt].sym != "SEMICN"){
                Exp(rt);
            }
        }

        if (token_ans[token_cnt].sym != "SEMICN"){
            error(token_ans[token_cnt-1].line, "i");
            node[++node_cnt] .endToken.sym = "SEMICN";   //补齐
            node[rt].son.push_back(node_cnt);
        }
        else{
            node[++node_cnt] = {token_ans[token_cnt], 1};
            node[rt].son.push_back(node_cnt);
            next_token();
        }
    }
}
// 语句 ForStmt → LVal '=' Exp
void ForStmt(int father)
{
    ++node_cnt;
    node[node_cnt].endToken.sym = "<ForStmt>";
    int rt = node_cnt;
    node[father].son.push_back(rt);

    LVal(rt);

    //=
    node[++node_cnt] = {token_ans[token_cnt], 1};
    node[rt].son.push_back(node_cnt);
    next_token();

    Exp(rt); // 解析表达式
}

// 表达式 Exp → AddExp
void Exp(int father)
{
    ++node_cnt;
    node[node_cnt].endToken.sym = "<Exp>";
    int rt = node_cnt;
    node[father].son.push_back(rt);

    AddExp(rt); // 解析加法表达式
}

// 条件表达式 Cond → LOrExp
void Cond(int father)
{
    ++node_cnt;
    node[node_cnt].endToken.sym = "<Cond>";
    int rt = node_cnt;
    node[father].son.push_back(rt);

    LOrExp(rt); // 解析或表达式
}

// 左值表达式 LVal → Ident ['[' Exp ']'] // k
void LVal(int father)
{
    //printf("LVal\n");
    ++node_cnt;
    node[node_cnt].endToken.sym = "<LVal>";
    int rt = node_cnt;
    node[father].son.push_back(rt);

    //Ident
    node[++node_cnt] = {token_ans[token_cnt], 1};
    node[rt].son.push_back(node_cnt);
    next_token();

    // 检查是否有数组下标
    if (token_ans[token_cnt].sym == "LBRACK")
    {
        node[++node_cnt] = {token_ans[token_cnt], 1};
        node[rt].son.push_back(node_cnt);
        next_token();

        Exp(rt); // 解析下标表达式

        if (token_ans[token_cnt].sym != "RBRACK")
        {
            error(token_ans[token_cnt-1].line, "k");
            node[++node_cnt] .endToken.sym = "RBRACK";   //补齐
            node[rt].son.push_back(node_cnt);
        }else{
            node[++node_cnt] = {token_ans[token_cnt], 1};
            node[rt].son.push_back(node_cnt);
            next_token();
        }
    }
}

// 基本表达式 PrimaryExp → '(' Exp ')' | LVal | Number | Character// j
void PrimaryExp(int father)
{
    ++node_cnt;
    node[node_cnt].endToken.sym = "<PrimaryExp>";
    int rt = node_cnt;
    node[father].son.push_back(rt);

    if (token_ans[token_cnt].sym == "LPARENT")
    { // '(' Exp ')'
        node[++node_cnt] = {token_ans[token_cnt], 1};
        node[rt].son.push_back(node_cnt);
        next_token();

        Exp(rt); // 解析内部表达式

        if (token_ans[token_cnt].sym != "RPARENT")
        {
            error(token_ans[token_cnt-1].line, "j");
            node[++node_cnt] .endToken.sym = "RPARENT";   //补齐
            node[rt].son.push_back(node_cnt);
        }else{
            node[++node_cnt] = {token_ans[token_cnt], 1};
            node[rt].son.push_back(node_cnt);
            next_token();
        }
    }
    else if (token_ans[token_cnt].sym == "IDENFR")
    { // LVal
        LVal(rt);
    }
    else if (token_ans[token_cnt].sym == "INTCON")
    { // Number
        Number(rt);
    }
    else if (token_ans[token_cnt].sym == "CHRCON")
    { // Character
        Character(rt);
    }
    else
    {
        //printf("what \n");
        //cout<<token_ans[token_cnt].sym<<endl;
        //error(token_ans[token_cnt].line, "j");
        //while(1);
    }
}

// 数值 Number → IntConst
void Number(int father)
{
    //int
    ++node_cnt;
    node[node_cnt].endToken.sym = "<Number>";
    int rt = node_cnt;
    node[father].son.push_back(rt);

    node[++node_cnt] = {token_ans[token_cnt], 1};
    node[rt].son.push_back(node_cnt);
    next_token();
}

// 字符 Character → CharConst
void Character(int father)
{
    //char
    ++node_cnt;
    node[node_cnt].endToken.sym = "<Character>";
    int rt = node_cnt;
    node[father].son.push_back(rt);

    node[++node_cnt] = {token_ans[token_cnt], 1};
    node[rt].son.push_back(node_cnt);
    next_token();
}

// 一元表达式 UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp // j
void UnaryExp(int father)
{
    ++node_cnt;
    node[node_cnt].endToken.sym = "<UnaryExp>";
    int rt = node_cnt;
    node[father].son.push_back(rt);
    if (token_ans[token_cnt].sym == "PLUS" || token_ans[token_cnt].sym == "MINU" || token_ans[token_cnt].sym == "NOT")
    {
        //cout<<"UnaryExp "<<token_ans[token_cnt].sym<<endl;

        UnaryOp(rt);

        UnaryExp(rt); // 递归解析
    }
    else if (token_ans[token_cnt+1].sym == "LPARENT" && token_ans[token_cnt].sym == "IDENFR")
    { // Ident '(' [FuncRParams] ')'
        node[++node_cnt] = {token_ans[token_cnt], 1};
        node[rt].son.push_back(node_cnt);
        next_token();

        //(
        node[++node_cnt] = {token_ans[token_cnt], 1};
        node[rt].son.push_back(node_cnt);
        next_token();

        if (token_ans[token_cnt].sym == "LPARENT" || token_ans[token_cnt].sym=="IDENFR" || token_ans[token_cnt].sym=="INTCON" || token_ans[token_cnt].sym=="CHRCON" || token_ans[token_cnt].sym=="PLUS" || token_ans[token_cnt].sym=="MINU" || token_ans[token_cnt].sym=="NOT")FuncRParams(rt);

        if (token_ans[token_cnt].sym != "RPARENT"){
            error(token_ans[token_cnt-1].line, "j");
            node[++node_cnt] .endToken.sym = "RPARENT";   //补齐
            node[rt].son.push_back(node_cnt);
        }else{
            node[++node_cnt] = {token_ans[token_cnt], 1};
            node[rt].son.push_back(node_cnt);
            next_token();
        }
    }
    else
    {
        PrimaryExp(rt);
    }
}

// 单目运算符 UnaryOp → '+' | '−' | '!' 注：'!'仅出现在条件表达式中
void UnaryOp(int father)
{
    ++node_cnt;
    node[node_cnt].endToken.sym = "<UnaryOp>";
    int rt = node_cnt;
    node[father].son.push_back(rt);

    //'+' | '−' | '!'
    node[++node_cnt] = {token_ans[token_cnt], 1};
    node[rt].son.push_back(node_cnt);
    next_token();
}

// 函数实参表 FuncRParams → Exp { ',' Exp }
void FuncRParams(int father)
{
    ++node_cnt;
    node[node_cnt].endToken.sym = "<FuncRParams>";
    int rt = node_cnt;
    node[father].son.push_back(rt);

    Exp(rt); // 解析第一个实参

    while (token_ans[token_cnt].sym == "COMMA")
    {
        node[++node_cnt] = {token_ans[token_cnt], 1};
        node[rt].son.push_back(node_cnt);
        next_token();
        Exp(rt); // 解析后续实参
    }
}

void rebuild_tree(int father,int rt,string token_name){
    //if((node[rt].son.size()>1))printf("unknown\n");
    //重构树
    int fa=father;
    while(node[rt].son.size()>1){
        ++node_cnt;
        node[node_cnt].endToken.sym = token_name;//"<MulExp>";

        if(fa==father){
            node[fa].son.pop_back();
            node[fa].son.push_back(node_cnt);
        }else{
            node[fa].son[0]=node_cnt;
        }
        node[node_cnt].son.push_back(rt);
        node[node_cnt].son.push_back(node[rt].son[node[rt].son.size()-2]);
        node[node_cnt].son.push_back(node[rt].son[node[rt].son.size()-1]);
        node[rt].son.pop_back();
        node[rt].son.pop_back();

        fa = node_cnt;
    }
}

void MulExp(int father)
{
    ++node_cnt;
    node[node_cnt].endToken.sym = "<MulExp>";
    int rt = node_cnt;
    node[father].son.push_back(rt);

    UnaryExp(rt);

    while(token_ans[token_cnt].sym == "MULT" || token_ans[token_cnt].sym == "DIV" || token_ans[token_cnt].sym == "MOD"){
        node[++node_cnt] = {token_ans[token_cnt], 1};
        node[rt].son.push_back(node_cnt);
        next_token();

        UnaryExp(rt);
    }

    rebuild_tree(father,rt,"<MulExp>");
}

void AddExp(int father){
    ++node_cnt;
    node[node_cnt].endToken.sym = "<AddExp>";
    int rt = node_cnt;
    node[father].son.push_back(rt);

    MulExp(rt);  //ending

    while(token_ans[token_cnt].sym == "PLUS" || token_ans[token_cnt].sym == "MINU"){
        node[++node_cnt] = {token_ans[token_cnt], 1};
        node[rt].son.push_back(node_cnt);
        next_token();

        MulExp(rt);   //ending
    }

    rebuild_tree(father,rt,"<AddExp>");
}

void RelExp(int father){
    ++node_cnt;
    node[node_cnt].endToken.sym = "<RelExp>";
    int rt = node_cnt;
    node[father].son.push_back(rt);

    AddExp(rt);

    while(token_ans[token_cnt].sym == "LSS" || token_ans[token_cnt].sym == "LEQ" || token_ans[token_cnt].sym == "GRE" || token_ans[token_cnt].sym == "GEQ"){
        node[++node_cnt] = {token_ans[token_cnt], 1};
        node[rt].son.push_back(node_cnt);
        next_token();

        AddExp(rt);
    }

    rebuild_tree(father,rt,"<RelExp>");      
}

void EqExp(int father){
    ++node_cnt;
    node[node_cnt].endToken.sym = "<EqExp>";
    int rt = node_cnt;
    node[father].son.push_back(rt);

    RelExp(rt);

    while(token_ans[token_cnt].sym == "EQL" || token_ans[token_cnt].sym == "NEQ" ){
        node[++node_cnt] = {token_ans[token_cnt], 1};
        node[rt].son.push_back(node_cnt);
        next_token();

        RelExp(rt);
    }

    rebuild_tree(father,rt,"<EqExp>");    
}

void LAndExp(int father){
    ++node_cnt;
    node[node_cnt].endToken.sym = "<LAndExp>";
    int rt = node_cnt;
    node[father].son.push_back(rt);

    EqExp(rt);

    while(token_ans[token_cnt].sym == "AND"){
        node[++node_cnt] = {token_ans[token_cnt], 1};
        node[rt].son.push_back(node_cnt);
        next_token();

        EqExp(rt);
    }

    rebuild_tree(father,rt,"<LAndExp>");
}

void LOrExp(int father){
    ++node_cnt;
    node[node_cnt].endToken.sym = "<LOrExp>";
    int rt = node_cnt;
    node[father].son.push_back(rt);

    LAndExp(rt);

    while(token_ans[token_cnt].sym == "OR"){
        node[++node_cnt] = {token_ans[token_cnt], 1};
        node[rt].son.push_back(node_cnt);
        next_token();

        LAndExp(rt);
    }

    rebuild_tree(father,rt,"<LOrExp>");
}



// 常量表达式 ConstExp → AddExp
void ConstExp(int father)
{
    ++node_cnt;
    node[node_cnt].endToken.sym = "<ConstExp>";
    int rt = node_cnt;
    node[father].son.push_back(rt);

    AddExp(rt);
}