#include<stdio.h>//读入方式值得一积累；
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
typedef struct ini{
    int cof;
    int exp;
}std1;
std1 a[100000];
std1 b[100000];
std1 sum[1000000];
int lena=0,lenb=0,len_sum=0;
int cmp(const void *p,const void *q){
    std1 c=*(std1 *)p;
    std1 d=*(std1 *)q;
    if(c.exp!=d.exp){
        return c.exp>d.exp?-1:1;
    }
}
void multip_add(int co,int ex){
    for(int i=1;i<=lena;++i){
        int n,m,op=0;
        n=co*a[i].cof;
        m=ex+a[i].exp;
        for(int j=i;j<=len_sum;++j){//逐项比较后加入进去
            if(sum[j].exp==m){
                sum[j].cof+=n;//加入
                if(sum[j].cof==0){//系数为0把指数也置零
                    sum[j].exp=0;
                }
                op=1;
            }
        }
        if(!op){//没找到相等的就放到最后
            len_sum++;
            sum[len_sum].exp=m;
            sum[len_sum].cof=n;
        }
    }
}

int main()
{
    char c;
    int ex,co;
    do{//第一个多项式读入
        scanf("%d%d%c",&co,&ex,&c);
        lena++;
        a[lena].cof=co,a[lena].exp=ex;
    }while(c!='\n');
    do{//第二个多项式读入
        scanf("%d%d%c",&co,&ex,&c);
        lenb++;
        b[lenb].cof=co,b[lenb].exp=ex;
    }while(c!='\n');
    for(int i=1;i<=lenb;++i){
        multip_add(b[i].cof,b[i].exp);
    }
    qsort(sum+1,len_sum,sizeof(sum[1]),cmp);
    for(int i=1;i<=len_sum;++i){
        if(sum[i].cof)
        printf("%d %d ",sum[i].cof,sum[i].exp);
    }
return 0;
}
int read(){
int x=0,f=1,c=getchar();
while(c<'0'||c>'9')(c=='-')?(f=-1):0,c=getchar();
while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
return x*f;
}
