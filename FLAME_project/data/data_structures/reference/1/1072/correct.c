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
int a[105];
int b[105];
int main()
{
    int N;
    scanf("%d",&N);
    int i;
    for ( (i) = 0; (i) < N; i++) {
        a[i]=i+1;
    }
    int n=1;
    for(i=1;i<=N;i++)
    {
        n*=i;
    }
    int temp,j,k,store,i0;
    for(i=0;i<n;i++)
    {
    	for(temp=0;temp<N;temp++) 
    		b[temp]=0;
        for(temp=0;temp<N;temp++)
        {
            printf("%d ",a[temp]);

        }
        printf("\n");
        for(j=N-1;a[j]>=a[j+1];j--){}
        store=a[j];
        int min=11;
        for(k=j+1;k<N;k++)
        {
            if(a[k]>a[j]&&a[k]<min) {
                store = a[k];
                i0 = k;
            }
        }
        a[i0]=a[j];
        a[j]=store;
        for(temp=j+1;temp<N;temp++)
            b[temp]=a[temp];
        for(temp=j+1;temp<N;temp++)
            a[temp]=b[N+j-temp];

    }
    return 0;
}

