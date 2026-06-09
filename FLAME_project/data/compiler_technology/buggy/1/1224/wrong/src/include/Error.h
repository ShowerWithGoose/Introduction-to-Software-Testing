#ifndef _ERROR_H_
#define _ERROR_H_
// Error.cpp
extern int error;

typedef struct Error
{
    int line;
    char errorType;
} Error;

void err(char, int);
void errPrint();
#endif