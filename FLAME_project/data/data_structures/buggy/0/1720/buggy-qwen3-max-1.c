#include<stdio.h>
main(void)
{
    char c[4],i;
    gets(c); // @@ [Buffer overflow: input string like "a-uB-F" exceeds 4 characters, causing stack smashing]
    for (i=c[0];i<=c[2];i++) // @@ [Incorrect logic: only handles first three characters and ignores rest of input; assumes fixed format like "x-y"]
        printf ("%c",i);
    return 0;
}