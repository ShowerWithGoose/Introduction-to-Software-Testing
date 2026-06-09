//找规律、模块化分析 
#include <stdio.h>//sum op1 x op2 y op3
int main()
{
    int sum,x,y;
    char op1,op2,op3;
    scanf("%d %c",&sum,&op1); // @@ [The initial operator op1 is read from input, but the algorithm assumes that the expression starts with a term and then an operator. However, if the expression starts with a negative number (e.g., "-5 + 3 ="), this initialization fails because it tries to read "-5" as the first integer and '+' as op1, which breaks the logic. More critically, unlike the reference program which initializes with "0+", this code does not handle the first term correctly when the first operator is '-' or when the expression begins directly with a number without a leading operator. This leads to incorrect parsing of the first operation.]
    while(op1!='=')
    {
        scanf("%d %c",&x,&op2);
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
        op1=op2;
    }
    printf("%d",sum);
    
    
    return 0;
}