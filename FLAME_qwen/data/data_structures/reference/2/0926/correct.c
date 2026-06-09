#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
//变量循环的初始化很关键，scanf的&

int main()
{
    int a1,a2,a3;
    char op1,op2,op3;
 
    //为了保证结构，在最开始加上一个0+
    a1 = 0;
    op1 = '+';
    while(op1!='=')
    {
        scanf("%d %c",&a2,&op2);    //这里用一个空格来忽略空白符
        //计算乘除
        while(op2=='*' || op2=='/')
        {
            scanf("%d %c",&a3,&op3);
            if(op2=='*')
                a2 *= a3;
            else if(op2=='/')
                a2 /= a3;
            op2 = op3;    //此处注意
        }
        //将两项相加（减）
        if(op1=='+')
            a1 += a2;
        else if(op1=='-')
            a1 -= a2;
        op1 = op2;    //此处注意
    }
 
    printf("%d",a1);
 
 return 0;
}


