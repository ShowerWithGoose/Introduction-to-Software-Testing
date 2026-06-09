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
            scanf("%c",&y); // @@ The loop condition checks 'y', but 'y' is only updated at the end of the loop body. If the input ends with '=', the previous scanf for operator reads '='. However, the logic fails to consume spaces before reading the next operator 'y' inside the loop, or more critically, the `while(getchar()==' ')` loops can cause infinite loops or skip necessary characters if not handled correctly relative to the newline or EOF. But the primary issue causing TLE or incorrect logic here is often related to how `getchar()` interacts with the buffer. Specifically, after `scanf("%d", &c)`, the buffer contains spaces/newline. The `while(getchar()==' ')` consumes spaces. Then `scanf("%c", &y)` reads the next non-space char. If that char is '=', the loop terminates. If not, it continues. The TLE usually suggests an infinite loop. Let's look closer. `while(getchar()==' ') {}` will hang if it encounters a newline or other non-space character that isn't consumed? No, `getchar()` returns the char. If it's not space, the loop stops. But it *consumes* that non-space character. So if the input is `10 + 20 * 30 - 40 / 5 =`, after reading `5`, the buffer has ` =\n`. `getchar()` gets ` ` (space), loop continues. `getchar()` gets `=`, loop stops. But `=` is now consumed! Then `scanf("%c", &y)` reads the next character, which might be `\n` or garbage, leading to unexpected behavior or infinite loop if `y` never becomes `=`. The error is that `while(getchar()==' ')` consumes the first non-space character, which is likely the operator or `=`, so the subsequent `scanf("%c", &y)` reads the character *after* the operator.
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