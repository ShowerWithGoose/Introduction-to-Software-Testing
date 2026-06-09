#include <stdio.h>
#include <string.h>
int num=0;
int main ()
{
    char ch[10005];
    char ch0[1005];
    gets(ch); // @@ [Using gets() is unsafe and may not be available in modern compilers; also, the logic does not implement arithmetic expression evaluation as required]
    for(int i,j=0;i<strlen(ch);i++) // @@ [Variable 'i' is uninitialized, leading to undefined behavior]
    {
        if(ch[i]!=' ')
        {
            ch0[j]=ch[i];
            j++;
        }
        if(ch0[i]>='0'&&ch0[i]<='9') // @@ [Accessing ch0[i] before it's fully populated; also, 'i' may exceed ch0's valid index since j <= i]
            num++;
        
    }
    if(num==(strlen(ch0)-1)) // @@ [Logic is flawed: this condition checks if number of digits equals length-1, which doesn't relate to evaluating the expression]
    {
        for(int k=0;k<strlen(ch0)-1;k++)
            printf("%c",ch0[k]); // @@ [This just prints the expression without '=' instead of computing the result]
    }
    
    return 0;
}