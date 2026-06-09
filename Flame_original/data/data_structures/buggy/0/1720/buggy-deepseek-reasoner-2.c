#include<stdio.h>
main(void) // @@ Error: Missing return type 'int'. In C99 and later, implicit int is not allowed, causing compilation error.
{
    char c[4],i;
    gets(c); // @@ Warning: Unsafe function 'gets' can cause buffer overflow, and is removed in C11. Additionally, the array size 4 is insufficient for inputs longer than 3 characters.
    for (i=c[0];i<=c[2];i++) // @@ Error: Logic does not check that characters around '-' are of the same type (lowercase, uppercase, or digit) and that the second character is greater than the first. Also assumes input always has exactly three characters and ignores the dash itself.
        printf ("%c",i);
    return 0;
}