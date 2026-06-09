//找规律、模块化分析 
#include <stdio.h>//sum op1 x op2 y op3
int main()
{
    int sum,x,y;
    char op1,op2,op3;
    scanf("%d %c",&sum,&op1); // @@ The format string "%d %c" consumes optional whitespace before reading the character. If the input has spaces after the number, op1 might read a space instead of the operator, or if it reads the operator correctly, the subsequent logic fails to handle spaces between tokens robustly compared to the reference which explicitly skips spaces. However, the critical logical error is below.
    while(op1!='=')
    {
        scanf("%d %c",&x,&op2); // @@ Similar to above, using "%d %c" relies on scanf's whitespace skipping for the integer but the space in format string skips whitespace before char. This part is actually okay for standard inputs, but the loop condition logic is flawed.
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
        op1=op2; // @@ When the inner while loop finishes, op2 holds the next additive operator (+, -, or =). This line correctly updates op1 for the next iteration. However, if the expression starts with a number and immediately ends (e.g., "5 ="), the first scanf reads 5 and '='. The while loop condition op1!='=' fails, so it prints sum. This seems correct for simple cases. Let's look closer at the trace.
    }
    printf("%d",sum);
    
    
    return 0;
}