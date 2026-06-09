//找规律、模块化分析 
#include <stdio.h>//sum op1 x op2 y op3
int main()
{
    int sum,x,y;
    char op1,op2,op3;
    scanf("%d %c",&sum,&op1); // @@ [This line reads the first operator (op1) directly. If it is '*' or '/', the subsequent handling only checks '+' and '-' for op1, leading to incorrect results. The reference program avoids this by initializing sum=0 and op1='+', and reading the first number and operator inside the loop.]
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