#include<stdio.h>
char s[10000];
int main()
{
    gets(s); // @@ [gets is unsafe and removed in C11, may cause compilation error in strict standards; also environment lacks gcc compiler.]
    puts(s);
    return 0;
}