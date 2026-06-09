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
        while(op2=='*'||op2=='/') // @@ 缺少对 op1 为乘除符的处理，导致第一个操作符为乘/除时 sum 未参与运算
        {
            scanf("%d %c",&y,&op3);
            if(op2=='*')
            x=x*y;
            else if(op2=='/')
            x=x/y;
            op2=op3;
        }
        if(op1=='+') // @@ 缺少对 op1 为乘除的分支，导致第一次除法结果被忽略
        sum+=x;
        else if(op1=='-') // @@ 同上，缺少乘除分支处理
        sum-=x;
        op1=op2;
    }
    printf("%d",sum);
    
    
    return 0;
}