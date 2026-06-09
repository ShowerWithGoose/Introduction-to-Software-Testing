#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
typedef long long ll;
#define eps 1e-8
/*5-1*2*3+12/2/2=
* num1=5;op1=-;op1!==;
* num2=1;op2=*
* num3=2;op3=*
* num2=2;op2=op3=*
* num3=3;op3=+
* num2=6；op2=op3=+
* 不满足循环跳出，此时op1=-；num1=5
* num1=-1;op1=+;op1!==
* 输入num2=12;op2=/
* 重复连乘除num2=3;op2==
* 此时op1=+；num1=-1；
* num1=2；op1==
* 调出大循环
*/
//运算符赋值给上一个实现循环
int main()//将一个数字和后面的运算符看为一个整体
{
    int num1=0, num2,num3;//数字num1记录加减。num2记录乘除，
    char op1='+', op2,op3;//运算符
   // scanf("%d %c", &num1, &op1);//先输入第一个整体
    while (op1 != '=') 
    {//判断是否为运算式。不是的话直接输出num1
        scanf(" %d %c", &num2, &op2);
        //先算乘除
        while (op2 == '*' || op2 == '/')
        {
            scanf(" %d %c", &num3, &op3);
            if (op2 == '*') {
                
                num2*= num3;
            }
            if (op2 == '/') {
            
                num2 /= num3;
            }
            op2 = op3;//实现连续乘除
        }
        //连续乘除算完，往前找加减
        if (op1 == '+') {
            num1 += num2;
        }
        if (op1 == '-') {
            num1 -= num2;
        }
        op1 = op2;//用于判断何时读取到等号 
    }
    printf("%d", num1);
    return 0;
}




