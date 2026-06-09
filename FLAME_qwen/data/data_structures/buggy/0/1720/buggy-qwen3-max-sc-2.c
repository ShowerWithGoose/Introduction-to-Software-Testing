#include<stdio.h>
main(void)
{
    char c[4],i;
    gets(c); // @@ [Using gets() is unsafe and may cause buffer overflow; also, the array size '4' is too small for general input containing '-' expansions, leading to undefined behavior. Additionally, the logic assumes input is always exactly 3 characters like "a-d", which fails for longer or irregular inputs.]
    for (i=c[0];i<=c[2];i++) // @@ [This loop incorrectly expands even when the characters are of different types (e.g., 'a' and 'D') or when the second character is not greater than the first. It also prints the entire range including endpoints, but the problem requires expansion only between the two characters (excluding endpoints) and only under specific conditions. Moreover, it does not handle cases where '-' appears multiple times or in invalid contexts.]
        printf ("%c",i);
    return 0;
}