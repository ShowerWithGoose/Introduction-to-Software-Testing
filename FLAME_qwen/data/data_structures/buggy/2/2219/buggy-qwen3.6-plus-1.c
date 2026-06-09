#include <stdio.h>
#include <string.h>
int num=0;
int main ()
{
    char ch[10005];
    char ch0[1005];
    gets(ch); // @@ `gets` is removed in the C11 standard, causing a compilation error on modern compilers; it is also unsafe and does not handle the trailing '=' or input termination properly.
    for(int i,j=0;i<strlen(ch);i++) // @@ Variable `i` is declared but not initialized, leading to undefined behavior and potential compilation errors when used in the loop condition.
    {
        if(ch[i]!=' ')
        {
            ch0[j]=ch[i];
            j++;
        }
        if(ch0[i]>='0'&&ch0[i]<='9') // @@ Logic error: accesses `ch0` at index `i` instead of `j` or `ch[i]`; `ch0` is not null-terminated and `i` may exceed bounds due to skipped spaces.
            num++;
        
    }
    if(num==(strlen(ch0)-1)) // @@ `ch0` lacks a null terminator, making `strlen(ch0)` undefined behavior; the logic does not evaluate the arithmetic expression as required by the problem.
    {
        for(int k=0;k<strlen(ch0)-1;k++) // @@ `strlen` on an un-terminated string causes undefined behavior; the program merely prints characters instead of calculating and outputting the integer result.
            printf("%c",ch0[k]);
    }
    
    return 0;
}