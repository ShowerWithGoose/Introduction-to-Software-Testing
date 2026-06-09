#include<stdio.h>
char sz1[200];
int main()
{
    gets(sz1); // @@ The 'gets' function has been removed from the C standard (C11) and causes a compilation error in modern compilers; 'fgets' should be used instead.
    puts(sz1);
    return 0;
}