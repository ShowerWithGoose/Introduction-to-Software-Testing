#include<stdio.h>
main(void)
{
    char c[4],i;
    gets(c); // @@ [Using 'gets' is unsafe and deprecated; more critically, the buffer size 'c[4]' is too small for general input containing '-' expansions like "a-d", which requires at least 4 characters plus null terminator (5 total). Also, the program logic assumes input format like "X-Y" exactly 3 chars, but doesn't validate or handle longer inputs or cases where expansion shouldn't occur. Additionally, the loop prints from c[0] to c[2] inclusive regardless of whether they are valid same-type expandable characters, violating problem requirements.]
    for (i=c[0];i<=c[2];i++) // @@ [This loop always expands from first to third character inclusively without checking if they are of the same type (e.g., both lowercase, both digits, etc.) or if c[1] is even '-'. It also fails to handle cases where expansion should not happen (like 'a-R'), directly violating problem constraints.]
        printf ("%c",i);
    return 0;
}