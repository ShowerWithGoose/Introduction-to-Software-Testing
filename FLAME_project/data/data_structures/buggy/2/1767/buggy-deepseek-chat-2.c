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
        sum-=x; // @@ The code does not handle the case where op1 is '*' or '/' from a previous iteration. When op1 is '*' or '/', the current logic skips the operation and incorrectly treats it as '+' or '-', leading to wrong results. For example, in "24 / 4 / 3 / 2 + 100 ...", after processing the first division, op1 becomes '/', but the next iteration reads a new x and op2, and the code does not perform the pending division on sum before moving to the next term.
        op1=op2;
    }
    printf("%d",sum);
    
    
    return 0;
}