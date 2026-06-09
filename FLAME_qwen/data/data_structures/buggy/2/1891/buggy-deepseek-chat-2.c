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
            if(y=='+') a=a+b; // @@ The condition should check x (the accumulated operator) instead of y (the current operator). For example, in "5 - 1 * 2", when processing the '+' after multiplication, y is '+' but the correct operation is subtraction (x is '-'), so this incorrectly adds b instead of subtracting.
            else if(y=='-') a=a-b; // @@ Same issue: should check x instead of y.
            
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