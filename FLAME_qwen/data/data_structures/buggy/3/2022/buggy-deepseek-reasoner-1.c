#include<stdio.h>
char sz1[200];
int main()
{
    gets(sz1); // @@ [gets is unsafe and deprecated in C11; may cause compilation error in strict standards]
    puts(sz1);
    return 0;
}