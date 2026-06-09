#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
enum SYMTYPE
{
    IDENFR = 0,
    INTCON = 1,
    STRCON = 2,
    CHRCON = 3,
    MAINTK = 4,
    CONSTTK = 5,
    INTTK = 6,
    CHARTK = 7,
    BREAKTK = 8,
    CONTINUETK = 9,
    IFTK = 10,
    ELSETK = 11,
    NOT = 12,
    AND = 13,
    OR = 14,
    FORTK = 15,
    GETINTTK = 16,
    GETCHARTK = 17,
    PRINTFTK = 18,
    RETURNTK = 19,
    PLUS = 20,
    MINU = 21,
    VOIDTK = 22,
    MULT = 23,
    DIV = 24,
    MOD = 25,
    LSS = 26,
    LEQ = 27,
    GRE = 28,
    GEQ = 29,
    EQL = 30,
    NEQ = 31,
    ASSIGN = 32,
    SEMICN = 33,
    COMMA = 34,
    LPARENT = 35,
    RPARENT = 36,
    LBRACK = 37,
    RBRACK = 38,
    LBRACE = 39,
    RBRACE = 40
};
string names[50] = {"IDENFR",
                    "INTCON",
                    "STRCON",
                    "CHRCON",
                    "MAINTK",
                    "CONSTTK",
                    "INTTK",
                    "CHARTK",
                    "BREAKTK",
                    "CONTINUETK",
                    "IFTK",
                    "ELSETK",
                    "NOT",
                    "AND",
                    "OR",
                    "FORTK",
                    "GETINTTK",
                    "GETCHARTK",
                    "PRINTFTK",
                    "RETURNTK",
                    "PLUS",
                    "MINU",
                    "VOIDTK",
                    "MULT",
                    "DIV",
                    "MOD",
                    "LSS",
                    "LEQ",
                    "GRE",
                    "GEQ",
                    "EQL",
                    "NEQ",
                    "ASSIGN",
                    "SEMICN",
                    "COMMA",
                    "LPARENT",
                    "RPARENT",
                    "LBRACK",
                    "RBRACK",
                    "LBRACE",
                    "RBRACE"};
struct TOKENS
{
    SYMTYPE sym;
    string token;
} tokens[100000];
int curcount = 0;
FILE *infile;
FILE *outfile;
FILE *errfile;
char curchar;
char curline[1024];
int currow = 0;
int curcoln = 0;
string token;
SYMTYPE symbol;
void retract()
{
    if (curcoln > 0)
    {
        curcoln--;
        curchar = curline[curcoln - 1];
    }
}
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
        {
            retract();
            return -1;
        }
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
SYMTYPE reserver()
{
    if (token == "main")
    {
        return MAINTK;
    }
    else if (token == "const")
    {
        return CONSTTK;
    }
    else if (token == "int")
    {
        return INTTK;
    }
    else if (token == "char")
    {
        return CHARTK;
    }
    else if (token == "break")
    {
        return BREAKTK;
    }
    else if (token == "continue")
    {
        return CONTINUETK;
    }
    else if (token == "if")
    {
        return IFTK;
    }
    else if (token == "else")
    {
        return ELSETK;
    }
    else if (token == "for")
    {
        return FORTK;
    }
    else if (token == "getint")
    {
        return GETINTTK;
    }
    else if (token == "getchar")
    {
        return GETCHARTK;
    }
    else if (token == "printf")
    {
        return PRINTFTK;
    }
    else if (token == "return")
    {
        return RETURNTK;
    }
    else if (token == "void")
    {
        return VOIDTK;
    }
    return IDENFR;
}
int transNum()
{
    return stoi(token);
}
void err()
{
    fprintf(errfile, "%d a\n", currow);
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
                return -1;
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
                return -1;
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
        {
            symbol = NOT;
            return -1;
        }
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
        {
            symbol = LSS;
            return -1;
        }
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
        {
            symbol = GRE;
            return -1;
        }
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
        {
            symbol = ASSIGN;
            return -1;
        }
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
        {
            symbol = DIV;
            return -1;
        }
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
            err();
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
            err();
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
            err();
            return -2;
        }
        catToken();
        symbol = OR;
    }
    return 0;
}
int main()
{
    infile = fopen("testfile.txt", "r");
    outfile = fopen("lexer.txt", "w");
    errfile = fopen("error.txt", "w");
    int r = 0;
    int error = 0;
    while ((r = getsymbol()) != -1)
    {
        if (r == 0)
        {
            tokens[curcount].sym = symbol;
            tokens[curcount].token = token;
            curcount++;
        }
        else
            error = 1;
    }
    if (!token.empty())
    {

        if ((isAnd() || isOr()))
            err();
        else
        {
            tokens[curcount].sym = symbol;
            tokens[curcount].token = token;
            curcount++;
        }
    }
    if (!error)
    {
        for (int i = 0; i < curcount; i++)
        {
            fprintf(outfile, "%s %s\n", names[tokens[i].sym].c_str(), tokens[i].token.c_str());
        }
    }
    fclose(infile);
    fclose(outfile);
    fclose(errfile);
}