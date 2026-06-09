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
    while(getchar()==' ') {};
    scanf("%c",&x);
    if(x=='=')
    {
        printf("%d",a);
    }
    else
    {
        scanf("%d",&b);
        while(getchar()==' ') {};
        scanf("%c",&y);
        while(y!='=')
        {
            scanf("%d",&c);
            while(getchar()==' ') {};
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
            scanf("%c",&y); // @@ This line incorrectly reads the operator after processing a term. In the case where y is '*' or '/' and the condition (x=='+'||x=='-')&&(y=='*'||y=='/') is true, the code updates b but does not update x or y properly for the next iteration. Specifically, after the if block, it reads the next operator into y, but x still holds the old operator (e.g., '+' or '-'), and the next number c is read before the operator, causing misalignment. The logic fails to handle operator precedence correctly when multiple '*' or '/' follow a '+' or '-'.
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
}