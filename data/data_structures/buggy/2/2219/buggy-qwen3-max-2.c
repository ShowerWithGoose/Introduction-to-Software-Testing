#include <stdio.h>
#include <string.h>
int num=0;
int main ()
{
    char ch[10005];
    char ch0[1005];
    gets(ch); // @@ [Using gets() is unsafe and may not be available in modern compilers, leading to compilation error; also, the logic does not implement arithmetic expression evaluation as required]
    for(int i,j=0;i<strlen(ch);i++) // @@ [Variable 'i' is uninitialized, leading to undefined behavior and potential compilation warning/error depending on compiler settings]
    {
        if(ch[i]!=' ')
        {
            ch0[j]=ch[i];
            j++;
        }
        if(ch0[i]>='0'&&ch0[i]<='9') // @@ [Accessing ch0[i] before it's fully initialized for all i; also, 'i' may exceed the written portion of ch0, causing undefined behavior]
            num++;
        
    }
    if(num==(strlen(ch0)-1)) // @@ [Logic is incorrect: this condition checks if number of digits equals length-1, which doesn't relate to evaluating the expression; also, ch0 is not null-terminated, so strlen(ch0) is undefined]
    {
        for(int k=0;k<strlen(ch0)-1;k++) // @@ [Again, ch0 is not null-terminated, so strlen(ch0) invokes undefined behavior; also, this just prints the expression without computing result]
            printf("%c",ch0[k]);
    }
    
    return 0;
}