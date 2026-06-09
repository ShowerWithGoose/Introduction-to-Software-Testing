#include<stdio.h>
char sz1[200];
int main()
{
    gets(sz1); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11 due to buffer overflow risks; using it may cause compilation errors with modern compilers.]
    puts(sz1);
    return 0;
}