#include <stdio.h> 
#include<string.h>
int main()
{
    char s[500];
    while(gets(s)!=NULL) // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it can lead to buffer overflow vulnerabilities and may cause compilation errors with modern compilers.]
    {
        puts(s);
    }
    return 0;
}