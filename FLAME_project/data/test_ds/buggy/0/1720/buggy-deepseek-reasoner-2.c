#include<stdio.h>
main(void) // @@ [Missing return type int; should be 'int main(void)']
{
    char c[4],i; // @@ [Array size too small for input like 'a-uB-F'; i should be int to avoid overflow]
    gets(c); // @@ [Unsafe function; buffer overflow possible with longer input]
    for (i=c[0];i<=c[2];i++) // @@ [Logic incorrect; does not handle multiple hyphens or type checks; i as char may wrap]
        printf ("%c",i);
    return 0;
}