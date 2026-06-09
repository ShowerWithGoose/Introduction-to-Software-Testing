#include <all.h>
int i = 0;


std::ofstream wenfafile("parser.txt");
void pttk()
{
    if(tks[i].content=="&")
    {
        tks[i].content="&&";
    }
    else if(tks[i].content=="|")
    {
        tks[i].content="||";
    }
    wenfafile << tokenTypeToString(tks[i].type) << " " << tks[i].content << std::endl;
    i++;
}
void opmain();
void opfuncdef();
void opdecl();
void opconstdecl();
void opvardecl();
void opconstdef();
void opconstexp();
void opaddexp();
void opmulexp();
void opunaryexp();
void opexp();
void opunaryop();
void opprimaryexp();
void oplorexp();
void oplandexp();
void opeqexp();
void oprelexp();
void opvardef();
void opinitval();
void opblock();
void opfunctype();
void opblockitem();
void opstmt();
void opif();
void opfor();
void opbreak();
void opcontinue();
void opreturn();
void opprintf();
void opgetint();
void opgetchar();
void oplvalandexp();
void opforstmt();
void judge()
{
    int j = i;
    if (tks[j + 1].type == MAINTK)
    {
        opmain();
    }
    else if (tks[j + 2].type == LPARENT)
    {
        opfuncdef();
    }
    else
    {
        opdecl();
    }
}
void opdecl()
{
    if (tks[i].type == CONSTTK)
    {
        opconstdecl();
    }
    else
    {
        opvardecl();
    }
}
void opbtype()
{
    pttk();
}
void opconstdecl()
{
    pttk();
    opbtype();
    opconstdef();
    while (tks[i].type == COMMA)
    {
        pttk();
        opconstdef();
    }
    if (tks[i].type == SEMICN)
    {
        pttk();
    }
    else
    {
        ierr(i);
    }
    wenfafile << "<ConstDecl>" << std::endl;
}
void opconstinitval()
{
    if (tks[i].type == STRCON)
    {
        pttk();
    }
    else if (tks[i].type == LBRACE)
    {
        pttk();
        if (tks[i].type == RBRACE)
        {
            pttk();
        }
        else
        {
            opconstexp();
            while (tks[i].type == COMMA)
            {
                pttk();
                opconstexp();
            }
            pttk();
        }
    }
    else
    {
        opconstexp();
    }
    wenfafile << "<ConstInitVal>" << std::endl;
}
void opconstdef()
{
    pttk();
    if (tks[i].type == LBRACK)
    {
        pttk();
        opconstexp();
        if (tks[i].type == RBRACK)
        {
            pttk();
        }
        else
        {
            kerr(i);
        }
        pttk();
        opconstinitval();
    }
    else
    {
        pttk();
        opconstinitval();
    }
    wenfafile << "<ConstDef>" << std::endl;
}

void opconstexp()
{
    opaddexp();
    wenfafile << "<ConstExp>" << std::endl;
}
void opaddexp()
{
    opmulexp();
    while (tks[i].type == PLUS || tks[i].type == MINU)
    {
        wenfafile << "<AddExp>" << std::endl;
        pttk();
        opmulexp();
    }
    wenfafile << "<AddExp>" << std::endl;
}
void opmulexp()
{
    opunaryexp();
    while (tks[i].type == DIV || tks[i].type == MULT||tks[i].type==MOD)
    {
        wenfafile << "<MulExp>" << std::endl;
        pttk();
        opunaryexp();
    }
    wenfafile << "<MulExp>" << std::endl;
}
void opfuncrparams()
{
    opexp();
    printf("1");
    while (tks[i].type == COMMA)
    {
        pttk();
        opexp();
    }
    wenfafile << "<FuncRParams>" << std::endl;
}
void opunaryexp()
{
    if (tks[i].type == IDENFR&&tks[i+1].type==LPARENT)
    {
        pttk();
        pttk();
        //
        if (tks[i].type == RPARENT)
        {
            pttk();
        }
        else if (tks[i].type == IDENFR || tks[i].type == CHRCON || tks[i].type == STRCON || tks[i].type == INTCON||tks[i].type==LPARENT||tks[i].type==PLUS)
        {
            opfuncrparams();
            if (tks[i].type == RPARENT)
            {
                pttk();
            }
            else
            {
                jerr(i);
            }
        }
        else
        {
            jerr(i);
        }
    }
    else if (tks[i].type == PLUS || tks[i].type == MINU || tks[i].type == NOT)
    {
        opunaryop();
        opunaryexp();
    }
    else
    {
        opprimaryexp();
    }
    wenfafile << "<UnaryExp>" << std::endl;
}
void opunaryop()
{
    pttk();
    wenfafile << "<UnaryOp>" << std::endl;
}
void opnumber()
{
    pttk();
    wenfafile << "<Number>" << std::endl;
}
void opcharacter()
{
    pttk();
    wenfafile << "<Character>" << std::endl;
}
void opexp()
{
    opaddexp();
    wenfafile << "<Exp>" << std::endl;
}
void oplval()
{
    pttk();
    if (tks[i].type == LBRACK)
    {
        pttk();
        opexp();
        //printf("%s",(tks[i-1].content+tks[i].content+tks[i+1].content).c_str());
        if (tks[i].type == RBRACK)
        {
            pttk();
        }
        else
        {
            kerr(i);
        }
    }
    wenfafile << "<LVal>" << std::endl;
}
void opprimaryexp()
{
    if (tks[i].type == LPARENT)
    {
        pttk();
        opexp();
        if (tks[i].type == RPARENT)
        {
            pttk();
        }
        else
        {
            jerr(i);
        }
    }
    else if (tks[i].type == IDENFR)
    {
        oplval();
    }
    else if (tks[i].type == INTCON)
    {
        opnumber();
    }
    else if (tks[i].type == CHRCON)
    {
        opcharacter();
    }
    wenfafile << "<PrimaryExp>" << std::endl;
}

void opcond()
{
    oplorexp();
    wenfafile << "<Cond>" << std::endl;
}

void oplorexp()
{
    oplandexp();
    while (tks[i].type == OR)
    {
        wenfafile << "<LOrExp>" << std::endl;
        pttk();
        oplandexp();
    }
    wenfafile << "<LOrExp>" << std::endl;
}

void oplandexp()
{
    opeqexp();
    while (tks[i].type == AND)
    {
        wenfafile << "<LAndExp>" << std::endl;
        pttk();
        opeqexp();
    }
    wenfafile << "<LAndExp>" << std::endl;
}
void opeqexp()
{
    oprelexp();
    while (tks[i].type == EQL || tks[i].type == NEQ)
    {
        wenfafile << "<EqExp>" << std::endl;
        pttk();
        oprelexp();
    }
    wenfafile << "<EqExp>" << std::endl;
}
void oprelexp()
{
    opaddexp();
    while (tks[i].type == LSS || tks[i].type == GRE || tks[i].type == LEQ || tks[i].type == GEQ)
    {
        wenfafile << "<RelExp>" << std::endl;
        pttk();
        opaddexp();
    }
    wenfafile << "<RelExp>" << std::endl;
}
void opvardecl()
{
    opbtype();
    opvardef();
    while (tks[i].type == COMMA)
    {
        pttk();
        opvardef();
    }
    if (tks[i].type == SEMICN)
    {
        pttk();
    }
    else
    {
        ierr(i);
    }
    wenfafile << "<VarDecl>" << std::endl;
}
void opvardef()
{
    pttk();
    if (tks[i].type == LBRACK)
    {
        pttk();
        opconstexp();
        if (tks[i].type == RBRACK)
        {
            pttk();
        }
        else
        {
            kerr(i);
        }
        if (tks[i].type == ASSIGN)
        {
            pttk();
            opinitval();
        }
    }
    else
    {
        if (tks[i].type == ASSIGN)
        {
            pttk();
            opinitval();
        }
    }
    wenfafile << "<VarDef>" << std::endl;
}
void opinitval()
{
    if (tks[i].type == STRCON)
    {
        pttk();
    }
    else if (tks[i].type == LBRACE)
    {
        pttk();
        if (tks[i].type == RBRACE)
        {
            pttk();
        }
        else
        {
            opexp();
            while (tks[i].type == COMMA)
            {
                pttk();
                opexp();
            }
            pttk();
        }
    }
    else
    {
        opexp();
    }
    wenfafile << "<InitVal>" << std::endl;
}
void opfuncfparam()
{
    opbtype();
    pttk();
    if (tks[i].type == LBRACK)
    {
        pttk();
        if (tks[i].type == RBRACK)
        {
            pttk();
        }
        else
        {
            kerr(i);
        }
    }
    wenfafile << "<FuncFParam>" << std::endl;
}
void opfuncfparams()
{
    opfuncfparam();
    while (tks[i].type == COMMA)
    {
        pttk();
        opfuncfparam();
    }
    wenfafile << "<FuncFParams>" << std::endl;
}
void opfuncdef()
{
    opfunctype();
    pttk();
    pttk();
    if (tks[i].type == LBRACE)
    {
        jerr(i);
        opblock();
    }
    else if (tks[i].type == RPARENT)
    {
        pttk();
        opblock();
    }
    else
    {
        opfuncfparams();
        if (tks[i].type == LBRACE)
        {
            jerr(i);
            opblock();
        }
        else if (tks[i].type == RPARENT)
        {
            pttk();
            opblock();
        }
    }
    wenfafile << "<FuncDef>" << std::endl;
}
void opfunctype()
{
    pttk();
    wenfafile << "<FuncType>" << std::endl;
}
void opblock()
{
    pttk();
    while (tks[i].type != RBRACE)
    {
        opblockitem();
    }
    pttk();
    wenfafile << "<Block>" << std::endl;
}
void opblockitem()
{
    if (tks[i].type == INTTK || tks[i].type == CONSTTK || tks[i].type == CHARTK)
    {
        opdecl();
    }
    else
    {
        opstmt();
    }
}
void opstmt()
{

    if (tks[i].type == IFTK)
    {
        opif();
    }
    else if (tks[i].type == FORTK)
    {
        opfor();
    }
    else if (tks[i].type == BREAKTK)
    {
        opbreak();
    }
    else if (tks[i].type == CONTINUETK)
    {
        opcontinue();
    }
    else if (tks[i].type == RETURNTK)
    {
        opreturn();
    }
    else if (tks[i].type == LBRACE)
    {
        opblock();
    }
    else if (tks[i].type == PRINTFTK)
    {
        opprintf();
    }
    else if (tks[i + 2].type == GETINTTK)
    {
        opgetint();
    }
    else if (tks[i + 2].type == GETCHARTK)
    {
        opgetchar();
    }
    else
    {
        int aline=tks[i].line;
        int j=i;
        int flag=0;
        while (tks[j].line==aline)
        {
            if(tks[j].type==ASSIGN)
            {
                flag=1;
                break;
            }
            j++;
        }
        if(flag==1)
        {
            oplvalandexp();
        }
        else
        {
            if (tks[i].type == SEMICN)
            {
                pttk();
            }
            else
            {
                opexp();
                if (tks[i].type == SEMICN)
                {
                    pttk();
                }
                else
                {
                    ierr(i);
                }
            }
        }

    }
    wenfafile << "<Stmt>" << std::endl;
}
void opgetchar()
{
    oplval();
    pttk();
    pttk();
    pttk();
    if (tks[i].type == RPARENT)
    {
        pttk();
    }
    else
    {
        jerr(i);
    }
    if (tks[i].type == SEMICN)
    {
        pttk();
    }
    else
    {
        ierr(i);
    }
}
void opgetint()
{
    oplval();
    pttk();
    pttk();
    pttk();
    if (tks[i].type == RPARENT)
    {
        pttk();
    }
    else
    {
        jerr(i);
    }
    if (tks[i].type == SEMICN)
    {
        pttk();
    }
    else
    {
        ierr(i);
    }
}

void opprintf()
{
    pttk();
    pttk();
    pttk();
    while (tks[i].type == COMMA)
    {
        pttk();
        opexp();
    }
    if (tks[i].type == RPARENT)
    {
        pttk();
    }
    else
    {
        jerr(i);
    }
    if (tks[i].type == SEMICN)
    {
        pttk();
    }
    else
    {
        ierr(i);
    }
}
void opreturn()
{
    int line = tks[i].line;
    pttk();
    if (tks[i].line == line&&tks[i].type != SEMICN)
    {
        opexp();
    }
    if (tks[i].type == SEMICN)
    {
        pttk();
    }
    else
    {
        ierr(i);
    }
}
void opbreak()
{
    pttk();
    if (tks[i].type == SEMICN)
    {
        pttk();
    }
    else
    {
        ierr(i);
    }
}
void opcontinue()
{
    pttk();
    if (tks[i].type == SEMICN)
    {
        pttk();
    }
    else
    {
        ierr(i);
    }
}

void oplvalandexp()
{

    oplval();
    pttk();
    opexp();
    if (tks[i].type == SEMICN)
    {
        pttk();
    }
    else
    {
        ierr(i);
    }
}
void opif()
{
    pttk();
    pttk();
    opcond();
    if (tks[i].type == RPARENT)
    {
        pttk();
    }
    else
    {
        jerr(i);
    }
    opstmt();
    if (tks[i].type == ELSETK)
    {
        pttk();
        opstmt();
    }
}
void opfor()
{
    pttk();
    pttk();
    if (tks[i].type == SEMICN)
    {
        pttk();
    }
    else
    {
        opforstmt();
        pttk();
    }
    if (tks[i].type == SEMICN)
    {
        pttk();
    }
    else
    {
        opcond();
        pttk();
    }
    if (tks[i].type == RPARENT)
    {
        pttk();
    }
    else
    {
        opforstmt();
        pttk();
    }
    opstmt();
}
void opforstmt()
{
    oplval();
    pttk();
    opexp();
    wenfafile << "<ForStmt>" << std::endl;
}
void opmain()
{
    pttk();
    pttk();
    pttk();
    if (tks[i].type == RPARENT)
    {
        pttk();
    }
    else
    {
        jerr(i);
    }
    opblock();
    wenfafile << "<MainFuncDef>" << std::endl;
}
void wenfa()
{
    while (i < tks.size())
        judge();
    wenfafile << "<CompUnit>" << std::endl;
}
