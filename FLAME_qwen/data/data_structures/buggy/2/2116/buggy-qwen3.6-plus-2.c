#include<stdio.h>
#include<string.h>
char s[100];
int main()
{
    gets(s); // @@ gets() has been removed from the C11 standard and will cause a compilation error in modern compilers. Use fgets() instead.
    printf("%s",s);
    return 0;
}