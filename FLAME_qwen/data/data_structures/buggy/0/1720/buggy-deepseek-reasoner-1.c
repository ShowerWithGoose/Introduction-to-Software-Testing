#include<stdio.h>
main(void) // @@ Missing return type; should be 'int main(void)' to comply with C99 and later standards, causing compilation error in strict mode.
{
    char c[4],i;
    gets(c);
    for (i=c[0];i<=c[2];i++)
        printf ("%c",i);
    return 0;
}