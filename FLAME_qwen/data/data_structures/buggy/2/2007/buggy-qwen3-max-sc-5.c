#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
char a[10000];
int main()
{
    gets(a); // @@ [The function 'gets' is unsafe and has been removed from the C11 standard; it can cause buffer overflow. Additionally, in many modern environments, using 'gets' leads to compilation errors or warnings that may prevent successful compilation.]
    puts(a);
    return 0;
}