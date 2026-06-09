#include<stdio.h>
main(void)
{
    char c[4],i; // @@ The buffer size is too small (4 bytes) for the input "a-uB-F" (7 bytes + null terminator), causing a buffer overflow and stack smashing when gets() is called. Additionally, the logic only handles a single expansion range, ignoring the requirements for multiple ranges and mixed types.
    gets(c);
    for (i=c[0];i<=c[2];i++)
        printf ("%c",i);
    return 0;
}