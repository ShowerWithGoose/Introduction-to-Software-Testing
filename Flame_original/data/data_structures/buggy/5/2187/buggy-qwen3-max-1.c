#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
typedef struct result
{
  int xishu;
  int zhishu;    
} Result;
//声明多项式结构体类型 
Result a[5000],b[5000],c[5000];
//声明结构体变量，分别表示前一个多项式、后一个多项式与计算结果 
int cmp(const void*p1,const void*p2); 

int main()
{
    int flag1=0,flag2=0;
    char ch;
    do //读入第一个多项式 
    {
        scanf("%d%d%c",&a[flag1].xishu,&a[flag1].zhishu,&ch);
        flag1++;
    }while(ch!='\n');
    do //读入第二个多项式 
    {
        scanf("%d%d%c",&b[flag2].xishu,&b[flag2].zhishu,&ch);
        flag2++;
    }while(ch!='\n');
    qsort(a,flag1,sizeof(Result),cmp);
    qsort(b,flag2,sizeof(Result),cmp);
    int k=0;
    for(int i=0;i<flag1;i++)
    {
        for(int j=0;j<flag2;j++)
        {
            c[k].xishu=a[i].xishu*b[j].xishu;
            c[k].zhishu=a[i].zhishu+b[j].zhishu;
            k++;
        }
    }
    qsort(c,k,sizeof(Result),cmp);
    for(int i=0;i<=k;i++) // @@ [Loop runs from 0 to k (inclusive), but valid indices are 0 to k-1. Accessing c[k] and c[k+1] causes out-of-bounds read/write.]
    {
        if(c[i].zhishu==c[i+1].zhishu&&c[i].zhishu!=0) // @@ [When i == k, c[i+1] accesses c[k+1], which is beyond the allocated array size (undefined behavior). Also, condition `c[i].zhishu != 0` is incorrect—it should combine like terms regardless of exponent being zero.]
        {
            c[i].xishu+=c[i+1].xishu;
            c[i+1].xishu=0;
        }
    }
    for(int i=0;i<=k;i++) // @@ [Again, loop goes up to i = k, but c[k] is uninitialized (since terms are stored in c[0] to c[k-1]). This leads to reading garbage or undefined behavior.]
    {
        if(c[i].xishu!=0)
        printf("%d %d ",c[i].xishu,c[i].zhishu);
    }
    return 0;
}

int cmp(const void*p1,const void*p2)
{
    struct result* a=(struct result*)p1;
    struct result* b=(struct result*)p2;
    return (b->zhishu)-(a->zhishu);
}