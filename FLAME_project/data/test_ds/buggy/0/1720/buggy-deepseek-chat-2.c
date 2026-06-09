#include<stdio.h>
main(void)
{
    char c[4],i;
    gets(c);
    for (i=c[0];i<=c[2];i++)
        printf ("%c",i);
    return 0;
}