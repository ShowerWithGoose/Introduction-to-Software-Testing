#include <all.h>

std::ofstream errfile("error.txt");
void jerr(int n)
{
    errfile << tks[n - 1].line << " j" << std::endl;
}
void kerr(int n)
{
    errfile << tks[n - 1].line << " k" << std::endl;
}
void ierr(int n)
{
    errfile << tks[n - 1].line << " i" << std::endl;
}
void aerr(int n)
{
    errfile << n << " a" << std::endl;
}