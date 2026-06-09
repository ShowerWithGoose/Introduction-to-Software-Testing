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
            if(y=='+') a=a+b; // @@ The condition should check x (the accumulated operator) instead of y (the current operator). For example, in "1+2*3", when processing '+', y is '+', but x should be '+' from the previous term. However, the logic here incorrectly uses y, which is correct in this case, but the real error is that the assignment x=y happens after the accumulation, so x is not updated before the next iteration. The correct logic should use x for accumulation, as in the reference program.
            else if(y=='-') a=a-b; // @@ Same issue as above: should use x instead of y.
            
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