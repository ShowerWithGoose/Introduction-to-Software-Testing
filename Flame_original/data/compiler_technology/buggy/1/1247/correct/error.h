#ifndef COMPILER_ERROR_H
#define COMPILER_ERROR_H

#include<vector>

void f_panic(const char *file,int line)__attribute__((__noreturn__));

#define ast(expr) do{if(!(expr)) f_panic(__FILE__,__LINE__);}while(false)
#define panic() f_panic(__FILE__,__LINE__)

struct Error{
    int line;
    char ecode;
    Error(int line,char ecode):line(line),ecode(ecode){}
};

extern std::vector<Error>errors;

bool printErrors(const char *fn);

#endif
