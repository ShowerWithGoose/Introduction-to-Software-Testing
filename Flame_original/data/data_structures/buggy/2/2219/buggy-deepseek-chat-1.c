#include <stdio.h>
#include <string.h>
int num=0;
int main ()
{
    char ch[10005];
    char ch0[1005];
    gets(ch);
    for(int i,j=0;i<strlen(ch);i++) // @@ [Error: Variable 'i' is uninitialized, causing undefined behavior in the loop condition and array access]
    {
        if(ch[i]!=' ')
        {
            ch0[j]=ch[i];
            j++;
        }
        if(ch0[i]>='0'&&ch0[i]<='9') // @@ [Error: Using 'i' as index for ch0 is incorrect; should use 'j' to track the current position in ch0, and also ch0 may not have been assigned at index i]
            num++;
        
    }
    if(num==(strlen(ch0)-1)) // @@ [Error: ch0 is not null-terminated, so strlen(ch0) will cause undefined behavior]
    {
        for(int k=0;k<strlen(ch0)-1;k++) // @@ [Error: Same issue - ch0 is not null-terminated, strlen will not work correctly]
            printf("%c",ch0[k]);
    }
    
    return 0;
}