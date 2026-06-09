#include<stdio.h>
main(void)
{
    char c[4],i; // @@ [Buffer size is too small; input like "a-uB-F" exceeds 4 characters, causing buffer overflow and stack smashing]
    gets(c); // @@ [Using gets() with a small fixed buffer leads to buffer overflow on long inputs; also, gets() is unsafe and deprecated]
    for (i=c[0];i<=c[2];i++) // @@ [Only processes first three characters as if input is always of form "X-Y", ignoring rest of string and multiple ranges like "a-uB-F"]
        printf ("%c",i);
    return 0;
}