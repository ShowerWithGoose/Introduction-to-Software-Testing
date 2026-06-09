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
            scanf("%d",&c); @@ // The program reads a new operand 'c' unconditionally at the start of the loop, but if the previous operator 'y' is '=' (which it isn't due to loop condition), or more critically, if there are no more numbers after the last operator before '=', this will attempt to read beyond the input. However, the real issue is that when the expression ends with '=', there is no number after the last operator, so reading 'c' here assumes there's always another number, which fails on valid inputs like "1 + 2 =". This causes undefined behavior or incorrect parsing.
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
            scanf("%c",&y);
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
} @@ // Function 'f' does not have a return statement for unexpected operators. Though the problem states the expression is valid and only contains +, -, *, /, the compiler may still warn or error in strict modes. However, the primary error is logical in main(), not here. But more critically, the compilation error mentioned ("gcc: not found") is environmental, yet the actual code has a logical flaw causing runtime misbehavior. Since the problem says "Compilation Error" but the given output is a shell error, we focus on code flaws that could cause compile issues. However, this code actually compiles. Given the discrepancy, the real issue is likely the unconditional read of 'c' leading to invalid input consumption, which is a logical/runtime error. But per instructions, we mark where the logic breaks parsing.