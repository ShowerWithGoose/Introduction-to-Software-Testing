//找规律、模块化分析 
#include <stdio.h>//sum op1 x op2 y op3
int main()
{
    int sum,x,y;
    char op1,op2,op3;
    scanf("%d %c",&sum,&op1);
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
        sum-=x; // @@ The code does not handle the case where op1 is '*' or '/' before processing the next term. When op1 is '*' or '/', the current term x should be combined with sum using multiplication or division, but the code only handles '+' and '-', causing incorrect results for expressions starting with multiplication or division (though the problem guarantees valid expressions, the logic fails for chained operations like "24 / 4 / 3 / 2" where the first operator is '/' and subsequent operators are also '/').
        op1=op2;
    }
    printf("%d",sum);
    
    
    return 0;
}