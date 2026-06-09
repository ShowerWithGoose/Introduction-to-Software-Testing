#include <stdio.h> 
#include<string.h>
int main()
{
    char s[500];
    while(gets(s)!=NULL) // @@ [Compilation error: gets() is removed in C11 and later standards, causing compilation failure with modern compilers; also unsafe and does not solve the problem]
    {
        puts(s);
    }
    return 0;
}