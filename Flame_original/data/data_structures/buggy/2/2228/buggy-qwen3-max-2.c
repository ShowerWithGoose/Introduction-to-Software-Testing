#include<stdio.h>
#include<string.h>
char s[10000];
int main()
{
    gets(s); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11. It can cause buffer overflow and leads to compilation errors with modern compilers that do not support it. Use 'fgets' instead.]
    puts(s);
    return 0;
}