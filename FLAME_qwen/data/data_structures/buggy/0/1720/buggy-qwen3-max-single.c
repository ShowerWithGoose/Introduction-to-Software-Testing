#include<stdio.h>
main(void)
{
    char c[4],i;
    gets(c); // @@ [Using gets() is unsafe and may cause buffer overflow; also, the array size is too small for general input]
    for (i=c[0];i<=c[2];i++) // @@ [Does not validate if input contains '-' at c[1]; assumes fixed 3-character format like "a-d"]
        printf ("%c",i);
    return 0;
}