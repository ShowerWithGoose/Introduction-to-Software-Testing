#include<stdio.h>
main(void)
{
    char c[4],i; // @@ insufficient buffer size (only 4 bytes) for input like "a-uB-F", causing buffer overflow when gets() writes beyond.
    gets(c); // @@ gets() does not check buffer boundaries, leading to stack smashing for long input.
    for (i=c[0];i<=c[2];i++)
        printf ("%c",i);
    return 0;
}