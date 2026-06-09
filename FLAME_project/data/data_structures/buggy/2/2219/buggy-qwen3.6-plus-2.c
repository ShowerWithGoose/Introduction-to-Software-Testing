#include <stdio.h>
#include <string.h>
int num=0;
int main ()
{
    char ch[10005];
    char ch0[1005];
    gets(ch);
    for(int i,j=0;i<strlen(ch);i++) // @@ [Variable 'i' is uninitialized, leading to undefined behavior. It should be initialized to 0.]
    {
        if(ch[i]!=' ')
        {
            ch0[j]=ch[i];
            j++;
        }
        if(ch0[i]>='0'&&ch0[i]<='9') // @@ [Logic error: accessing ch0 with index 'i' which tracks original string position, not the compacted string position 'j'. Also, this logic doesn't parse or evaluate the expression.]
            num++;
        
    }
    if(num==(strlen(ch0)-1)) // @@ [The entire logic is flawed. It attempts to check if the input is a simple number but fails to handle operators or evaluate the arithmetic expression as required by the problem.]
    {
        for(int k=0;k<strlen(ch0)-1;k++)
            printf("%c",ch0[k]);
    }
    
    return 0;
}