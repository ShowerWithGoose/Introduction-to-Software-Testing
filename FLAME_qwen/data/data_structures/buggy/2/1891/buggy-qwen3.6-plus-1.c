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
            if(y=='+') a=a+b; // @@ Should use 'x' (the previous operator) instead of 'y' to correctly apply the pending addition or subtraction to the accumulator 'a'
            else if(y=='-') a=a-b; // @@ Should use 'x' instead of 'y' for the same reason

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