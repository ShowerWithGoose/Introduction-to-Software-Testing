#ifndef MYHEADER_H
#define MYHEADER_H

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
/*extern std::ifstream file;
extern std::ofstream outfile;
extern std::ofstream errfile;
extern std::ofstream wenfafile;*/
enum tokentype
{
    IDENFR,
    INTCON,
    STRCON,
    CHRCON,
    MAINTK,
    CONSTTK,
    INTTK,
    CHARTK,
    BREAKTK,
    CONTINUETK,
    IFTK,
    ELSETK,
    NOT,
    AND,
    OR,
    FORTK,
    GETINTTK,
    GETCHARTK,
    PRINTFTK,
    RETURNTK,
    PLUS,
    MINU,
    VOIDTK,
    MULT,
    DIV,
    MOD,
    LSS,
    LEQ,
    GRE,
    GEQ,
    EQL,
    NEQ,
    ASSIGN,
    SEMICN,
    COMMA,
    LPARENT,
    RPARENT,
    LBRACK,
    RBRACK,
    LBRACE,
    RBRACE
};
inline std::string tokenTypeToString(tokentype t)
{
    switch (t)
    {
    case IDENFR:
        return "IDENFR";
    case INTCON:
        return "INTCON";
    case STRCON:
        return "STRCON";
    case CHRCON:
        return "CHRCON";
    case MAINTK:
        return "MAINTK";
    case CONSTTK:
        return "CONSTTK";
    case INTTK:
        return "INTTK";
    case CHARTK:
        return "CHARTK";
    case BREAKTK:
        return "BREAKTK";
    case CONTINUETK:
        return "CONTINUETK";
    case IFTK:
        return "IFTK";
    case ELSETK:
        return "ELSETK";
    case NOT:
        return "NOT";
    case AND:
        return "AND";
    case OR:
        return "OR";
    case FORTK:
        return "FORTK";
    case GETINTTK:
        return "GETINTTK";
    case GETCHARTK:
        return "GETCHARTK";
    case PRINTFTK:
        return "PRINTFTK";
    case RETURNTK:
        return "RETURNTK";
    case PLUS:
        return "PLUS";
    case MINU:
        return "MINU";
    case VOIDTK:
        return "VOIDTK";
    case MULT:
        return "MULT";
    case DIV:
        return "DIV";
    case MOD:
        return "MOD";
    case LSS:
        return "LSS";
    case LEQ:
        return "LEQ";
    case GRE:
        return "GRE";
    case GEQ:
        return "GEQ";
    case EQL:
        return "EQL";
    case NEQ:
        return "NEQ";
    case ASSIGN:
        return "ASSIGN";
    case SEMICN:
        return "SEMICN";
    case COMMA:
        return "COMMA";
    case LPARENT:
        return "LPARENT";
    case RPARENT:
        return "RPARENT";
    case LBRACK:
        return "LBRACK";
    case RBRACK:
        return "RBRACK";
    case LBRACE:
        return "LBRACE";
    case RBRACE:
        return "RBRACE";
    default:
        return "UNKNOWN_TOKEN";
    }
}
struct token
{
    tokentype type;
    std::string content;
    int line;
};

extern std::vector<struct token> tks;

void cifa();
void wenfa();
/*struct compunit
{
    std::vector<struct decl> decl;
    std::vector<struct funcdef> funcdef;
    struct mainfunc mainfunc;
};
enum btype
{
    INT,
    CHAR
};
enum vardeftype
{
    CONSTANDARRY,
    CONST,
    ARRY,
    NOCONSTNOARRY
};
enum initvaltype
{
    EXP,
    STRING
};
struct varinitval
{
    initvaltype i;
    union
    {
        std::vector<struct exp> e;
        std::string stringconst;
    } data;
};

struct vardef
{
    vardeftype v;
    std::string ident;
    struct constexp c;
    varinitval varinitv;
};
struct constexp
{
};
struct mainfunc
{
};
enum typeofdecl
{
    CONSTDECL,
    VARDECL
};
struct decl
{
    typeofdecl t;
    btype b;
    union
    {
        vardecl vardecl;
        constdecl constdecl;
    } d;
};
struct vardecl
{
    btype b;
    std::vector<struct vardef> vardef;
};
struct constdecl
{
    btype b;
    std::vector<struct constdef> constdef;
};
enum constdeftype
{
    ARRY,
    NOARRY
};
struct constdef
{
    constdeftype v;
    std::string ident;
    struct constexp c;
    struct constinitval initv;
};
enum constinittype
{
    CONSTEXP,
    STRING
};
struct constinitval
{
    constinittype i;
    union
    {
        std::vector<struct exp> e;
        std::string stringconst;
    } data;
};
enum functype
{
    VOID,
    INT,
    CHAR
};
struct funcdef
{
    functype t;
    std::string ident;
    struct funcparams p;
    struct block b;
};
struct funcparams
{
    std::vector<struct funcparam> param;
};
struct funcparam
{
    btype b;
    std::string ident;
    bool isarry;
};
struct block
{
    std::vector<struct blockitem> b;
};
struct blockitem
{
    enum
    {
        DECL,
        STMT
    } e;
    union
    {
        struct decl d;
        struct stmt s;
    } data;
};
struct stmt
{
    enum
    {
        ASSIGN,
        GETINT,
        GETCHAR,
        IF,
        FOR,
        BREAK,
        CONTINUE,
        RETURN,
        PRINTF,
        EXP,
        BLOCK,
    };
    union
    {
        struct assign assign;
        struct exp exp;
        struct block block;
        struct ifblock ifb;
        struct forblock forb;
        struct breakblock breakblock;
        struct continueblock continueb;
        struct returnblock areturn;
        struct getintblock getaint;
        struct getcharblock getachar;
        struct printfblock printfb;
    } data;
};
struct assign
{
};
struct exp
{
};
struct block
{
};
struct ifblock
{
};
struct forblock
{
};
struct breakblock
{
};
struct continueblock
{
};
struct returnblock
{
};
struct getintblock
{
};
struct getcharblock
{
};
struct printfblock
{
};
*/
void jerr(int n);
void kerr(int n);
void ierr(int n);
void aerr(int n);
#endif