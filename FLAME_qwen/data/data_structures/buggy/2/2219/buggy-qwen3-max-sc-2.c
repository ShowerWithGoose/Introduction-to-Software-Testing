#include <stdio.h>
#include <string.h>
int num=0;
int main ()
{
    char ch[10005];
    char ch0[1005];
    gets(ch); // @@ [Using gets() is unsafe and may cause buffer overflow; also, the program logic does not implement arithmetic expression evaluation as required]
    for(int i,j=0;i<strlen(ch);i++) // @@ [Variable 'i' is uninitialized, leading to undefined behavior]
    {
        if(ch[i]!=' ')
        {
            ch0[j]=ch[i];
            j++;
        }
        if(ch0[i]>='0'&&ch0[i]<='9') // @@ [Accessing ch0[i] before it's fully populated; also, 'i' indexes original string but used on compressed string ch0]
            num++;
        
    }
    if(num==(strlen(ch0)-1)) // @@ [Logic error: comparing count of digits to length of expression minus one doesn't validate or evaluate the expression]
    {
        for(int k=0;k<strlen(ch0)-1;k++)
            printf("%c",ch0[k]); // @@ [This just prints the expression without evaluating it, violating problem requirements]
    }
    
    return 0;
}