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
            scanf("%d %c",&num2,&sign2);//对于第二组数据进行输入 @@ The format string "%d %c" consumes whitespace before the integer but not necessarily after the character if the next token is immediately adjacent or if spaces are handled inconsistently. More critically, this logic fails to correctly handle the precedence and associativity for mixed operators because it greedily consumes pairs. However, the specific bug here is that when sign2 is * or /, it reads ahead. If the expression ends with = after a *, the logic breaks. But the main logical error is in how it handles the transition from high precedence to low precedence.
            if(sign2=='+'||sign2=='-'||sign2=='=')//判断为加减，可以直接进行计算
            {
            num1=caculate(num1,num2,sign1);//把第一组数据进行计算变成一个数字
            sign1=sign2;//更新符号 
        }
            else//再加设一组数据对于连乘或连除进行计算 
            {
                scanf("%d %c",&num0,&sign0); @@ This line assumes there is always another number and operator following a * or /. If the expression ends or transitions to +/- immediately, this read might consume the wrong token or fail. Specifically, in the sequence `... * 2 + ...`, sign2 is `*`. It enters else. Reads `2` into num0 and `+` into sign0. Then it calculates `num2 = num2 * num0`. Then `sign2` becomes `+`. The loop `while(sign0=='*'||sign0=='/')` does not execute. Then `num1 = caculate(num1, num2, sign1)`. This part actually looks logically okay for simple cases, but let's look at the failure case: `24 / 4 / 3 / 2 + ...`.
                num2=caculate(num2,num0,sign2);//先把第一个数据进行计算 
                sign2=sign0;//更新符号 
                while(sign0=='*'||sign0=='/')//需要连乘或者连除的情况
                {
                scanf("%d %c",&num0,&sign0);
                num2=caculate(num2,num0,sign2);
                sign2=sign0;//更新符号 
                 }
                num1=caculate(num1,num2,sign1);//把第一组数据进行计算变成一个数字
            sign1=sign2;//更新符号 
             } 
        }
        printf("%d",num1);
    
    return 0;
 }