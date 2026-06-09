#include<stdio.h>
main(void)
{
    char c[4],i; // @@ Array size too small for input "a-uB-F", causing buffer overflow when reading with gets.
    gets(c); // @@ Buffer overflow: input string longer than 3 characters plus null terminator, leads to stack smashing.
    for (i=c[0];i<=c[2];i++)
        printf ("%c",i);
    return 0;
}