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
clock_t p,stop;
int main()
{
    gets(s);
    int l,k;
    l= strlen(s);
    for ( k = 0; k < l; k++) {
        int p=0;
        if(s[k+1]!='-')
            printf("%c",s[k]);
        else{
            if(s[k]>=s[k+2])
                printf("%c",s[k]);
            else
            {
                if((s[k]-96)*(s[k+2]-96)<0)
                    printf("%c",s[k]);
                else{
                    if((s[k]-64)*(s[k+2]-64)<0)
                        printf("%c",s[k]);
                    else
                    {
                       p=s[k];
                        while (p<s[k+2])
                        {
                            printf("%c",p);
                            p++;
                        }
                        k++;
                    }
                }
            }
        }
    }

    return 0;
}



