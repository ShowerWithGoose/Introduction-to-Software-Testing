#include<stdio.h>
#include<math.h> 
#include<string.h>
#include<stdlib.h>

int f(int a, char x, int b); 

int a, b, c;
char x, y;
int n, i, j;

int main()
{
    scanf("%d",&a);
    while(getchar()==' ') {}; // @@ Consumes the next non-space character (e.g., operator) if no space is present, causing incorrect parsing.
    scanf("%c",&x);
    if(x=='=')
    {
        printf("%d",a);
    }
    else
    {
        scanf("%d",&b);
        while(getchar()==' ') {}; // @@ Same issue: consumes the operator character if there are no spaces before it.
        scanf("%c",&y);
        while(y!='=')
        {
            scanf("%d",&c);
            while(getchar()==' ') {}; // @@ Same issue: consumes the next operator if no space exists.
            if((x=='+'||x=='-')&&(y=='*'||y=='/'))
            {
                b=f(b, y, c);
            }
            else
            {
            a=f(a, x, b);
            b=c;
            x=y;    
            }
            scanf("%c",&y); // @@ Reads the next character without skipping whitespace, so it may read a space instead of the operator.
        }
        printf("%d",f(a, x, b));
    }


return 0;    
}

int f(int a, char x, int b)
{
    if(x=='+')
    {
        return (a+b);
    }
    if(x=='-')
    {
        return (a-b);
    }
    if(x=='*')
    {
        return (a*b);
    }
    if(x=='/')
    {
        return (a/b);
    }
} // @@ Missing return statement for non-void function when x is not '+', '-', '*', or '/', causing a compilation error.