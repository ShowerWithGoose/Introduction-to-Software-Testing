#include<stdio.h>
char sz1[200];
int main()
{
    gets(sz1); // @@ [gets() has been removed from the C11 standard and will cause a compilation error in modern compilers; it is also unsafe as it does not perform bounds checking]
    puts(sz1);
    return 0;
}