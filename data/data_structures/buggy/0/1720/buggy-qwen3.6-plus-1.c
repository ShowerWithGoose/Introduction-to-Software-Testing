#include<stdio.h>
main(void) // @@ Missing return type 'int' for the main function, which causes a compilation error in C99 and later standards.
{
    char c[4],i;
    gets(c);
    for (i=c[0];i<=c[2];i++)
        printf ("%c",i);
    return 0;
}