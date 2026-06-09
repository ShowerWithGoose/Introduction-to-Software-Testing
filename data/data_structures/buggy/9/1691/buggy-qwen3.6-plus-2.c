#include<stdio.h>
#include<string.h>
int main()
{
    char s[500];
    while (gets(s)) // @@ The `gets` function was removed in the C11 standard and causes a compilation error in modern compilers due to inherent buffer overflow vulnerabilities. It should be replaced with `fgets`.
    {
        puts(s);
    }
    return 0;
}