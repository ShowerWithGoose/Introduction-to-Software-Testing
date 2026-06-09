//找规律、模块化分析 
#include <stdio.h>//sum op1 x op2 y op3
int main()
{
    int sum,x,y;
    char op1,op2,op3;
    scanf("%d %c",&sum,&op1); // @@ [This skips spaces but may consume the '=' if it immediately follows a number without space, and more critically, it doesn't handle leading spaces before the first operator correctly in all cases. However, the main issue is deeper.]
    while(op1!='=')
    {
        scanf("%d %c",&x,&op2); // @@ [Using "%d %c" skips whitespace before reading the char, which consumes the '=' if it comes right after a number (e.g., "...40=" becomes op2='='). But the critical flaw is that this approach fails to handle operator precedence correctly when the first operator is * or /.]
        while(op2=='*'||op2=='/')
        {
            scanf("%d %c",&y,&op3);
            if(op2=='*')
            x=x*y;
            else if(op2=='/')
            x=x/y;
            op2=op3;
        }
        if(op1=='+')
        sum+=x;
        else if(op1=='-')
        sum-=x;
        else if(op1=='*') // @@ [Missing handling for when the first operator (op1) is '*' or '/'. The program assumes op1 is only '+' or '-', but the initial op1 could be '*' or '/', e.g., in "24 / 4 ...", op1 is '/', yet the code never applies it to 'sum'.]
        sum=sum*x;
        else if(op1=='/') // @@ [Same as above: missing logic to apply initial multiplication/division to 'sum'. This causes the first operation (like 24 / 4) to be ignored as an operation on 'sum', and instead treated as if sum=24 and then later adding/subtracting the result of the rest, which is wrong.]
        sum=sum/x;
        op1=op2;
    }
    printf("%d",sum);
    
    
    return 0;
}