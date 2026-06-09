#include <stdio.h>
#include <string.h>
int num=0;
int main ()
{
    char ch[10005];
    char ch0[1005];
    gets(ch);
    for(int i,j=0;i<strlen(ch);i++) // @@ [Variable 'i' is uninitialized, leading to undefined behavior. It should be initialized to 0, e.g., 'for(int i=0, j=0; ...']
    {
        if(ch[i]!=' ')
        {
            ch0[j]=ch[i];
            j++;
        }
        if(ch0[i]>='0'&&ch0[i]<='9') // @@ [Logic error: checking ch0[i] instead of ch[i] or the current character. Also, this logic does not parse or evaluate the expression.]
            num++;
        
    }
    if(num==(strlen(ch0)-1)) // @@ [Logic error: This condition and the subsequent block do not implement arithmetic evaluation. The program fails to calculate the result of the expression.]
    {
        for(int k=0;k<strlen(ch0)-1;k++)
            printf("%c",ch0[k]);
    }
    
    return 0;
}