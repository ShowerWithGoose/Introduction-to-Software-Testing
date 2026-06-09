#include <stdio.h>
#include <string.h>
int num=0;
int main ()
{
    char ch[10005];
    char ch0[1005];
    gets(ch);
    for(int i,j=0;i<strlen(ch);i++) // @@ i is uninitialized; loop condition uses undefined value leading to undefined behavior
    {
        if(ch[i]!=' ')
        {
            ch0[j]=ch[i];
            j++;
        }
        if(ch0[i]>='0'&&ch0[i]<='9') // @@ uses index i on ch0 but ch0 is filled with index j, causing out-of-bounds access and incorrect digit counting
            num++;
        
    }
    if(num==(strlen(ch0)-1)) // @@ ch0 is not null-terminated, strlen behavior undefined; also the logic does not evaluate the expression
    {
        for(int k=0;k<strlen(ch0)-1;k++) // @@ same strlen issue; loop may access invalid memory
            printf("%c",ch0[k]);
    }
    
    return 0;
}