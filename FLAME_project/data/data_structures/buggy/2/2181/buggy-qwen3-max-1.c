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
        while(y!='=') // @@ [This loop may never terminate because after reading the last number and the '=', the next scanf("%c",&y) reads beyond '=' or gets stuck if input ends, causing infinite loop or undefined behavior. Also, it fails to consume spaces before reading y inside the loop.]
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
            scanf("%c",&y); // @@ [This reads the next operator without skipping leading spaces, which may read a space as y, breaking the logic and possibly causing infinite loop when y becomes space and never equals '='.]
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