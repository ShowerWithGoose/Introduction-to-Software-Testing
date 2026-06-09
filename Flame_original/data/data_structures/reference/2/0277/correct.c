#include <stdio.h>
int readinnumber()
{
    int a;//a是输入的数字
    scanf("%d",&a);
    return a;
}
char readinch()
{
    char b;//b为输入的运算符
    do
    {
        scanf("%c",&b);
    }while(b==' ');
    return b;
}
int check(char b1,char b2)//此函数是为了判断运算的优先级
{
    if(b1=='*'||b1=='/')
            return 0;
    else
        if(b2=='*'||b2=='/')
            return 1;
        else
            return 0;
}
int calculate(int x,char b,int y)
{
    if(b=='*')
        return x*y;
    if(b=='/')
        return x/y;
    if(b=='+')
        return x+y;
    if(b=='-')
        return x-y;
}
int main()
{
    int one,two,three;
    char left,right;
    one=readinnumber();//读入最左边的数字
    left=readinch();//读入第一个运算符
    if(left=='=')
        printf("%d",one);//如果表达式为一个数直接跟‘=’
    else
    {
        two=readinnumber();//读入中间的数字
        right=readinch();
        if(right=='=')
            printf("%d",calculate(one , left,right));//计算输出结果
        else
        {
            while(right!='=')//停止条件读入‘=’
            {
                three=readinnumber();//读入右边的数字
                if(check(left,right)==0)
                {
                    one=calculate(one,left,two);
                    two=three;
                    left=right;
                }
                else
                {
                    two=calculate(two,right,three);
 
                }
                right=readinch();
            }
            printf("%d",calculate(one,left,two));
        }
 
    }
    return 0;
}
 



