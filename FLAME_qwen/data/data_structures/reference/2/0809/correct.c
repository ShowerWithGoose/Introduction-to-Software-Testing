#include<stdio.h>
#include<string.h>
int calculator(char ,int ,int );
int main()
{
    int a,b,c;
    char op1,op2;
    scanf(" %d",&a);
    scanf(" %c",&op1);
    if(op1!='=')
    {
        scanf(" %d",&b);
    }
    while(op1!='=')
    {
        if(op1=='*'||op1=='/')
        {
            a=calculator(op1,a,b);
            scanf(" %c",&op1);
            if(op1!='=')
            {
                scanf(" %d",&b);
            }
        }
        else
        {
            scanf(" %c",&op2);
            if(op2=='+'||op2=='-'||op2=='=')
            {
                a=calculator(op1,a,b);
                op1=op2;
                if(op2!='=')
                {
                    scanf(" %d",&b);
                }
            }
            else if(op2!='=')
            {
                scanf(" %d",&c);
                b=calculator(op2,b,c);
            }
            else
            {
                op1=op2;
            }
        }
    }
    printf(" %d",a);
    return 0;
}
int calculator(char op,int a,int b)
{
    if(op=='+')
    {
        return a+b;
    }
    else if (op=='-')
    {
        return a-b;
    }
    else if (op=='*')
    {
        return a*b;
    }
    else if (op=='/')
    {
        return a/b;
    }
}


