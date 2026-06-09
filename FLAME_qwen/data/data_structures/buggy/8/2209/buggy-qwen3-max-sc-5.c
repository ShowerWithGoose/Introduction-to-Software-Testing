#include <stdio.h>

int main()
{
    char s[100] = "";
    while (gets(s) != NULL) // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; many compilers no longer support it, leading to a compilation error. Additionally, the reference program also uses 'gets', but modern environments may lack it entirely, causing "gcc: not found" or implicit declaration errors during compilation.]
        puts(s);
    return 0;
}