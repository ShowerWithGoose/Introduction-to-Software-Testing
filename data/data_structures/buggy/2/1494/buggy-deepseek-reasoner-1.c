/*本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#define MAX 9223372036854775807LL
#define MIN -9223372036854775808LL
int main()
{
    char d='+',e,f;//规定初始值 d为加号 
    int a=0,b=0,c;
    while (1)//读入 
    {
        scanf("%d %c",&b,&e);//以数字空格符号为一组 
        while(e=='*'||e=='/')//如果符号为乘除 
        {
            scanf("%d %c",&c,&f);//再继续读入一组 
            if(e=='*')//如果第二组符号为乘法 
            {
            b=b*c;}
            else //如果第二组符号为除法 
            {
            b=b/c;}
            e=f;//恢复初始值 
        }
        if(d=='+')//如果遇到加号 
        a=a+b;
        else if(d=='-')//遇到减号 
        a=a-b;
        d=e;//初始值 
        if(d=='=')//遇到等号输出结果 
        printf("%d\n",a);@@ //缺少break，导致循环无法退出
    }
    return 0 ;
}