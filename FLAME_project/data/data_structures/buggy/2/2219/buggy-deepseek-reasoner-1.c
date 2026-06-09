#include <stdio.h>
#include <string.h>
int num=0;
int main ()
{
    char ch[10005];
    char ch0[1005];
    gets(ch);
    for(int i,j=0;i<strlen(ch);i++) // @@ variable i is not initialized, leading to undefined behavior; also j is not correctly used to track the index for ch0
    {
        if(ch[i]!=' ')
        {
            ch0[j]=ch[i];
            j++;
        }
        if(ch0[i]>='0'&&ch0[i]<='9') // @@ accessing ch0 with index i, which is out of bounds and uninitialized; also logic does not correctly count digits
            num++;
        
    }
    if(num==(strlen(ch0)-1)) // @@ ch0 is not null-terminated, so strlen is undefined; the condition is logically incorrect for the problem
    {
        for(int k=0;k<strlen(ch0)-1;k++) // @@ same undefined strlen; also printing characters without performing any arithmetic
            printf("%c",ch0[k]);
    }
    
    return 0;
}