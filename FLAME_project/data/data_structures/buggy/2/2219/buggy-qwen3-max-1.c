#include <stdio.h>
#include <string.h>
int num=0;
int main ()
{
    char ch[10005];
    char ch0[1005];
    gets(ch);
    for(int i,j=0;i<strlen(ch);i++) // @@ [Variable 'i' is uninitialized; loop behavior is undefined. Also, 'num' counts digits incorrectly by checking ch0[i] before it's fully built.]
    {
        if(ch[i]!=' ')
        {
            ch0[j]=ch[i];
            j++;
        }
        if(ch0[i]>='0'&&ch0[i]<='9') // @@ [Accessing ch0[i] is invalid because 'i' indexes the original string, but ch0 is filled only up to 'j'; also, this logic doesn't parse or evaluate the expression.]
            num++;
        
    }
    if(num==(strlen(ch0)-1)) // @@ [This condition assumes the entire expression is a single number, which fails for actual expressions with operators.]
    {
        for(int k=0;k<strlen(ch0)-1;k++) // @@ [This just prints the expression without '=' instead of evaluating it, violating the problem requirement.]
            printf("%c",ch0[k]);
    }
    
    return 0;
}