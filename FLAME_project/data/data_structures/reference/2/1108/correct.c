#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
int main ()
{
    int a,b,c;
    char p,q,r;
    a=0,p='+';
    scanf("%d %c",&b,&q);
    while(1)
    {
        if(q=='+' || q=='-' )
        {
            if(p=='+')
                a=a+b;
            else if (p=='-')
                a=a-b;
            p=q;//加减法结果补充到a中，需要进行的计算符号存到p中
            scanf("%d %c",&b,&q);//顺序往后读入数字和符号重新进入循环进行判断
        }
        if(q=='*' || q=='/')
        {
            scanf("%d %c",&c,&r);//乘除法要再往后读入一位进行运算，而与前面的数据无关
            if(q=='*')
                b=b*c;
            else if(q=='/')
                b=b/c;
            q=r;
        }
        if(q=='=')
        {
           if(p=='+')
              a=a+b;
           else if (p=='-')
              a=a-b;
           printf("%d\n",a);
           break;
        }
    }
    return 0;
}

