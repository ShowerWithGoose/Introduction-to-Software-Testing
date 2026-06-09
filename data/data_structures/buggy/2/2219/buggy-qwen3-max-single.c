#include <stdio.h>
#include <string.h>
int num=0;
int main ()
{
    char ch[10005];
    char ch0[1005];
    gets(ch); // @@ [Using gets() is unsafe and may cause buffer overflow; however, the primary issue is that the program logic does not implement arithmetic expression evaluation as required.]
    for(int i,j=0;i<strlen(ch);i++) // @@ [Variable 'i' is uninitialized, leading to undefined behavior. Also, the loop condition uses strlen(ch) repeatedly which is inefficient, but more critically, the logic fails to parse and evaluate the arithmetic expression correctly.]
    {
        if(ch[i]!=' ')
        {
            ch0[j]=ch[i];
            j++;
        }
        if(ch0[i]>='0'&&ch0[i]<='9') // @@ [Accessing ch0[i] before it's fully written (only indices < j are valid), and 'i' may exceed the actual length of ch0, causing out-of-bounds read. Also, this check is misplaced—it should be on ch[i], not ch0[i].]
            num++;
        
    }
    if(num==(strlen(ch0)-1)) // @@ [This condition assumes the number of digits equals total non-space characters minus one (for '='), which is incorrect logic for evaluating expressions. It doesn't handle operators or precedence.]
    {
        for(int k=0;k<strlen(ch0)-1;k++)
            printf("%c",ch0[k]); // @@ [This just prints the expression without evaluating it, violating the problem requirement to compute and output the result.]
    }
    
    return 0;
}