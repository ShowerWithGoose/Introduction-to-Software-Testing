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
char s[100000]={0};
clock_t start,stop;
int main()
{
    gets(s);
    int n,i;
    n= strlen(s);
    for ( i = 0; i < n; i++) {
        int start=0;
        if(s[i+1]!='-')
            printf("%c",s[i]);
        else{
            if(s[i]>=s[i+2])
                printf("%c",s[i]);
            else
            {
                if((s[i]-96)*(s[i+2]-96)<0)
                    printf("%c",s[i]);
                else{
                    if((s[i]-64)*(s[i+2]-64)<0)
                        printf("%c",s[i]);
                    else
                    {
                       start=s[i];
                        while (start<s[i+2])
                        {
                            printf("%c",start);
                            start++;
                        }
                        i++;
                    }
                }
            }
        }
    }

    return 0;
}



