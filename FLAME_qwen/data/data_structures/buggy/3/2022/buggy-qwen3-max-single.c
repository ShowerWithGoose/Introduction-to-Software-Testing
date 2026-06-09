#include<stdio.h>
char sz1[200];
int main()
{
    gets(sz1); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it can lead to buffer overflow vulnerabilities. Additionally, many modern compilers (like GCC) no longer support it by default, which likely caused the compilation error "gcc: not found" indirectly due to failed linking or compiler rejection.]
    puts(sz1);
    return 0;
}