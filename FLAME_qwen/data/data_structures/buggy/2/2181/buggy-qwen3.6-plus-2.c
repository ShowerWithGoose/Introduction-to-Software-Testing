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
    while(getchar()==' ') {}; // @@ getchar() consumes the first non-space character (the operator), causing it to be lost. Use scanf(" %c", &x) to skip whitespace automatically.
    scanf("%c",&x);
    if(x=='=')
    {
        printf("%d",a);
    }
    else
    {
        scanf("%d",&b);
        while(getchar()==' ') {}; // @@ Same issue: consumes the operator character instead of skipping spaces.
        scanf("%c",&y);
        while(y!='=')
        {
            scanf("%d",&c);
            while(getchar()==' ') {}; // @@ Same issue: consumes the next operator character, leading to incorrect parsing.
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
            scanf("%c",&y); // @@ Reads a space if present before the operator, causing logic errors. Use " %c" format to skip whitespace.
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
} // @@ Missing return statement for the default case, which may cause a compilation error or undefined behavior.