#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <cctype>
#include "include/Lexer.h"
#include "include/Type.h"
#include "include/Error.h"
#include "include/File.h"
using namespace std;
// 共享变量初始化
SYMTYPE symbol;
std::string token;
int currow = 0;

char curchar;
char curline[1024];
int line = 0;
int curcoln = 0;
int num = 0;

int getchar()
{
    if (strlen(curline) == 0)
    {
        if (fgets(curline, 1024, infile) == NULL)
            return -1;
        currow++;
        curcoln = 0;
    }
    curchar = curline[curcoln];
    curcoln++;
    if (curchar == '\0')
    {

        if (fgets(curline, 1024, infile) == NULL)
            return -1;
        currow++;
        curcoln = 0;
        curchar = curline[curcoln];
        curcoln++;
    }

    return 0;
}
bool isSpace()
{
    return curchar == ' ';
}
bool isNewline()
{
    return curchar == '\n';
}
bool isTab()
{
    return curchar == '\t';
}
bool isComma()
{
    return curchar == ',';
}
bool isSemi()
{
    return curchar == ';';
}
bool isEqu()
{
    return curchar == '=';
}
bool isPlus()
{
    return curchar == '+';
}
bool isMinus()
{
    return curchar == '-';
}
bool isDivi()
{
    return curchar == '/';
}
bool isStar()
{
    return curchar == '*';
}
bool isLpar()
{
    return curchar == '(';
}
bool isRpar()
{
    return curchar == ')';
}
bool isLbk()
{
    return curchar == '[';
}
bool isRbk()
{
    return curchar == ']';
}
bool isLbe()
{
    return curchar == '{';
}
bool isRbe()
{
    return curchar == '}';
}
bool isMod()
{
    return curchar == '%';
}
bool isNot()
{
    return curchar == '!';
}
bool isLess()
{
    return curchar == '<';
}
bool isGreater()
{
    return curchar == '>';
}
bool isAnd()
{
    return curchar == '&';
}
bool isOr()
{
    return curchar == '|';
}
void catToken()
{
    token.push_back(curchar);
}
void retract()
{
    if (curcoln > 0)
    {
        curcoln--;
        curchar = curline[curcoln - 1];
    }
}
int transNum()
{
    return stoi(token);
}

int getsymbol()
{ // 0为正常，-1为结束，-2为错误
    token.clear();
    if (getchar() == -1)
        return -1;
    while (isSpace() || isNewline() || isTab())
    {
        if (getchar() == -1)
            return -1;
    }
    if (isalpha(curchar) || curchar == '_')
    {
        while (isalpha(curchar) || isdigit(curchar) || curchar == '_')
        {
            catToken();
            if (getchar() == -1)
            {
                symbol = reserver();
                return -3;
            }
        }
        retract();

        symbol = reserver();
    }
    else if (isdigit(curchar))
    { // 这里暂时没有关注前导零
        while (isdigit(curchar))
        {
            catToken();
            if (getchar() == -1)
            {
                symbol = INTCON;
                return -3;
            }
        }
        retract();
        symbol = INTCON;
    }
    else if (isPlus())
    {
        catToken();
        symbol = PLUS;
    }
    else if (isMinus())
    {
        catToken();
        symbol = MINU;
    }
    else if (isStar())
    {
        catToken();
        symbol = MULT;
    }
    else if (isLpar())
    {
        catToken();
        symbol = LPARENT;
    }
    else if (isRpar())
    {
        symbol = RPARENT;
        catToken();
    }
    else if (isLbk())
    {
        symbol = LBRACK;
        catToken();
    }
    else if (isRbk())
    {
        symbol = RBRACK;
        catToken();
    }
    else if (isLbe())
    {
        symbol = LBRACE;
        catToken();
    }
    else if (isRbe())
    {
        symbol = RBRACE;
        catToken();
    }
    else if (isComma())
    {
        symbol = COMMA;
        catToken();
    }
    else if (isSemi())
    {
        symbol = SEMICN;
        catToken();
    }
    else if (isMod())
    {
        symbol = MOD;
        catToken();
    }
    else if (isNot())
    {
        catToken();
        if (getchar() == -1)
            return -1;
        if (isEqu())
        {
            symbol = NEQ;
            catToken();
        }
        else
        {
            retract();
            symbol = NOT;
        }
    }
    else if (isLess())
    {
        catToken();
        if (getchar() == -1)
            return -1;
        if (isEqu())
        {
            catToken();
            symbol = LEQ;
        }
        else
        {
            retract();
            symbol = LSS;
        }
    }
    else if (isGreater())
    {
        catToken();
        if (getchar() == -1)
            return -1;
        if (isEqu())
        {
            catToken();
            symbol = GEQ;
        }
        else
        {
            retract();
            symbol = GRE;
        }
    }
    else if (isEqu())
    {
        catToken();
        if (getchar() == -1)
            return -1;
        if (isEqu())
        {
            catToken();
            symbol = EQL;
        }
        else
        {
            retract();
            symbol = ASSIGN;
        }
    }
    else if (isDivi())
    {
        catToken();
        if (getchar() == -1)
            return -1;
        if (isStar())
        { // 这里解决多行注释
            do
            {
                do
                {
                    if (getchar() == -1)
                        return -1;
                } while (!isStar());
                do
                {
                    if (getchar() == -1)
                        return -1;
                    if (isDivi())
                        return getsymbol();
                } while (isStar());

            } while (!isStar());
        }
        else if (isDivi())
        {
            do
            {
                if (getchar() == -1)
                    return -1;
                if (isNewline())
                    return getsymbol();
            } while (!isNewline());
        }
        retract();
        symbol = DIV;
    }
    else if (curchar == '\"')
    {
        catToken();
        do
        {

            if (getchar() == -1)
                return -1;
            catToken();
        } while (curchar != '\"');

        symbol = STRCON;
    }
    else if (curchar == '\'')
    {
        catToken();
        if (getchar() == -1)
            return -1;
        catToken();
        if (curchar == '\\')
        {
            if (getchar() == -1)
                return -1;
            catToken();
        }
        if (getchar() == -1)
            return -1;
        if (curchar != '\'')
        {
            err('a', currow);
            return -2;
        }
        catToken();
        symbol = CHRCON;
    }
    else if (isAnd())
    {
        catToken();
        if (getchar() == -1)
            return -1;
        if (!isAnd())
        {
            err('a', currow);
            return -2;
        }
        catToken();
        symbol = AND;
    }
    else if (isOr())
    {
        catToken();
        if (getchar() == -1)
            return -1;
        if (!isOr())
        {
            err('a', currow);
            return -2;
        }
        catToken();
        symbol = OR;
    }
    return 0;
}
void allTokenGets()
{
    int r = 0;
    while ((r = getsymbol()) != -1)
    {
        if (r == 0)
        {
            tokens[tokenNum].sym = symbol;
            tokens[tokenNum].token = token;
            tokens[tokenNum].line = currow;
            tokenNum++;
        }
        if (r == -3)
        {
            tokens[tokenNum].sym = symbol;
            tokens[tokenNum].token = token;
            tokens[tokenNum].line = currow;
            tokenNum++;
            break;
        }
    }
}
