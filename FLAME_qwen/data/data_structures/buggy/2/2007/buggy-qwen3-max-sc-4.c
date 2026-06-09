#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
char a[10000];
int main()
{
    gets(a); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11. It can cause buffer overflow and leads to undefined behavior. Most modern compilers (like GCC) will refuse to compile code using 'gets' unless explicitly allowed, which explains the compilation error. Use 'fgets' instead.]
    puts(a);
    return 0;
}