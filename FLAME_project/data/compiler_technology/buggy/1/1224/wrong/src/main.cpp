#include <iostream>
#include <bits/stdc++.h>

#include "include/Parser.h"
#include "include/Lexer.h"
#include "include/Type.h"
#include "include/Error.h"
#include "include/File.h"

// 共享变量初始化
int tokenNum = 0;
TOKENS tokens[1000000];
FILE *infile;
FILE *outfile;
FILE *errfile;

int main()
{
    infile = fopen("testfile.txt", "r");
    outfile = fopen("parser.txt", "w");
    errfile = fopen("error.txt", "w");
    int r = 0;
    allTokenGets();
    BuildTree();
    if (!error)
    {
        TreeToString();
    }
    else
    {
        errPrint();
    }
    fclose(infile);
    fclose(outfile);
    fclose(errfile);
}