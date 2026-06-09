#include <stdio.h>
#include <string.h>
int num=0;
int main ()
{
    char ch[10005];
    char ch0[1005];
    gets(ch); // @@ [Using gets() is unsafe and may cause buffer overflow; also, the logic does not implement arithmetic expression evaluation as required]
    for(int i,j=0;i<strlen(ch);i++) // @@ [Variable 'i' is uninitialized, leading to undefined behavior]
    {
        if(ch[i]!=' ')
        {
            ch0[j]=ch[i];
            j++;
        }
        if(ch0[i]>='0'&&ch0[i]<='9') // @@ [Accessing ch0[i] before it's fully populated; index 'i' may exceed valid range of ch0]
            num++;
        
    }
    if(num==(strlen(ch0)-1)) // @@ [Logic incorrectly assumes number of digits equals length minus one; fails to parse or evaluate expression]
    {
        for(int k=0;k<strlen(ch0)-1;k++)
            printf("%c",ch0[k]); // @@ [Outputs characters instead of computing and printing the integer result of the expression]
    }
    
    return 0;
}