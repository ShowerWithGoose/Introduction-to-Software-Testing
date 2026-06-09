#include <stdio.h> 
#include<string.h>
int main()
{
    char s[500];
    while(gets(s)!=NULL) // @@ [gets() is unsafe and removed in C11; also, this program does not solve the problem, it just echoes input]
    {
        puts(s);
    }
    return 0;
}