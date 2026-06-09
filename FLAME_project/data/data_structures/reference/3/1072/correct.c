#include <stdio.h> //不用我多说了
#include <math.h> //数学公式
#include <stdlib.h> //快排和malloc
#include <ctype.h> //字符处理函数
#include <string.h> //字符串函数
#include <time.h>//找时间
#define ll long long //纯粹是为了快~
#define eps 1e-6 //别被浮点数相等判断卡掉
#define MAX 1000005 //看好数据范围，多开5个空间
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define NumberOf(a) (sizeof(a)/sizeof(a[0]))
#define MAXN  10
#define MAXK  1e7
#define swap(x,y) {\
 typeof(x)temp=x;\
x=y;y=temp;\
}
clock_t start,stop;
char s[105];
int main()
{
    gets(s);
    int i=0,num;
    if(s[0]=='0')
    {
        i=2;
        while(s[i]=='0')
        {
            i++;
        }
        num=i-1;
        printf("%c",s[i]);
        i++;
        if (s[i]!='\0')
        printf(".");
        while (s[i]!='\0')
        {
            printf("%c",s[i]);
            i++;
        }
        printf("e-%d",num);
    }
    else{
        while(s[i]!='.')
            i++;
        num=i-1;
        i=0;
        printf("%c.",s[i]);
        i++;
        while (s[i]!='\0')
        {
            if(s[i]=='.')
                i++;
            else{
                printf("%c",s[i]);
                i++;
            }
        }
        printf("e%d",num);
    }

    return 0;
}




