#include <all.h>


struct allerror e;
void jerr(int n)
{
    e.fault='j';
    e.line=tks[n-1].line;
    myerr.push_back(e);
}
void kerr(int n)
{
    e.fault='k';
    e.line=tks[n-1].line;
    myerr.push_back(e);
}
void ierr(int n)
{
    e.fault='i';
    e.line=tks[n-1].line;
    myerr.push_back(e);
}
void aerr(int n)
{
    e.fault='a';
    e.line=n;
    myerr.push_back(e);
}