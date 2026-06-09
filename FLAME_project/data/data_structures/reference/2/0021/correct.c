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
int calculate(int x,char b,int y)//此函数是为了计算式子
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
    int one,two,three;//one代表左边的数字，two代表中间的数字，three代表右边的数字
    char left,right;//left代表one和two之间的运算符，right代表two个three之间的运算符
    one=readinnumber();//读入最左边的数字
    left=readinch();//读入第一个运算符
    if(left=='=')
        printf("%d",one);//如果表达式为一个数直接跟‘=’
    else
    {
        two=readinnumber();//读入中间的数字
        right=readinch();//读入右边的运算符
        if(right=='=')
            printf("%d",calculate(one , left,right));//计算输出结果
        else
        {
            while(right!='=')//停止条件读入‘=’
            {
                three=readinnumber();//读入右边的数字
                if(check(left,right)==0)//判断字符优先级
                {//说明left的优先级更大
                    one=calculate(one,left,two);//将one更新
                    two=three;//将two更新
                    left=right;//将left更新
                }
                else
                {//说明right优先级更大
                    two=calculate(two,right,three);//更新two
 
                }
                right=readinch();//读入下一个运算符
            }
            printf("%d",calculate(one,left,two));//由于上述循环的结果为一个只包含两个数字和表达式，直接计算得到结果
        }
 
    }
    return 0;
}
 

