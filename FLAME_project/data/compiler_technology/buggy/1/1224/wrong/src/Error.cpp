#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

#include "include/Error.h"
#include "include/Type.h"
#include "include/File.h"

Error errors[100000];
int error = 0;
int errorcount = 0;
void err(char errorType, int line)
{
    error = 1;
    errors[errorcount].line = line;
    errors[errorcount].errorType = errorType;
    ++errorcount;
}
void errPrint()
{
    std::sort(errors, errors + errorcount, [](const Error &a, const Error &b)
              {
                  return a.line < b.line; // 按 line 升序
              });
    for (int i = 0; i < errorcount; i++)
    {
        fprintf(errfile, "%d %c\n", errors[i].line, errors[i].errorType);
    }
}