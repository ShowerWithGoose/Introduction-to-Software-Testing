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
typedef struct dian{
    int h;
    int z;
}point ;
typedef struct duan{
    point begin;
    point end;
}line;
/*int num(point[],int n)
{
    int num=0;
    for()

}*/
int main()
{
    int n;
    scanf("%d",&n);
    int i;
    line p[200];
    for (i = 0; i < n; i++) {
          scanf("%d%d%d%d",&(p[i].begin.h),&(p[i].begin.z),&p[i].end.h,&p[i].end.z);
    }
    int flag=1,j;
    int num,max;
    struct dian temp,ans;
    max=-1;
    for(i=0;i<n;i++){
        flag=1;
        temp=p[i].end;
        num=0;
        while(flag)
        {
            flag=0;
            for(j=0;j<n;j++)
            {
                if (temp.h==p[j].begin.h&&temp.z==p[j].begin.z) {
                    temp = p[j].end;
                    num++;
                    flag = 1;
                    break;
                }
            }
        }
        if (max<num) {
            max = num;
            ans=p[i].begin;
        }
    }
    printf("%d %d %d",max+1,ans.h,ans.z);
    return 0;
}


