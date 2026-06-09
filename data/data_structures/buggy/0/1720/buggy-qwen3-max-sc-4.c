#include<stdio.h>
main(void)
{
    char c[4],i;
    gets(c); // @@ [Using gets() is unsafe and may cause buffer overflow; also, the array size '4' is too small for general input containing '-' expansions, leading to undefined behavior. Additionally, the logic assumes input is always exactly 3 characters like "a-d", which fails for longer or shorter inputs.]
    for (i=c[0];i<=c[2];i++) // @@ [This loop incorrectly assumes the input format is always X-Y (3 characters), and blindly expands from c[0] to c[2] without checking if '-' is present, if types match, or if c[2] > c[0]. It also prints the entire range including endpoints, while the problem requires expanding only the characters between the two endpoints (excluding them in the expansion output, but the reference program actually includes the original characters via the final printf). However, more critically, this implementation does not handle cases where expansion should NOT occur (e.g., mixed types), violating the problem requirements.]
        printf ("%c",i);
    return 0;
}