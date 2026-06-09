#include <stdio.h>
#include <string.h>
int num=0;
int main ()
{
    char ch[10005];
    char ch0[1005];
    gets(ch);
    for(int i,j=0;i<strlen(ch);i++) // @@ [Error: Variable 'i' is uninitialized, leading to undefined behavior in the loop condition and array access.]
    {
        if(ch[i]!=' ')
        {
            ch0[j]=ch[i];
            j++;
        }
        if(ch0[i]>='0'&&ch0[i]<='9') // @@ [Error: Using 'i' as index for ch0 is incorrect; should use 'j' or a separate counter, as 'i' does not correspond to the position in ch0.]
            num++;
        
    }
    if(num==(strlen(ch0)-1)) // @@ [Error: ch0 is not null-terminated, so strlen(ch0) will cause undefined behavior.]
    {
        for(int k=0;k<strlen(ch0)-1;k++) // @@ [Error: Same issue as above; ch0 is not null-terminated.]
            printf("%c",ch0[k]);
    }
    
    return 0;
}