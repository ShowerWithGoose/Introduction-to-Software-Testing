#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
char f[10000];
int t1,t2;
char s[10000];
long long stack[10000];
int main()
{
    int i;
    long long m;
    scanf("%[^=]",&s);                        //读入 = 前的字符串
    int len = strlen(s);
    for(i = 0; i < len; i++)
    {
        m = 0;
        if(s[i] == ' ') continue;        	 //若是' ' 跳过
        if(s[i] >= '0' && s[i] <='9')		 // 读入数字
        {
            while(s[i] >= '0' && s[i] <='9') m = m*10 + s[i++] - '0';
            stack[++t1] = m;			//将当前读入的数字压如栈
            i--;                            //为什么要i--呢， 因为前面多加了一个
        }
        else
        {
            char b = s[i];				//读入操作符
            if( (f[t2] == '*'|| f[t2] == '/')&&t1>=2&&t2>=1)      //如果符号栈栈顶为乘除，先算乘除，此时要求数字栈有至少2个数
            {
                if(f[t2] == '*') m = stack[t1-1]*stack[t1];        //取出栈顶两个数字进行计算
                else m = stack[t1-1]/stack[t1];
                t1--;
                t2--;
                stack[t1] = m;   										  //把计算结果压入栈中
            }
            f[++t2] = b;												 //  把本次读入的操作符压入栈中
        }

    }
    if((f[t2] == '*' ||f[t2] == '/' )&&t1>=2 && t2>=1)           //如果最后一次压入符号栈中的数字是乘除
    {
        if(f[t2]== '*') m = stack[t1-1]*stack[t1];
        else m = stack[t1-1]/stack[t1];
        t1--;
        t2--;
        stack[t1] = m;
    }
    m = stack[1];														 //从第一个数开始
    for(i = 1; i< t1; i++)
    {
        if(f[i]== '+') m = m + stack[i+1];							//运算加减
        else m = m - stack[i+1];
    }
    printf("%lld",m);
    return 0;
}

