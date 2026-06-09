#include <stdio.h>
#include <string.h>
int num=0;
int main ()
{
    char ch[10005];
    char ch0[1005];
    gets(ch);
    for(int i,j=0;i<strlen(ch);i++) // @@ [Error: Variable i is uninitialized, leading to undefined behavior in the loop condition]
    {
        if(ch[i]!=' ')
        {
            ch0[j]=ch[i];
            j++;
        }
        if(ch0[i]>='0'&&ch0[i]<='9') // @@ [Error: Using ch0[i] instead of ch[i]; ch0 is not fully populated and index i may be out of bounds]
            num++;
        
    }
    if(num==(strlen(ch0)-1)) // @@ [Error: ch0 is not null-terminated, so strlen(ch0) may cause undefined behavior]
    {
        for(int k=0;k<strlen(ch0)-1;k++) // @@ [Error: Same issue with ch0 not being null-terminated]
            printf("%c",ch0[k]);
    }
    
    return 0;
}