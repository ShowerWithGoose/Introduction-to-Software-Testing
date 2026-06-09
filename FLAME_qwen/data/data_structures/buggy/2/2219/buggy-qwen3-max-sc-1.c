#include <stdio.h>
#include <string.h>
int num=0;
int main ()
{
    char ch[10005];
    char ch0[1005];
    gets(ch); // @@ [Using gets() is unsafe and may not be available in modern compilers; also, the logic does not implement arithmetic evaluation as required]
    for(int i,j=0;i<strlen(ch);i++) // @@ [Variable 'i' is uninitialized, leading to undefined behavior]
    {
        if(ch[i]!=' ')
        {
            ch0[j]=ch[i];
            j++;
        }
        if(ch0[i]>='0'&&ch0[i]<='9') // @@ [Accessing ch0[i] before it's fully written; index 'i' may exceed valid range of ch0]
            num++;
        
    }
    if(num==(strlen(ch0)-1)) // @@ [Logic incorrectly assumes number of digits equals total non-space characters minus one; doesn't parse or evaluate expression]
    {
        for(int k=0;k<strlen(ch0)-1;k++)
            printf("%c",ch0[k]); // @@ [Outputs the expression without evaluating it, violating problem requirements]
    }
    
    return 0;
}