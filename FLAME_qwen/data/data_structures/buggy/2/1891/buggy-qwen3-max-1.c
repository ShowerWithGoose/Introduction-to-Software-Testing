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
            if(x=='+') a=a+b; // @@ [Used 'y' instead of 'x' to decide the operation for accumulating into 'a'; this causes incorrect accumulation when handling sequences like "5 - 1 * 2", because 'y' has already been updated to the next operator]
            else if(x=='-') a=a-b; // @@ [Same as above: should use 'x', which holds the previous additive operator, not 'y', which is the current operator being processed]
            
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