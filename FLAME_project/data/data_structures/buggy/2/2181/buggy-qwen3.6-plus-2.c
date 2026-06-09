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
            scanf("%c",&y); // @@ The loop condition checks 'y', but if 'y' is not '=', the loop continues. However, after reading 'y', if it is '=', the loop terminates correctly. The issue causing TLE is likely an infinite loop if input format is slightly unexpected or logic error in consumption. But looking closely at the logic: if `y` becomes `=`, the loop `while(y!='=')` stops. The previous code structure was flawed. Let's re-evaluate the TLE cause.
            // Actually, the primary issue in many such student submissions with `getchar()` loops is that if the input ends or format differs, `getchar()` might block or loop infinitely if EOF isn't handled or if spaces aren't consumed correctly before the next token.
            // However, there is a more subtle logical error. If `y` is read as `=`, the loop terminates.
            // Let's look at the `while(getchar()==' ') {};` lines. If the character is not a space, it is consumed and discarded. This is correct for skipping spaces.
            // Wait, if `scanf("%c", &y)` reads a non-space character, it proceeds.
            // The TLE usually implies an infinite loop.
            // Consider the case: `10 + 20 =`.
            // 1. `a=10`. Skip spaces. `x='+'`.
            // 2. `b=20`. Skip spaces. `y='='`.
            // 3. `while(y!='=')` -> False. Loop doesn't enter.
            // 4. Print `f(10, '+', 20)` -> 30. Correct.
            
            // Consider: `10 + 20 * 30 =`
            // 1. `a=10`. `x='+'`.
            // 2. `b=20`. `y='*'`.
            // 3. Loop `y!='='` is True.
            // 4. `scanf("%d", &c)` -> `c=30`.
            // 5. Skip spaces.
            // 6. `x='+'`, `y='*'`. Condition `(x=='+'||x=='-')&&(y=='*'||y=='/')` is True.
            // 7. `b = f(20, '*', 30)` -> `b=600`.
            // 8. `scanf("%c", &y)`. Reads `=`.
            // 9. Loop check `y!='='` is False. Terminate.
            // 10. Print `f(10, '+', 600)` -> 610. Correct.

            // Why TLE?
            // The `while(getchar()==' ') {};` construct consumes one non-space character if the first char isn't a space? No.
            // `getchar()` returns a char. If it is ' ', loop continues. If it is NOT ' ', loop terminates, BUT that non-space character is consumed and lost.
            // Example: `10 + 20`.
            // After `scanf("%d", &b)`, buffer has ` \n` or ` =`.
            // `while(getchar()==' ') {};` skips spaces. If next char is `=`, it is consumed by `getchar()` and discarded.
            // Then `scanf("%c", &y)` reads the NEXT character after `=`.
            // This means the operator/terminator `=` is skipped/eaten by the space-skipping loop!
            // So `y` will read whatever is after `=`, or wait for more input if `=` was the last thing.
            // If `=` is eaten, `y` never becomes `=`, leading to infinite loop (TLE) or wrong parsing.
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