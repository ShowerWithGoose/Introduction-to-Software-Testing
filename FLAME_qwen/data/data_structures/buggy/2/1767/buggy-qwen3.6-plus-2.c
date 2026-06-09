//找规律、模块化分析 
#include <stdio.h>//sum op1 x op2 y op3
int main()
{
    int sum,x,y;
    char op1,op2,op3;
    scanf("%d %c",&sum,&op1); // @@ Reads the first number and operator before the loop, which breaks the logic because op1 might be '*' or '/', but the subsequent if-else only handles '+' and '-'. It should initialize sum=0 and op1='+' instead.
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