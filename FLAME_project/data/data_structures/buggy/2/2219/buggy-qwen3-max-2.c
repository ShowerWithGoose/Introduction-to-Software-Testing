#include <stdio.h>
#include <string.h>
int num=0;
int main ()
{
    char ch[10005];
    char ch0[1005];
    gets(ch);
    for(int i,j=0;i<strlen(ch);i++) // @@ [Variable 'i' is uninitialized; also, 'num' counts digits incorrectly by checking ch0[i] which may be out of bounds or uninitialized]
    {
        if(ch[i]!=' ')
        {
            ch0[j]=ch[i];
            j++;
        }
        if(ch0[i]>='0'&&ch0[i]<='9') // @@ [Accessing ch0[i] is wrong: 'i' indexes original string, but ch0 is compacted; should use 'j-1' or separate digit detection logic]
            num++;
        
    }
    if(num==(strlen(ch0)-1)) // @@ [Logic is fundamentally flawed: it assumes the entire expression is a single number if digit count equals length-1, ignoring operators entirely]
    {
        for(int k=0;k<strlen(ch0)-1;k++)
            printf("%c",ch0[k]); // @@ [This just prints the expression without '=' instead of evaluating it; completely ignores arithmetic operations]
    }
    
    return 0;
}