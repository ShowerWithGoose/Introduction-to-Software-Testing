#include<stdio.h>
#include<string.h>
int main()
{
    char s[500];
    while (gets(s)) // @@ [Using gets() is deprecated and can cause compilation errors in C11 or stricter standards; it is also unsafe and may lead to buffer overflow.]
    {
        puts(s);
    }
    return 0;
}