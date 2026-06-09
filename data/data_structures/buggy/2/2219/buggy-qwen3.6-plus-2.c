#include <stdio.h>
#include <string.h>
int num=0;
int main ()
{
    char ch[10005];
    char ch0[1005];
    gets(ch); // @@ gets is removed in the C11 standard and causes compilation errors in modern environments; use fgets instead.
    for(int i,j=0;i<strlen(ch);i++) // @@ Variable i is declared but not initialized, causing undefined behavior and potential compilation errors; should be int i=0, j=0.
    {
        if(ch[i]!=' ')
        {
            ch0[j]=ch[i];
            j++;
        }
        if(ch0[i]>='0'&&ch0[i]<='9') // @@ Logic error: accesses ch0 with index i instead of j or ch[i]; ch0 is not null-terminated, leading to incorrect parsing.
            num++;
        
    }
    if(num==(strlen(ch0)-1)) // @@ ch0 lacks a null terminator, causing strlen to invoke undefined behavior; additionally, the logic fails to calculate the arithmetic expression as required.
    {
        for(int k=0;k<strlen(ch0)-1;k++) // @@ strlen on unterminated string causes undefined behavior; the loop merely prints characters instead of evaluating the expression.
            printf("%c",ch0[k]);
    }
    
    return 0;
}