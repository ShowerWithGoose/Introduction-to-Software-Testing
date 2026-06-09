#include<stdio.h>
char sz1[200];
int main()
{
    gets(sz1); // @@ gets() is unsafe and removed from C11 standard; use fgets() instead.
    puts(sz1);
    return 0;
}