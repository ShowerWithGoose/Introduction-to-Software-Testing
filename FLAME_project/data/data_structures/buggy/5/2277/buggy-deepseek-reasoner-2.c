#include <stdio.h>
#include <string.h>
int main(void)
{
    char c; // @@ [Variable should store polynomial terms, not single character]
    while ((c=getchar())!=EOF) // @@ [Should parse integer pairs from input, not characters]
        printf("%c",c); // @@ [Should compute and output polynomial product, not echo characters]
}