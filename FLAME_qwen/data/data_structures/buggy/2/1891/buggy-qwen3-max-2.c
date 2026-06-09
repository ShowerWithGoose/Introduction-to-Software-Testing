#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int main()
{
    int a,b,c;
    char x,y,z;
    a=0;
    x='+';
    scanf("%d %c",&b,&y);
    while(1)
    {
        if(y=='*'||y=='/')
        {
            scanf("%d %c",&c,&z);
            if(y=='*') b=b*c;
            else if(y=='/') b=b/c;
            
            y=z;
        }
        if(y=='+'||y=='-')
        {
            if(x=='+') a=a+b; // @@ [The program incorrectly uses 'y' instead of the stored previous operator 'x' to decide how to combine 'a' and 'b'. This causes incorrect accumulation when handling sequences like "5 - 1 * 2", because after processing multiplication, the current operator 'y' is '-' but it should use the pending operator 'x' which was set earlier.]
            else if(x=='-') a=a-b; // @@ [Same issue: should use 'x', not 'y'. The variable 'x' holds the last addition/subtraction operator that hasn't been applied yet, while 'y' is the current operator being processed (which could be '*' or '/'). Using 'y' here leads to wrong logic when coming from a multiplication/division block.]
            
            x=y;
            scanf("%d %c",&b,&y);
        }
        if(y=='=')
        {
            if(x=='+') a=a+b;
            else if(x=='-') a=a-b;
            
            printf("%d\n",a);
            break;
        }
    }
    return 0;
}