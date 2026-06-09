#include <stdio.h>
#include <string.h>
int num=0;
int main ()
{
    char ch[10005];
    char ch0[1005];
    gets(ch);
    for(int i,j=0;i<strlen(ch);i++) // @@ [Error: Variable 'i' is uninitialized, leading to undefined behavior. Also, the loop condition uses 'i' which is not initialized, and the logic for copying characters is flawed.]
    {
        if(ch[i]!=' ')
        {
            ch0[j]=ch[i];
            j++;
        }
        if(ch0[i]>='0'&&ch0[i]<='9') // @@ [Error: 'i' is used as index for ch0, but ch0 is filled using 'j', so this accesses uninitialized or incorrect positions. Also, this logic does not correctly count digits in the expression.]
            num++;
        
    }
    if(num==(strlen(ch0)-1)) // @@ [Error: This condition is incorrect for evaluating the arithmetic expression. The program only outputs the expression without spaces if all characters except '=' are digits, which is not the intended behavior.]
    {
        for(int k=0;k<strlen(ch0)-1;k++)
            printf("%c",ch0[k]);
    }
    
    return 0;
}