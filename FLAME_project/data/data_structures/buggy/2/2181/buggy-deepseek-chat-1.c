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
            scanf("%c",&y); // @@ This line may cause an infinite loop if the input contains spaces before '=', because the space is consumed by getchar() in the while loop, but then scanf("%c",&y) reads the next character which could be a space, and the loop continues without processing the '='. The original program uses a do-while loop to skip spaces before reading the operator, but here the space-skipping is done before reading the number, not before reading the operator, leading to potential infinite loop when spaces appear before '='.
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