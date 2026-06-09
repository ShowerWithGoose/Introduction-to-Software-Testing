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
        if(op1=='+') // @@ [Missing handling for op1 being '*' or '/'. Should also include else if for '*' and '/' to apply the operation to sum. Otherwise initial multiplication or division are ignored.]
        sum+=x;
        else if(op1=='-')
        sum-=x;
        op1=op2;
    }
    printf("%d",sum);
    return 0;
}