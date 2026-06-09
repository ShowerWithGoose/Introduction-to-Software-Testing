#include<stdio.h>
main(void)
{
    char c[4],i;
    gets(c); // @@ [Using gets() is unsafe and may cause buffer overflow; also, the array size '4' is too small for general input containing '-' expansions, leading to undefined behavior. Additionally, the logic assumes input is always exactly 3 characters like "a-d", which fails for longer or shorter inputs.]
    for (i=c[0];i<=c[2];i++) // @@ [This loop incorrectly includes both endpoints and expands even when the characters are not of the same type or when end < start. It also does not check if c[1] is '-', violating problem requirements.]
        printf ("%c",i);
    return 0;
}