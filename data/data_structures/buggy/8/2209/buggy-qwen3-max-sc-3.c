#include <stdio.h>

int main()
{
    char s[100] = "";
    while (gets(s) != NULL) // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; many modern compilers no longer support it, leading to a compilation error.]
        puts(s);
    return 0;
}