#include<stdio.h>
main(void)
{
    char c[4],i; // @@ Array size too small; buffer overflow when input string is longer than 3 characters.
    gets(c); // @@ Unsafe function; causes stack smashing due to buffer overflow.
    for (i=c[0];i<=c[2];i++)
        printf ("%c",i);
    return 0;
}