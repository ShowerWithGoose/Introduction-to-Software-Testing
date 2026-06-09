#include<stdio.h>
main(void)
{
    char c[4],i; // @@ The array size is too small (4 bytes) to hold the input string "a-uB-F" (7 characters + null terminator), causing a buffer overflow when gets(c) is called. This leads to stack smashing. Additionally, the logic only handles a single expansion range, not multiple segments or mixed types as required.
    gets(c);
    for (i=c[0];i<=c[2];i++)
        printf ("%c",i);
    return 0;
}