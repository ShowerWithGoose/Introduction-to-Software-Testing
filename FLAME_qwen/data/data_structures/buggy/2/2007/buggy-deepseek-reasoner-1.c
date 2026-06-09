#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
char a[10000];
int main()
{
    gets(a); // @@ [gets is unsafe and removed in C11; may cause compilation error in strict mode]
    puts(a);
    return 0;
}