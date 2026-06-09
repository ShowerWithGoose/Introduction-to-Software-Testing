#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#define MAX 9223372036854775807LL
#define MIN -9223372036854775808LL
int main()
{
    char d='+',e,f;  // @@ e and f are uninitialized, may cause undefined behavior and potential infinite loops
    int a=0,b=0,c;
    while (1)//读入 
    {
        scanf("%d %c",&b,&e);  // @@ no check on scanf return value; if input ends, program may loop indefinitely
        while(e=='*'||e=='/')//如果符号为乘除 
        {
            scanf("%d %c",&c,&f);  // @@ no check on scanf return value
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
        printf("%d\n",a);  // @@ missing break after printing; program enters infinite loop, causing Time Limit Exceeded
    }
    return 0 ;
}