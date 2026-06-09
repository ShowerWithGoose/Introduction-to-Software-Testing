#include <stdio.h>

int main()
{
    char s[100] = "";
    while (gets(s) != NULL) // @@ [gets() is unsafe and removed in C11; use fgets() instead]
        puts(s);
    return 0;
}