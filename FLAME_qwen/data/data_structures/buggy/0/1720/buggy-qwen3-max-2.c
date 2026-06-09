#include<stdio.h>
main(void)
{
    char c[4],i;
    gets(c); // @@ [Using gets() is unsafe and may cause buffer overflow; also, the array size '4' is too small for general input containing '-' expansions like "a-z", which requires at least 4 characters but doesn't account for longer inputs or safety. Additionally, the program logic assumes input is always exactly 3 characters (e.g., "a-d"), which violates the problem's general input requirement.]
    for (i=c[0];i<=c[2];i++) // @@ [This loop expands from c[0] to c[2] inclusive regardless of whether '-' is present or if the characters are of the same type and valid. It fails to check if c[1] is '-', and does not validate character types (e.g., mixing letters and digits) or ordering (e.g., 'd'-'a' would loop backwards incorrectly). Also, if c[0] > c[2], it may cause infinite or undefined behavior due to signed char overflow.]
        printf ("%c",i);
    return 0;
}