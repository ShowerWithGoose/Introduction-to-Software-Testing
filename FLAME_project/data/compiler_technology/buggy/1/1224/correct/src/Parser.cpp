#include <bits/stdc++.h>
#include <string>
#include "include/Parser.h"
#include "include/Type.h"
#include "include/Lexer.h"
#include "include/Error.h"
#include "include/File.h"

Node nodes[2000000];
Nodep rootp = &nodes[0];

int count = 0;

int curcount = 0;

void AddChildNode(Nodep father, PARSER_TYPE type, int index)
{
    Nodep temp = father;
    if (temp->child == 0)
    {
        temp->child = ++count;
        nodes[count].index = index;
        nodes[count].type = type;
    }
    else
    {
        temp = &nodes[temp->child];
        while (temp->fellow != 0)
        {
            temp = &nodes[temp->fellow];
        }
        temp->fellow = ++count;
        nodes[count].index = index;
        nodes[count].type = type;
    }
}
void ChangeFellow(Nodep father, PARSER_TYPE type)
{
    int temp = father->child;
    if (nodes[temp].fellow != 0)
    {
        ++count;
        nodes[count].fellow = nodes[temp].fellow;
        nodes[temp].fellow = 0;
        nodes[count].child = father->child;
        nodes[count].type = type;
        father->child = count;
        temp = count;
    }
    while (nodes[nodes[nodes[temp].fellow].fellow].fellow != 0)
    {
        ++count;
        nodes[count].fellow = nodes[nodes[nodes[temp].fellow].fellow].fellow; // 向后取2位
        nodes[nodes[nodes[temp].fellow].fellow].fellow = 0;
        nodes[count].child = father->child;
        nodes[count].type = type;
        father->child = count;
        temp = count;
    }
}
void TreeToString()
{
    Nodep temp = rootp;
    if (temp->child != 0)
    {
        PrintNode(&nodes[temp->child]);
    }
}
void PrintNode(Nodep father)
{
    Nodep temp = father;
    if (temp->child != 0)
    {
        PrintNode(&nodes[temp->child]);
    }
    temp = &nodes[temp->child];
    while (temp->fellow != 0)
    {
        temp = &nodes[temp->fellow];
        PrintNode(temp);
    }
    NodeToString(father);
}
void NodeToString(Nodep now)
{
    if (now->type == _ENDPARSE)
    {
        fprintf(outfile, "%s %s\n", sym_names[tokens[now->index].sym].c_str(), tokens[now->index].token.c_str());
    }
    else if (now->type != _BlockItem && now->type != _Decl && now->type != _BType && now->type != _NULL)
    {
        fprintf(outfile, "<%s>\n", parser_names[now->type].c_str());
    }
}
void AddNull(Nodep father)
{
    Nodep temp = father;
    if (temp->child == 0)
    {
        temp->child = ++count;
        nodes[count].type = _NULL;
    }
    else
    {
        temp = &nodes[temp->child];
        while (temp->fellow != 0)
        {
            temp = &nodes[temp->fellow];
        }
        temp->fellow = ++count;
        nodes[count].type = _NULL;
    }
}

void BuildTree()
{
    CompUnit(&nodes[0]);
}
SYMTYPE getnow()
{
    return tokens[curcount].sym;
}
SYMTYPE getpre(int index)
{
    if (curcount + index >= tokenNum)
        return NOTOKEN;
    return tokens[curcount + index].sym;
}

void CompUnit(Nodep father)
{ // CompUnit → {Decl} {FuncDef} MainFuncDef
    AddChildNode(father, _CompUnit, curcount);
    int temp = count;
    while (getnow() == CONSTTK || getnow() == INTTK || getnow() == CHARTK)
    {
        if (getnow() == CONSTTK)
        {
            Decl(&nodes[temp]);
        }
        else if (getnow() == INTTK)
        {
            if (getpre(1) == MAINTK)
            {
                break;
            }
            if (getpre(1) == IDENFR)
            {
                if (getpre(2) == LPARENT)
                {
                    break;
                }
                else
                {
                    Decl(&nodes[temp]);
                }
            }
        }
        else if (getnow() == CHARTK)
        {
            if (getpre(1) == IDENFR)
            {
                if (getpre(2) == LPARENT)
                {
                    break;
                }
                else
                {
                    Decl(&nodes[temp]);
                }
            }
        }
    }
    while (getnow() == VOIDTK || getnow() == INTTK || getnow() == CHARTK)
    {
        if (getnow() == VOIDTK || getnow() == CHARTK)
        {
            FuncDef(&nodes[temp]);
        }
        else if (getnow() == INTTK)
        {
            if (getpre(1) == MAINTK)
            {
                break;
            }
            if (getpre(1) == IDENFR)
            {
                FuncDef(&nodes[temp]);
            }
        }
    }

    if (getnow() == INTTK)
    {
        if (getpre(1) == MAINTK)
        {
            MainFuncDef(&nodes[temp]);
        }
    }
}
void Decl(Nodep father)
{ // Decl → ConstDecl | VarDecl
    AddChildNode(father, _Decl, curcount);
    if (getnow() == CONSTTK)
    {
        ConstDecl(&nodes[count]);
    }
    else if (getnow() == INTTK || getnow() == CHARTK)
    {
        VarDecl(&nodes[count]);
    }
}
void ConstDecl(Nodep father)
{ // ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';'
    AddChildNode(father, _ConstDecl, curcount);
    int temp = count;
    if (getnow() == CONSTTK)
    {

        ENDPARSE(&nodes[temp]); // const

        BType(&nodes[temp]);

        ConstDef(&nodes[temp]);
        while (getnow() == COMMA)
        {
            ENDPARSE(&nodes[temp]); //,
            ConstDef(&nodes[temp]);
        }
        if (getnow() == SEMICN)
            ENDPARSE(&nodes[temp]); //;
        else
            err('i', tokens[curcount - 1].line);
    }
}
void BType(Nodep father)
{ // BType → 'int' | 'char'
    AddChildNode(father, _BType, curcount);
    int temp = count;
    if (getnow() == INTTK || getnow() == CHARTK)
    {
        ENDPARSE(&nodes[temp]);
    }
}
void ConstDef(Nodep father)
{ // ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal
    AddChildNode(father, _ConstDef, curcount);
    int temp = count;
    if (getnow() == IDENFR)
    {
        ENDPARSE(&nodes[temp]); // Ident
        if (getnow() == LBRACK)
        {
            ENDPARSE(&nodes[temp]); //[
            ConstExp(&nodes[temp]);
            if (getnow() == RBRACK)
                ENDPARSE(&nodes[temp]); //]
            else
                err('k', tokens[curcount - 1].line);
        }
        if (getnow() == ASSIGN)
        {
            ENDPARSE(&nodes[temp]); //=
            ConstInitVal(&nodes[temp]);
        }
    }
}
void ConstInitVal(Nodep father)
{ // ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' |StringConst
    AddChildNode(father, _ConstInitVal, curcount);
    int temp = count;
    if (getnow() == LPARENT || getnow() == IDENFR || getnow() == INTCON || getnow() == CHRCON || getnow() == PLUS || getnow() == MINU || getnow() == NOT)
        ConstExp(&nodes[temp]);
    else if (getnow() == LBRACE)
    {
        ENDPARSE(&nodes[temp]); //{
        if (getnow() == LPARENT || getnow() == IDENFR || getnow() == INTCON || getnow() == CHRCON || getnow() == PLUS || getnow() == MINU || getnow() == NOT)
        {
            ConstExp(&nodes[temp]);
            while (getnow() == COMMA)
            {
                ENDPARSE(&nodes[temp]); //,
                ConstExp(&nodes[temp]);
            }
        }

        if (getnow() == RBRACE)
        {
            ENDPARSE(&nodes[temp]); //}
        }
    }
    else if (getnow() == STRCON)
    {
        ENDPARSE(&nodes[temp]); // StringConst
    }
}

void VarDecl(Nodep father)
{ // VarDecl → BType VarDef { ',' VarDef } ';'
    AddChildNode(father, _VarDecl, curcount);
    int temp = count;
    BType(&nodes[temp]);
    VarDef(&nodes[temp]);
    while (getnow() == COMMA)
    {
        ENDPARSE(&nodes[temp]); //,
        VarDef(&nodes[temp]);
    }
    if (getnow() == SEMICN)
        ENDPARSE(&nodes[temp]); //;
    else
        err('i', tokens[curcount - 1].line);
}

void VarDef(Nodep father)
{ // VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '='InitVal
    AddChildNode(father, _VarDef, curcount);
    int temp = count;
    if (getnow() == IDENFR)
    {
        ENDPARSE(&nodes[temp]); // Ident
        if (getnow() == LBRACK)
        {
            ENDPARSE(&nodes[temp]); //[

            ConstExp(&nodes[temp]);

            if (getnow() == RBRACK)
                ENDPARSE(&nodes[temp]); //]
            else
                err('k', tokens[curcount - 1].line);
        }
        if (getnow() == ASSIGN)
        {
            ENDPARSE(&nodes[temp]); //=
            InitVal(&nodes[temp]);
        }
    }
}

void InitVal(Nodep father)
{ // InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
    AddChildNode(father, _InitVal, curcount);
    int temp = count;
    if (getnow() == LPARENT || getnow() == IDENFR || getnow() == INTCON || getnow() == CHRCON || getnow() == PLUS || getnow() == MINU || getnow() == NOT)
        Exp(&nodes[temp]);
    else if (getnow() == LBRACE)
    {
        ENDPARSE(&nodes[temp]); //{
        if (getnow() == LPARENT || getnow() == IDENFR || getnow() == INTCON || getnow() == CHRCON || getnow() == PLUS || getnow() == MINU || getnow() == NOT)
        {
            Exp(&nodes[temp]);
            while (getnow() == COMMA)
            {
                ENDPARSE(&nodes[temp]); //,
                Exp(&nodes[temp]);
            }
        }
        if (getnow() == RBRACE)
        {
            ENDPARSE(&nodes[temp]); //}
        }
    }
    else if (getnow() == STRCON)
    {
        ENDPARSE(&nodes[temp]); // StringConst
    }
}

void FuncDef(Nodep father)
{ // FuncDef → FuncType Ident '(' [FuncFParams] ')' Block
    AddChildNode(father, _FuncDef, curcount);
    int temp = count;
    FuncType(&nodes[temp]);
    if (getnow() == IDENFR)
    {
        ENDPARSE(&nodes[temp]); // Ident
        if (getnow() == LPARENT)
        {
            ENDPARSE(&nodes[temp]); // (
            if (getnow() == INTTK || getnow() == CHARTK)

                FuncFParams(&nodes[temp]);
            if (getnow() == RPARENT)
            {
                ENDPARSE(&nodes[temp]); // )
            }
            else
                err('j', tokens[curcount - 1].line);
        }
    }
    Block(&nodes[temp]);
}

void MainFuncDef(Nodep father)
{ // MainFuncDef → 'int' 'main' '(' ')' Block
    AddChildNode(father, _MainFuncDef, curcount);
    int temp = count;
    if (getnow() == INTTK)
    {
        ENDPARSE(&nodes[temp]); // int
        if (getnow() == MAINTK)
        {
            ENDPARSE(&nodes[temp]); // main
            if (getnow() == LPARENT)
            {
                ENDPARSE(&nodes[temp]); // (
                if (getnow() == RPARENT)
                {
                    ENDPARSE(&nodes[temp]); // )
                }
                else
                    err('j', tokens[curcount - 1].line);
                Block(&nodes[temp]);
            }
        }
    }
}

void FuncType(Nodep father)
{ // FuncType → 'void' | 'int' | 'char'
    AddChildNode(father, _FuncType, curcount);
    int temp = count;
    if (getnow() == INTTK || getnow() == VOIDTK || getnow() == CHARTK)
    {
        ENDPARSE(&nodes[temp]); // int
    }
}

void FuncFParams(Nodep father)
{ // FuncFParams → FuncFParam { ',' FuncFParam }
    AddChildNode(father, _FuncFParams, curcount);
    int temp = count;
    FuncFParam(&nodes[temp]);
    while (getnow() == COMMA)
    {
        ENDPARSE(&nodes[temp]); // ,
        FuncFParam(&nodes[temp]);
    }
}

void FuncFParam(Nodep father)
{ // FuncFParam → BType Ident ['[' ']']
    AddChildNode(father, _FuncFParam, curcount);
    int temp = count;
    BType(&nodes[temp]);
    if (getnow() == IDENFR)
    {
        ENDPARSE(&nodes[temp]); // Ident
    }
    if (getnow() == LBRACK)
    {
        ENDPARSE(&nodes[temp]); // [
        if (getnow() == RBRACK)
        {
            ENDPARSE(&nodes[temp]); // ]
        }
        else
            err('k', tokens[curcount - 1].line);
    }
}

void Block(Nodep father)
{ // Block → '{' { BlockItem } '}'
    AddChildNode(father, _Block, curcount);
    int temp = count;
    if (getnow() == LBRACE)
    {
        ENDPARSE(&nodes[temp]); // {
        while (getnow() == SEMICN || getnow() == IDENFR || getnow() == LBRACE || getnow() == IFTK || getnow() == FORTK || getnow() == BREAKTK || getnow() == CONTINUETK || getnow() == RETURNTK || getnow() == PRINTFTK || getnow() == LPARENT || getnow() == INTCON || getnow() == CHRCON || getnow() == PLUS || getnow() == MINU || getnow() == NOT || getnow() == CONSTTK || getnow() == INTTK || getnow() == CHARTK)
            BlockItem(&nodes[temp]);
        if (getnow() == RBRACE)
        {
            ENDPARSE(&nodes[temp]); // }
        }
    }
}

void BlockItem(Nodep father)
{ // BlockItem → Decl | Stmt
    AddChildNode(father, _BlockItem, curcount);
    int temp = count;
    if (getnow() == CONSTTK || getnow() == INTTK || getnow() == CHARTK)
    {
        Decl(&nodes[temp]);
    }
    else if (getnow() == SEMICN || getnow() == IDENFR || getnow() == LBRACE || getnow() == IFTK || getnow() == FORTK || getnow() == BREAKTK || getnow() == CONTINUETK || getnow() == RETURNTK || getnow() == PRINTFTK || getnow() == LPARENT || getnow() == INTCON || getnow() == CHRCON || getnow() == PLUS || getnow() == MINU || getnow() == NOT)
    {
        Stmt(&nodes[temp]);
    }
}

void Stmt(Nodep father)
{ // Stmt → LVal '=' (Exp|'getint''('')'|'getchar''('')') ';'
    // | [Exp] ';'
    // | Block
    // | 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
    // | 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
    // | 'break' ';' | 'continue' ';'
    // | 'return' [Exp] ';'
    // | 'printf''('StringConst {','Exp}')'';'
    AddChildNode(father, _Stmt, curcount);
    int temp = count;
    if (getnow() == LBRACE)
    {
        Block(&nodes[temp]);
    }
    else if (getnow() == IFTK)
    {
        ENDPARSE(&nodes[temp]); // if
        if (getnow() == LPARENT)
        {
            ENDPARSE(&nodes[temp]); // (
            Cond(&nodes[temp]);
            if (getnow() == RPARENT)
            {
                ENDPARSE(&nodes[temp]); // )
                Stmt(&nodes[temp]);
                if (getnow() == ELSETK)
                {
                    ENDPARSE(&nodes[temp]); // else
                    Stmt(&nodes[temp]);
                }
            }
            else
                err('j', tokens[curcount - 1].line);
        }
    }
    else if (getnow() == FORTK)
    {
        ENDPARSE(&nodes[temp]); // for
        if (getnow() == LPARENT)
        {
            ENDPARSE(&nodes[temp]); // (
            if (getnow() == IDENFR)
            {
                ForStmt(&nodes[temp]);
            }
            if (getnow() == SEMICN)
            {
                ENDPARSE(&nodes[temp]); // ;
            }
            if (getnow() == LPARENT || getnow() == IDENFR || getnow() == INTCON || getnow() == CHRCON || getnow() == PLUS || getnow() == MINU || getnow() == NOT)
            {
                Cond(&nodes[temp]);
            }
            if (getnow() == SEMICN)
            {
                ENDPARSE(&nodes[temp]); // ;
            }
            if (getnow() == IDENFR)
            {
                ForStmt(&nodes[temp]);
            }
            if (getnow() == RPARENT)
            {
                ENDPARSE(&nodes[temp]); // )
                Stmt(&nodes[temp]);
            }
            else
                err('j', tokens[curcount - 1].line);
        }
    }
    else if (getnow() == BREAKTK)
    {
        ENDPARSE(&nodes[temp]); // break
        if (getnow() == SEMICN)
        {
            ENDPARSE(&nodes[temp]); // ;
        }
        else
            err('i', tokens[curcount - 1].line);
    }
    else if (getnow() == CONTINUETK)
    {
        ENDPARSE(&nodes[temp]); // continue
        if (getnow() == SEMICN)
        {
            ENDPARSE(&nodes[temp]); // ;
        }
        else
            err('i', tokens[curcount - 1].line);
    }
    else if (getnow() == RETURNTK)
    {
        ENDPARSE(&nodes[temp]); // return
        if (getnow() == LPARENT || getnow() == IDENFR || getnow() == INTCON || getnow() == CHRCON || getnow() == PLUS || getnow() == MINU || getnow() == NOT)
        {
            Exp(&nodes[temp]);
        }
        if (getnow() == SEMICN)
        {
            ENDPARSE(&nodes[temp]); //;
        }
        else
            err('i', tokens[curcount - 1].line);
    }
    else if (getnow() == PRINTFTK)
    {
        ENDPARSE(&nodes[temp]); // printf
        if (getnow() == LPARENT)
        {
            ENDPARSE(&nodes[temp]); //(
            if (getnow() == STRCON)
            {
                ENDPARSE(&nodes[temp]); // StringConst
                while (getnow() == COMMA)
                {
                    ENDPARSE(&nodes[temp]); // ,
                    Exp(&nodes[temp]);
                }
                if (getnow() == RPARENT)
                {
                    ENDPARSE(&nodes[temp]); // )
                    if (getnow() == SEMICN)
                    {
                        ENDPARSE(&nodes[temp]); // ;
                    }
                    else
                        err('i', tokens[curcount - 1].line);
                }
                else
                    err('j', tokens[curcount - 1].line);
            }
        }
    }
    else if (getnow() == LPARENT || getnow() == INTCON || getnow() == CHRCON || getnow() == PLUS || getnow() == MINU || getnow() == NOT)
    {
        Exp(&nodes[temp]);
        if (getnow() == SEMICN)
        {
            ENDPARSE(&nodes[temp]); // ;
        }
    }
    else if (getnow() == IDENFR)
    {
        int line = tokens[curcount].line;
        int assign = 0;
        int now = curcount;
        while (tokens[now].line == line)
        {
            if (tokens[now].sym == ASSIGN)
            {
                assign = now;
                break;
            }
            if (tokens[now].sym == SEMICN)
            {
                break;
            }
            ++now;
        }
        if (assign > curcount)
        {
            LVal(&nodes[temp]);
            if (getnow() == ASSIGN)
            {
                ENDPARSE(&nodes[temp]); // =
                if (getnow() == GETINTTK || getnow() == GETCHARTK)
                {
                    ENDPARSE(&nodes[temp]); // getint||getchar
                    if (getnow() == LPARENT)
                    {
                        ENDPARSE(&nodes[temp]); // (
                        if (getnow() == RPARENT)
                        {
                            ENDPARSE(&nodes[temp]); // )
                        }
                        else
                            err('j', tokens[curcount - 1].line);
                    }
                }
                else if (getnow() == LPARENT || getnow() == IDENFR || getnow() == INTCON || getnow() == CHRCON || getnow() == PLUS || getnow() == MINU || getnow() == NOT)
                {
                    Exp(&nodes[temp]);
                }
                if (getnow() == SEMICN)
                {
                    ENDPARSE(&nodes[temp]); // ;
                }
                else
                    err('i', tokens[curcount - 1].line);
            }
        }
        else
        {
            Exp(&nodes[temp]);
            if (getnow() == SEMICN)
            {
                ENDPARSE(&nodes[temp]); // ;
            }
        }
    }
    else if (getnow() == SEMICN)
    {
        ENDPARSE(&nodes[temp]); // ;
    }
    else
        err('i', tokens[curcount - 1].line);
}

void ForStmt(Nodep father)
{ // LVal '=' Exp
    AddChildNode(father, _ForStmt, curcount);
    int temp = count;
    LVal(&nodes[temp]);
    if (getnow() == ASSIGN)
    {
        ENDPARSE(&nodes[temp]); // =
        Exp(&nodes[temp]);
    }
}

void Exp(Nodep father)
{ // Exp → AddExp
    AddChildNode(father, _Exp, curcount);
    int temp = count;
    AddExp(&nodes[temp]);
}

void Cond(Nodep father)
{ // Cond → LOrExp
    AddChildNode(father, _Cond, curcount);
    int temp = count;
    LOrExp(&nodes[temp]);
}

void LVal(Nodep father)
{ // LVal → Ident ['[' Exp ']']
    AddChildNode(father, _LVal, curcount);
    int temp = count;
    if (getnow() == IDENFR)
    {
        ENDPARSE(&nodes[temp]); // Ident
        if (getnow() == LBRACK)
        {
            ENDPARSE(&nodes[temp]); // [
            Exp(&nodes[temp]);
            if (getnow() == RBRACK)
            {
                ENDPARSE(&nodes[temp]); // ]
            }
            else
                err('k', tokens[curcount - 1].line);
        }
    }
}

void PrimaryExp(Nodep father)
{ // PrimaryExp → '(' Exp ')' | LVal | Number | Character
    AddChildNode(father, _PrimaryExp, curcount);
    int temp = count;
    if (getnow() == LPARENT)
    {
        ENDPARSE(&nodes[temp]); // (
        Exp(&nodes[temp]);
        if (getnow() == RPARENT)
        {
            ENDPARSE(&nodes[temp]); // )
        }
        else
            err('j', tokens[curcount - 1].line);
    }
    else if (getnow() == IDENFR)
    {
        LVal(&nodes[temp]);
    }
    else if (getnow() == INTCON)
    {
        Number(&nodes[temp]);
    }
    else if (getnow() == CHRCON)
    {
        Character(&nodes[temp]);
    }
}

void Number(Nodep father)
{
    AddChildNode(father, _Number, curcount);
    int temp = count;
    if (getnow() == INTCON)
    {
        ENDPARSE(&nodes[temp]); // IntConst
    }
}

void Character(Nodep father)
{
    AddChildNode(father, _Character, curcount);
    int temp = count;
    if (getnow() == CHRCON)
    {
        ENDPARSE(&nodes[temp]); // CharConst
    }
}

void UnaryExp(Nodep father)
{ // UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
    AddChildNode(father, _UnaryExp, curcount);
    int temp = count;
    if (getnow() == LPARENT || getnow() == INTCON || getnow() == CHRCON)
    {
        PrimaryExp(&nodes[temp]);
    }
    else if (getnow() == PLUS || getnow() == MINU || getnow() == NOT)
    {
        UnaryOp(&nodes[temp]);
        UnaryExp(&nodes[temp]);
    }
    else if (getnow() == IDENFR)
    {
        if (getpre(1) == LPARENT)
        {
            ENDPARSE(&nodes[temp]); // Ident
            ENDPARSE(&nodes[temp]); //(
            if (getnow() == LPARENT || getnow() == IDENFR || getnow() == INTCON || getnow() == CHRCON || getnow() == PLUS || getnow() == MINU || getnow() == NOT)
            {
                FuncRParams(&nodes[temp]);
            }
            if (getnow() == RPARENT)
            {
                ENDPARSE(&nodes[temp]); // )
            }
            else
                err('j', tokens[curcount - 1].line);
        }
        else
        {
            PrimaryExp(&nodes[temp]);
        }
    }
}

void UnaryOp(Nodep father)
{ // UnaryOp → '+' | '−' | '!'
    AddChildNode(father, _UnaryOp, curcount);
    int temp = count;
    if (getnow() == PLUS || getnow() == MINU || getnow() == NOT)
    {
        ENDPARSE(&nodes[temp]); // + - !
    }
}

void FuncRParams(Nodep father)
{ // FuncRParams → Exp { ',' Exp }
    AddChildNode(father, _FuncRParams, curcount);
    int temp = count;
    Exp(&nodes[temp]);
    while (getnow() == COMMA)
    {
        ENDPARSE(&nodes[temp]); //,
        Exp(&nodes[temp]);
    }
}

void MulExp(Nodep father)
{ // MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
    AddChildNode(father, _MulExp, curcount);
    int temp = count;
    UnaryExp(&nodes[temp]);
    while (getnow() == MULT || getnow() == DIV || getnow() == MOD)
    {
        ENDPARSE(&nodes[temp]); //* / %
        UnaryExp(&nodes[temp]);
    }
    ChangeFellow(&nodes[temp], _MulExp);
}

void AddExp(Nodep father)
{ // AddExp → MulExp | AddExp ('+' | '−') MulExp
    AddChildNode(father, _AddExp, curcount);
    int temp = count;
    MulExp(&nodes[temp]);
    while (getnow() == PLUS || getnow() == MINU)
    {
        ENDPARSE(&nodes[temp]); //+ -
        MulExp(&nodes[temp]);
    }
    ChangeFellow(&nodes[temp], _AddExp);
}

void RelExp(Nodep father)
{ // RelExp → AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
    AddChildNode(father, _RelExp, curcount);
    int temp = count;
    AddExp(&nodes[temp]);
    while (getnow() == LSS || getnow() == LEQ || getnow() == GRE || getnow() == GEQ)
    {
        ENDPARSE(&nodes[temp]); //* / %
        AddExp(&nodes[temp]);
    }
    ChangeFellow(&nodes[temp], _RelExp);
}

void EqExp(Nodep father)
{
    // EqExp → RelExp | EqExp('==' | '!=') RelExp
    AddChildNode(father, _EqExp, curcount);
    int temp = count;
    RelExp(&nodes[temp]);
    while (getnow() == EQL || getnow() == NEQ)
    {
        ENDPARSE(&nodes[temp]); //* / %
        RelExp(&nodes[temp]);
    }
    ChangeFellow(&nodes[temp], _EqExp);
}

void LAndExp(Nodep father)
{ // LAndExp → EqExp | LAndExp '&&' EqExp
    AddChildNode(father, _LAndExp, curcount);
    int temp = count;
    EqExp(&nodes[temp]);
    while (getnow() == AND || getnow() == LPARENT || getnow() == IDENFR || getnow() == INTCON || getnow() == CHRCON || getnow() == PLUS || getnow() == MINU || getnow() == NOT)
    {
        if (getnow() == AND)
            ENDPARSE(&nodes[temp]); //&&
        else
            AddNull(&nodes[temp]);
        EqExp(&nodes[temp]);
    }
    ChangeFellow(&nodes[temp], _LAndExp);
}

void LOrExp(Nodep father)
{ // LOrExp → LAndExp | LOrExp '||' LAndExp
    AddChildNode(father, _LOrExp, curcount);
    int temp = count;
    LAndExp(&nodes[temp]);
    while (getnow() == OR || getnow() == LPARENT || getnow() == IDENFR || getnow() == INTCON || getnow() == CHRCON || getnow() == PLUS || getnow() == MINU || getnow() == NOT)
    {
        if (getnow() == OR)
            ENDPARSE(&nodes[temp]); //&&
        else
            AddNull(&nodes[temp]);
        LAndExp(&nodes[temp]);
    }
    ChangeFellow(&nodes[temp], _LOrExp);
}

void ConstExp(Nodep father)
{ // ConstExp → AddExp
    AddChildNode(father, _ConstExp, curcount);
    int temp = count;
    AddExp(&nodes[temp]);
}

void ENDPARSE(Nodep father)
{
    AddChildNode(father, _ENDPARSE, curcount);
    curcount++;
}