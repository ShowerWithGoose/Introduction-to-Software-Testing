#include<stdio.h>
#include<string.h>

int main()
{
    int num1,num2;
    char op1,op2;
    int out=0;
    scanf("%d %c",&num1,&op1);
    out+=num1;
    while(op1!='=')
    {
        if(op1=='+'||op1=='-')
        {
            scanf("%d %c",&num1,&op2);
            if(op2=='*'||op2=='/')
            {
                while(1)
                {
                    scanf("%d",&num2);
                    if(op2=='*')
                    {
                        num1*=num2;
                    }
                    else 
                    {
                        num1/=num2;
                    }
                    scanf("%c",&op2);
                    if(op2==' ')
                    {
                        scanf("%c",&op2);
                    }
                    if(op2==' ')
                    {
                        scanf("%c",&op2);
                    }
                    if(op2=='+'||op2=='-'||op2=='=')
                    {
                        break;
                    }
                }
                if(op1=='+')
                {
                    out+=num1;
                }
                else if(op1=='-')
                {
                    out-=num1;
                }
                op1=op2;
            }
            else
            {
                if(op1=='+')
                {
                    out+=num1;
                }
                else if(op1=='-')
                {
                    out-=num1;
                }
                op1=op2;
            }
        }
        else 
        {
            while(1)
            {
                scanf("%d %c",&num1,&op2);
                if(op1=='*')
                {
                    out*=num1;
                }
                else
                {
                    out/=num1;
                }
                op1=op2;
                if(op1=='+'||op1=='-'||op1=='=')
                {
                    break;
                }
            }
        }
    }
    printf("%d",out);
    return 0;
}



