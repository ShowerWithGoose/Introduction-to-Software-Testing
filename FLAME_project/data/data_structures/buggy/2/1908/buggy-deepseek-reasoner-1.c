#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#define ll long long
#define eps 0.000001
#define MAX( x, y ) ( ((x) > (y)) ? (x) : (y) )
#define MIN( x, y ) ( ((x) < (y)) ? (x) : (y) )
#define Max 10005
int caculate(int num1,int num2,char sign)
{
    switch (sign)
    {
        case '+':
        return num1+num2;
        case '-':
        return num1-num2;
        case '*':
        return num1*num2;
        case '/':
            if(num2==0)
            return num1;
        return num1/num2;
    }
    
}
int main()
{
    int num1=0,num2=0,num0=0;
    char sign1,sign2,sign0;
    //进行主题部分的输入 
        scanf("%d %c",&num1,&sign1);//每次仅读入一个数字和一个符号 
        while(sign1!='=')//如果需要进行计算 
        {
            scanf("%d %c",&num2,&sign2);//对于第二组数据进行输入
            if(sign2=='+'||sign2=='-'||sign2=='=')//判断为加减，可以直接进行计算
            {
            num1=caculate(num1,num2,sign1);//把第一组数据进行计算变成一个数字
            sign1=sign2;//更新符号 
        }
            else//再加设一组数据对于连乘或连除进行计算 
            {
                scanf("%d %c",&num0,&sign0);
                num2=caculate(num2,num0,sign2); // @@ 应先计算 num1 和 num2（使用 sign1）以保持左结合，而不是计算 num2 和 num0
                sign2=sign0;//更新符号 
                while(sign0=='*'||sign0=='/')//需要连乘或者连除的情况
                {
                scanf("%d %c",&num0,&sign0);
                num2=caculate(num2,num0,sign2); // @@ 同样应直接对 num1 进行累乘除运算，而不是对 num2
                sign2=sign0;//更新符号 
                 }
                num1=caculate(num1,num2,sign1); // @@ 最后再用 num1 与 num2 运算会导致运算顺序错误，应逐步将乘除结果累积到 num1
            sign1=sign2;//更新符号 
             } 
        }
        printf("%d",num1);
    
    return 0;
 }