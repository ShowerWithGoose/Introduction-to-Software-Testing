//找规律、模块化分析 
#include <stdio.h>//sum op1 x op2 y op3
int main()
{
    int sum,x,y;
    char op1,op2,op3;
    scanf("%d %c",&sum,&op1); // @@ [This skips spaces but may consume the '=' if input starts with "number =", and doesn't handle leading spaces before operator correctly per problem spec]
    while(op1!='=')
    {
        scanf("%d %c",&x,&op2); // @@ [Using "%d %c" skips whitespace before reading the next number, but then reads the next non-whitespace char as op2; however, it fails to handle cases where after reading x, the next char is '=' because the format string expects a char after %d even when expression ends]
        while(op2=='*'||op2=='/')
        {
            scanf("%d %c",&y,&op3); // @@ [Same issue: assumes there's always a character after %d, but if expression ends right after y (e.g., ... * y =), this will read beyond or misread '=']
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
        op1=op2;
    }
    printf("%d",sum);
    
    
    return 0;
}