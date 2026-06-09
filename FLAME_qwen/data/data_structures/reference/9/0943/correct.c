#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define N 1005
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))
//scanf记得变量要加&，循环变量记得初始化，break语句写在最后，读清题意，看看变量开int还是longlong
//switchcase记得加break,while循环看看会不会死循环，函数看看是不是一定能返回值。
int read();
int len[105];
int max_len = 0;
struct in
{
    int x[3];
    int y[3];
} a[1000];
int cmp(const void *p,const void *q){
    struct in c=*(struct in *)p;
    struct in d=*(struct in *)q;
    if(c.x[1]!=d.x[1]){
        return c.x[1]>d.x[1]?1:-1;
    } else return c.x[2]>d.x[2]?1:-1;
    }
int equal(int n, int m, int a, int b)
{
    if (n == m && a == b)
    {
        return 1;
    }
    else
        return 0;
}
int main()
{
     int n = read();
    for (int i = 1; i <= n; ++i)
    {
        a[i].x[1] = read();
        a[i].y[1] = read();
        a[i].x[2] = read();
        a[i].y[2] = read();
    }
    qsort(a+1,n,sizeof(a[1]),cmp);
    int op,k;
    for(int i=1;i<=n;++i){
        len[i]=1;
        k=i;
        for(int j=i+1;j<=n;++j){
            if(equal(a[k].x[2], a[j].x[1], a[k].y[2], a[j].y[1])){
                k=j;
                len[i]++;
            }
        }
        if (len[i] > max_len)
        {
            op=i;
            max_len =  len[i];
        }
    }
    printf("%d %d %d",max_len,a[op].x[1],a[op].y[1]);
    return 0;
return 0;
}
int read(){
int x=0,f=1,c=getchar();
while(c<'0'||c>'9')(c=='-')?(f=-1):0,c=getchar();
while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
return x*f;
}
