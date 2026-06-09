#include<stdio.h>
main(void)
{
    char c[4],i;
    gets(c); // @@ [Buffer overflow: input string may exceed 3 characters plus null terminator, causing stack smashing]
    for (i=c[0];i<=c[2];i++) // @@ [Logic error: assumes fixed format "X-Y", ignores problem requirements like mixed ranges, same-type check, and general string processing]
        printf ("%c",i);
    return 0;
}