#include<stdio.h>
main(void)
{
    char c[4],i;
    gets(c); // @@ [Using gets() is unsafe and may cause buffer overflow; also, the array size '4' is too small for general input containing '-' expansions, leading to undefined behavior. Additionally, the logic assumes input is always exactly 3 characters like "a-d", which fails for longer or shorter inputs.]
    for (i=c[0];i<=c[2];i++) // @@ [This loop incorrectly includes both endpoints and assumes c[1] is '-', but does not validate that c[1] is '-' or that c[0] and c[2] are of the same valid type (e.g., both lowercase, uppercase, or digits). It also fails to handle cases where expansion should not occur (e.g., 'a-R'), violating problem requirements.]
        printf ("%c",i);
    return 0;
}