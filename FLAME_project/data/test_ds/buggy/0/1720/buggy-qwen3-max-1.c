#include<stdio.h>
main(void)
{
    char c[4],i;
    gets(c); // @@ [Buffer overflow: input string may exceed 3 characters plus null terminator, causing stack smashing]
    for (i=c[0];i<=c[2];i++) // @@ [Logic error: assumes fixed format like "a-u", but input can be longer and contain multiple segments like "a-uB-F"; also accesses c[2] without checking length]
        printf ("%c",i);
    return 0;
}