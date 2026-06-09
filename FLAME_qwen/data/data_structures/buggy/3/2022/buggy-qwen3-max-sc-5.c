#include<stdio.h>
char sz1[200];
int main()
{
    gets(sz1); // @@ [The function 'gets' is unsafe and has been removed from the C standard library; it can cause buffer overflow. Additionally, in many modern compilers/environments, 'gets' is not available, leading to a compilation error.]
    puts(sz1);
    return 0;
}